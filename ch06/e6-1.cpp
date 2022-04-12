//
// Created by hliangzhao on 2022/4/12.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>

using namespace std;

// TODO: 使用双端队列deque

const int maxn = 1000;

// 程序个数、五种指令的单位运行时间、运行时间配额
int n, c[5], quota;
// 存放变量的数值（题目说了每个变量的名字是一个小写字母）
int var[26];
// ip[pid]是程序pid的当前执行位置（行号）。所有程序都存在prog数组，更类似真实的情况，代码也更短
int ip[maxn];
char prog[maxn][10];
// 下面这两个队列充分模拟了有锁的程序的运行逻辑。显然，队列中只需要存放程序的编号即可。
deque<int> readyQ;
queue<int> blockQ;

// 全局锁
bool locked;

// 这个函数的抽象恰到好处！
void run(int pid) {
    int q = quota;
    while (q > 0) {
        char *p = prog[ip[pid]];
        // 用每一行的第三个字符来区分该语句的类型
        switch (p[2]) {
            case '=':
                var[p[0] - 'a'] = isdigit(p[5]) ? (p[4] - '0') * 10 + p[5] - '0' : p[4] - '0';
                q -= c[0];
                break;
            case 'i':   // print
                printf("%d: %d\n", pid + 1, var[p[6] - 'a']);
                q -= c[1];
                break;
            case 'c':   // lock
                if (locked) {
                    blockQ.push(pid);
                    return;
                }
                locked = true;
                q -= c[2];
                break;
            case 'l':   // unlock
                // 这里能直接设定为unlocked，是因为上锁行为不会嵌套
                locked = false;
                if (!blockQ.empty()) {
                    //  阻止队列中的第一个程序进入等待队列的首部
                    int pid2 = blockQ.front();
                    blockQ.pop();
                    readyQ.push_front(pid2);
                }
                q -= c[3];
                break;
            case 'd':
                return;
        }
        // 执行下一行
        ip[pid]++;
    }
    // 能执行到这里，意味着程序还没结束，因此放到等待队列尾
    readyQ.push_back(pid);
}

int main() {
    freopen("../ch06/e6-1-data.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d %d %d\n", &n, &c[0], &c[1], &c[2], &c[3], &c[4], &quota);
        memset(var, 0, sizeof(var));

        int line = 0;
        for (int i = 0; i < n; i++) {
            // 读取一个程序到prog中
            fgets(prog[line++], maxn, stdin);
            // 因为所有程序不加以区分地都被读入prog数组中，因此，用ip[i]存储第i个程序在prog中的起始行号
            ip[i] = line - 1;
            while (prog[line - 1][2] != 'd') {
                fgets(prog[line++], maxn, stdin);
            }
            readyQ.push_back(i);
        }

        locked = false;
        while (!readyQ.empty()) {
            int pid = readyQ.front();
            readyQ.pop_front();
            run(pid);
        }
        if (T) cout << endl;
    }
    return 0;
}
