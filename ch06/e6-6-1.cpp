//
// Created by hliangzhao on 2022/4/13.
//

#include <cstdio>
#include <cstring>

const int max_depth = 20;
const int max_idx = 1 << max_depth;
// TODO: 需要维护一个巨大的数组，模拟的空间开销和计算量都很大
int e66_s[max_idx];

int main() {
    freopen("../ch06/e6-6-data.in", "r", stdin);
    int D, I;
    while (scanf("%d %d", &D, &I) == 2) {
        memset(e66_s, 0, sizeof(e66_s));
        int n = (1 << D) - 1, k;
        for (int i = 0; i < I; i++) {
            k = 1;
            while (true) {
                // 看原题描述，先翻转开关
                e66_s[k] = !e66_s[k];
                // 反转后为true则左走，否则右走
                if (e66_s[k] == 1) {
                    k = 2 * k;
                } else {
                    k = 2 * k + 1;
                }
                if (k > n) break;
            }
        }
        printf("%d\n", k / 2);
    }
    return 0;
}
