//
// Created by hliangzhao on 2022/3/29.
//

#include <cstdio>
#include <cstring>
#include <cctype>

#define LOCAL
char str1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
char str2[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

void method1() {
    char input[85], tmp[85];
    while (fgets(input, 80, stdin)) {
        memset(tmp, ' ', sizeof(tmp));

        // TODO: 将最后的'\n'去掉
        int len = strlen(input);
        input[len - 1] = '\0';
        len -= 1;

        int p = 1, m = 1;

        for (int i = 0; i < len / 2; i++) {
            if (input[i] != input[len - 1 - i]) {
                p = 0;
                break;
            }
        }

        for (int i = 0; i < len; i++) {
            char c = input[i];
            for (int j = 0; j < strlen(str1); j++) {
                if (str1[j] == c) {
                    tmp[i] = str2[j];
                }
            }
        }
        for (int i = 0; i < len; i++) {
            if (input[i] != tmp[len - 1 - i]) {
                m = 0;
                break;
            }
        }

        if (p && m) {
            printf("%s -- is a mirrored palindrome.\n\n", input);
        } else if (p && !m) {
            printf("%s -- is a regular palindrome.\n\n", input);
        } else if (!p && m) {
            printf("%s -- is a mirrored string.\n\n", input);
        } else {
            printf("%s -- is not a palindrome.\n\n", input);
        }
    }
}

char rev(char c) {
    // TODO: type.h提供的函数isalpha(), isdigit(), isprint(), toupper(), tolower()等。
    if (isalpha(c)) {
        return str2[c - 'A'];
    }
    return str2[c - '0' + 25];
}

void method2() {
    char input[85];
    while (scanf("%s", input) == 1) {
        int len = strlen(input);
        int p = 1, m = 1;
        for (int i = 0; i < len / 2; i++) {
            if (input[i] != input[len - 1 -i]) {
                p = 0;
            }
            if (rev(input[i]) != input[len - 1 -i]) {
                m = 0;
            }
        }
        if (p && m) {
            printf("%s -- is a mirrored palindrome.\n\n", input);
        } else if (p && !m) {
            printf("%s -- is a regular palindrome.\n\n", input);
        } else if (!p && m) {
            printf("%s -- is a mirrored string.\n\n", input);
        } else {
            printf("%s -- is not a palindrome.\n\n", input);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("../ch03/e3-3-data.in", "r", stdin);
#endif
    method2();
    return 0;
}