//
// Created by hliangzhao on 2022/3/28.
//

#include <cstdio>

#define LOCAL
#define SIZE 105
int c31_arr[SIZE];  // TODO: 比较大的数组应当申明在函数外（堆而非栈上）

int main() {
#ifdef LOCAL
    freopen("../e2-5-data.in", "r", stdin);
#endif
    int x, n = 0;
    while (scanf("%d", &x) == 1) {
        c31_arr[n++] = x;
    }
    for (int i = n - 1; i >= 1; i--) {
        printf("%d ", c31_arr[i]);
    }
    printf("%d\n", c31_arr[0]);
    return 0;
}
