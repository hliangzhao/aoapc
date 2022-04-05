//
// Created by hliangzhao on 2022/4/5.
//

#include <iostream>
#include <queue>
#include <set>

using namespace std;

// TODO: 优先队列使用push和pop入队和出队，但使用top取队首元素。

void test_pq1() {
    // TODO: 默认情况下pq是一个「越小的元素优先级越低」的优先队列
    priority_queue<int> pq;
    // 入队顺序为2 3 1
    pq.push(2);
    pq.push(3);
    pq.push(1);

    // 出队顺序为3 2 1
    while (!pq.empty()) {
        int val = pq.top();
        cout << val << endl;
        pq.pop();
    }
}

// TODO: 创建一个存放自定义类型的优先队列。该队列中个位数越大的整数，优先级越低
struct cmp {
    bool operator()(const int a, const int b) {
        return a % 10 > b % 10;
    }
};

void test_pq2() {
    priority_queue<int, vector<int>, cmp> pq;
    // 入队顺序为33 12 11
    pq.push(33);
    pq.push(12);
    pq.push(11);

    // 出队顺序为11 12 33
    while (!pq.empty()) {
        int val = pq.top();
        cout << val << endl;
        pq.pop();
    }
}

void test_pq3() {
    // TODO: 直接使用STL自带的仿函数创建一个「越小优先级越大」的优先队列
    priority_queue<int, vector<int>, greater<int> > pq;
    // 入队顺序为2 3 1
    pq.push(2);
    pq.push(3);
    pq.push(1);

    // 出队顺序为1 2 3
    while (!pq.empty()) {
        int val = pq.top();
        cout << val << endl;
        pq.pop();
    }
}

typedef long long LL;

const int coef[] = {2, 3, 5};

void p5_7() {
    priority_queue<LL, vector<LL>, greater<LL> > pq;
    set<LL> s;
    pq.push(1);
    s.insert(1);
    for (int i = 1;; i++) {
        LL x = pq.top();
        pq.pop();
        if (i == 1500) {
            cout << "The 1500'th ugly number is " << x << ".\n";
            break;
        }
        // TODO: 用已有的丑数生成新的丑数，插入队列之后自动按照从小到大的顺序排序
        for (int j : coef) {
            LL x2 = x * j;
            if (!s.count(x2)) {
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
}

int main() {
    p5_7();
    return 0;
}
