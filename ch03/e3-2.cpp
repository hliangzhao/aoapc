//
// Created by hliangzhao on 2022/3/29.
//

#include <cstdio>
#include <cstring>

#define LOCAL
#define SIZE 80
char s[SIZE] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

void method1() {
    char input[205];
    fgets(input, 200, stdin);
    for (int i = 0; i < strlen(input) - 1; i++) {
        char c = input[i];
        for (int j = 0; j < strlen(s); j++) {
            if (c == ' ') {
                printf(" ");
                break;
            }
            if (c == s[j]) {
                printf("%c", s[j - 1]);
            }
        }
    }
}

void method2() {
#ifdef LOCAL
    freopen("../ch03/e3-2-data.in", "r", stdin);
#endif
    int i, c;
    while ((c = getchar()) != EOF) {
        for (i = 1; s[i] && s[i] != c; i++);
        if (s[i]) {
            putchar(s[i - 1]);
        } else {
            // TODO: 只可能是空格
            putchar(c);
        }
    }
}

int main() {
    method2();
    return 0;
}
