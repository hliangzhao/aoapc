//
// Created by hliangzhao on 2022/3/30.
//

#include <cstdio>

long long C(int n, int m) {
    // TODO: 这是因为C_n^m = C_n^{n-m}
    if (m < n - m) {
        m = n - m;
    }
    long long res = 1;
    // TODO: 对于如阶乘之类的复杂运算，最好进行简化，以免中间结果溢出
    for (int i = m + 1; i <= n; i++) {
        res *= i;
    }
    for (int i = 1; i <= n - m; i++) {
        res /= i;
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%lld", C(n, m));
    return 0;
}
