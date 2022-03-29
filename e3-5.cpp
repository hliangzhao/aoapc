//
// Created by hliangzhao on 2022/3/29.
//

#include <cstdio>
#include <cstring>

void method1() {
    int n, x;
    scanf("%d", &n);
    int found = 0;
    for (x = 1; x < n; x++) {
        int sum = x, x2 = x, y = 0;
        while (x2) {
            y = x2 % 10;
            sum += y;
            x2 = (x2 - y) / 10;
        }
        if (sum == n) {
            printf("%d\n", x);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("0\n");
    }
}

// TODO: 一次性枚举所有结果，最后查表。当有多次输入的时候，这是更快的计算方式。

#define SIZE 100005
int ans[SIZE];

void method2() {
    int T, n;
    memset(ans, 0, sizeof(ans));
    for (int m = 1; m < SIZE; m++) {
        int x = m, y = m;
        while (x > 0) {
            y += x % 10;
            x /= 10;
        }
        if (ans[y] == 0 || m < ans[y]) {
            ans[y] = m;
        }
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
}

int main() {
    method2();
    return 0;
}
