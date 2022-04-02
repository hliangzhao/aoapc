//
// Created by hliangzhao on 2022/3/29.
//

/* Molar Mass */

#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
    char input[40];
    scanf("%s", input);
    char last_char = ' ', c;
    double res = 0;
    int num = 1, first_number = 1;

    for (int i = 0; i < strlen(input); i++) {
        c = input[i];
        if (isalpha(c)) {
            // 每一次开始计算上一轮的结果，因此修改初始计数
            if (last_char == 'C') {
                res += 12.01 * num;
                first_number = !first_number;
                num = 1;
            } else if (last_char == 'H') {
                res += 1.008 * num;
                first_number = !first_number;
                num = 1;
            } else if (last_char == 'O') {
                res += 16.00 * num;
                first_number = !first_number;
                num = 1;
            } else if (last_char == 'N') {
                res += 14.01 * num;
                first_number = !first_number;
                num = 1;
            }
            // 如果last_char不是上述四个字符，则为' '，此时只需要更新它
            last_char = c;
        } else {
            if (first_number) {
                num = c - '0';
                first_number = !first_number;
            } else {
                num = num * 10 + c - '0';
            }
        }
    }

    if (isalpha(c)) {
        if (c == 'C') {
            res += 12.01;
        } else if (c == 'H') {
            res += 1.008;
        } else if (c == 'O') {
            res += 16.00;
        } else if (c == 'N') {
            res += 14.01;
        }
    } else {
        if (first_number) {
            num = c - '0';
        } else {
            num = num * 10 + c - '0';
        }
        if (last_char == 'C') {
            res += 12.01 * num;
        } else if (last_char == 'H') {
            res += 1.008 * num;
        } else if (last_char == 'O') {
            res += 16.00 * num;
        } else if (last_char == 'N') {
            res += 14.01 * num;
        }
    }
    printf("%.3lfg/mol\n", res);
    return 0;
}
