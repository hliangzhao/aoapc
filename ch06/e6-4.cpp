//
// Created by hliangzhao on 2022/4/13.
//

// TODO: 使用数组构建链表

#include <cstdio>
#include <cstring>

const int maxn = 100000 + 5;
int last, cur, next[maxn];
char s[maxn];

int main() {
    freopen("../ch06/e6-4-data.in", "r", stdin);
    // 字符从第1个位置开始存储
    while (scanf("%s", s + 1) == 1) {
        int n = (int) strlen(s + 1);
        last = cur = 0;
        // next[0]表示最左边的字符
        next[0] = 0;

        // 开始遍历每一个字符
        for (int i = 1; i <= n; i++) {
            char ch = s[i];
            if (ch == '[') {
                // 光标移动到最左边，即当前第一个字符的前面
                cur = 0;
            } else if (ch == ']') {
                // last记录的是当前最后一个字符的索引，因此此时光标移动到最后一个字符的后面
                cur = last;
            } else {
                // TODO: 以下部分较为抽象，仔细品味！
                // 这是一个普通字符，这个字符会被打印到当前光标的后面。
                // 因此，在打印这个字符之前，当前光标右边的字符就是ch的下一个字符，即：
                next[i] = next[cur];
                // 现在字符ch被打印了，但是光标的位置还没有更新，即光标此刻在ch的左边了，那么有：
                next[cur] = i;
                if (cur == last) {
                    // 更新last
                    last = i;
                }
                // 更新光标的位置
                cur = i;
            }
        }

        // i == 0意味者走到了没有被设置过的元素那里（0为初值），意味着结束了
        for (int i = next[0]; i != 0; i = next[i]) {
            printf("%c", s[i]);
        }
        printf("\n");
    }

    return 0;
}
