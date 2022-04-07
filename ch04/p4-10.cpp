//
// Created by hliangzhao on 2022/4/4.
//

/* Flooded! */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SIZE 30

int elevations[SIZE];

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    freopen("../ch04/p4-10-data.in", "r", stdin);
    int m, n, v;
    memset(elevations, 0, sizeof(elevations));

    scanf("%d %d\n", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            scanf("%d ", &elevations[i * n + j]);
        }
        scanf("%d\n", &elevations[(i + 1) * n - 1]);
    }
    scanf("%d\n0 0\n", &v);

    // 对海拔高度进行排序
    qsort(elevations, m * n, sizeof(int), cmp);

    for (int i = 0; i < m * n; i++) {
        int v2 = v;
        // 假设e[i] < x <= e[i+1]
        // 则100 * (\sum_{j <= i} (e[i] - e[j])) + 100 * (\sum_{j <= i} (x - e[i])) = v
        // 由此计算出x。若x不满足范围要求，则continue
        for (int j = 0; j <= i; j++) {
            v2 -= 100 * (elevations[i] - elevations[j]);
        }
        double x = (double) v2 / 100 / (i + 1) + elevations[i];
        if (x <= elevations[i] || x > elevations[i + 1]) {
            continue;
        } else {
            printf("Water level is %.2f meters.\n%.2f percent of the region is under water.\n", x,
                   (double) (i + 1) / (m * n) * 100);
        }
    }

    return 0;
}
