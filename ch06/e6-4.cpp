//
// Created by hliangzhao on 2022/4/13.
//

// TODO: 使用数组构建链表

#include <cstdio>
#include <cstring>

const int maxn = 100000 + 5;
int last, cursor, next[maxn];
char s[maxn];

int main() {
    freopen("../ch06/e6-4-data.in", "r", stdin);
    // 字符从第1个位置开始存储
    while (scanf("%s", s + 1) == 1) {
        int n = (int) strlen(s + 1);
        // TODO: 第一个字符和当前最后一个字符的index分别为1和last
        //  光标所在的位置用cursor记录，cursor+1是下一个字符的打印位置
        last = cursor = 0;
        // next[0] = next[cursor=0] = 最左边的字符
        next[0] = 0;

        // 开始遍历每一个字符
        for (int i = 1; i <= n; i++) {
            char ch = s[i];
            if (ch == '[') {
                // TODO：光标移动到最左边，即当前第一个字符的前面
                //  即下一个字符会被打印到第一个坑位
                cursor = 0;
            } else if (ch == ']') {
                // TODO：last记录的是当前最后一个字符的索引，因此此时光标移动到最后一个字符的位置
                //  即下一个字符会被打印到当前最后一个字符的后面
                cursor = last;
            } else {
                // TODO: 这是一个普通字符，这个字符会被打印到当前光标的后面（即cursor+1的位置）。
                //  因此，在打印这个字符之前，当前光标右边的字符就是ch的下一个字符，即：
                next[i] = next[cursor];

                // 打印字符ch。

                // TODO: 现在字符ch被打印了，但是光标的位置还没有更新，那么此刻ch就成了光标所指向的元素的下一个元素。
                //  因此有：
                next[cursor] = i;

                // TODO：当前最后一个元素的位置要继续往后开辟
                if (cursor == last) {
                    // 更新last
                    last = i;
                }
                // TODO：最后，雷打不动地更新光标的位置
                cursor = i;
            }
        }

        // TODO: i == 0意味者走到了没有被设置过的元素那里（0为初值），意味着结束了
        for (int i = next[0]; i != 0; i = next[i]) {
            printf("%c", s[i]);
        }
        printf("\n");
    }

    return 0;
}
