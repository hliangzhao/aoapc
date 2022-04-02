//
// Created by hliangzhao on 2022/4/1.
//

#include <cstdio>
#include <cstring>
#define LOCAL

int main() {
#ifdef LOCAL
    freopen("../ch04/e4-3-data.in", "r", stdin);
#endif
    int n, k, m, arr[25];
    while (scanf("%d%d%d", &n, &k, &m) && n) {
        memset(arr, 1, sizeof(arr));
        int leave = 0, a_pos = 0, b_pos = n + 1;
        // idx从1开始
        while (leave <= n) {
            // A从前往后数k个
            int A_step = 0;
            while (A_step != k) {
                a_pos = (a_pos + 1) % n;
                if (a_pos == 0) {
                    a_pos = n;
                }
                if (arr[a_pos] != 0) {
                    A_step++;
                }
            }
            // B从后往前数m个
            int B_step = 0;
            while (B_step != m) {
                b_pos = b_pos - 1;
                if (b_pos <= 0) {
                    b_pos += n;
                }
                if (arr[b_pos] != 0) {
                    B_step++;
                }
            }
            if (b_pos == a_pos) {
                arr[a_pos] = 0;
                leave++;
                printf("%3d\n", a_pos);
            } else {
                arr[a_pos] = 0;
                arr[b_pos] = 0;
                leave += 2;
                printf("%3d%3d\n", a_pos, b_pos);
            }
        }
    }

    return 0;
}