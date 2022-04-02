//
// Created by hliangzhao on 2022/3/28.
//

#include <cstdio>
#include <cstring>

#define SIZE 1005

int c32_arr[SIZE];

void method1() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        c32_arr[i] = -1;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1;; j++) {
            int idx = i * j;
            if (idx > n) {
                break;
            }
            c32_arr[idx] *= -1;
        }
    }
    int first = 1;
    for (int i = 1; i <= n; i++) {
        // TODO: 使用first消除最后一个元素的空格
        if (c32_arr[i] == 1) {
            if (first) {
                printf("%d", i);
                first = 0;
            } else {
                printf(" %d", i);
            }
        }
    }
}

void method2() {
    int n, k;
    scanf("%d %d", &n, &k);
    memset(c32_arr, 0, sizeof(c32_arr));            // TODO: 使用memset设置数组元素的统一初值c（string.h head）
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (j % i == 0) {
                c32_arr[j] = !c32_arr[j];
            }
        }
    }
    int first = 1;
    for (int i = 1; i <= n; i++) {
        if (c32_arr[i]) {
            if (first) {
                first = 0;
                printf("%d", i);
            } else {
                printf(" %d", i);
            }
        }
    }
}

int main() {
    method2();
    return 0;
}
