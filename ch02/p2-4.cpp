//
// Created by hliangzhao on 2022/3/28.
//

/* subsequence */

#include <cstdio>

int main() {
    int n, m, kase = 1;
    while (scanf("%d %d", &n, &m) == 2 && n && m) {
        double s = 0;
        // TODO: 转为long long型数据，防止计算时溢出
        for (long long i = n; i <= m; i++) {
            s += 1.0 / (double)(i * i);
        }
        printf("Case %d: %.5f\n", kase++, s);
    }
    return 0;
}