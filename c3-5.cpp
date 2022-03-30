//
// Created by hliangzhao on 2022/3/29.
//

#include <cstdio>
#include <cstring>

#define maxn 10000000 + 10
char s[maxn];

int main() {
    // TODO: 大数组需要在函数外声明，这样是分配在堆上的，否则会爆栈
//    char s[maxn];
    scanf("%s", s);
    int tot = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '1') {
            tot++;
        }
    }
    printf("%d\n", tot);
    return 0;
}
