//
// Created by hliangzhao on 2022/3/28.
//

#include <cstdio>
#include <cmath>

void method1() {
    for (int a = 1; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            int s = a * 1100 + b * 11;
            // TODO: 注意下面这种验证是否为平方数的方法
            int m = floor(sqrt(s) + 0.5);
            if (m*m == s) {
                printf("%d\n", s);
            }
        }
    }
}

void method2() {
    for (int x= 1; ; x++) {
        int n = x * x;
        if (n < 1000) continue;
        if (n > 9999) break;
        int high = n / 100;
        int low = n % 100;
        if (high/10 == high%10 && low/10 == low%10) {
            printf("%d\n", n);
        }
    }
}

void method3() {
    int x = 1;
    while (true) {
        int n = x * x;
        if (n < 1000) {
            x++;
            continue;
        }
        if (n > 9999) break;
        int high = n / 100;
        int low = n % 100;
        if (high/10 == high%10 && low/10 == low%10) {
            printf("%d\n", n);
        }
        x++;
    }
}

int main() {
    method3();
    return 0;
}