//
// Created by hliangzhao on 2022/3/28.
//

#include <cstdio>

#define INF 10000000

int main() {
    int x, n = 0, kase = 0;
    while (scanf("%d", &n) == 1 && n) {
        int sum = 0, min = INF, max = -INF;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            sum += x;
            if (x < min) {
               min = x;
            }
            if (x > max) {
                max = x;
            }
        }
        if (kase) {
            printf("\n");
        }
        printf("Case %d: %d %d %.3f\n", ++kase, min, max, (double)sum/n);
    }
    return 0;
}
