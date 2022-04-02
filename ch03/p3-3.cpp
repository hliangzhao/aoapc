//
// Created by hliangzhao on 2022/3/29.
//


/* Digit Counting */

#include <cstdio>
#include <cstring>

int main() {
    int arr[20], n;
    memset(arr, 0, sizeof(arr));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x = i;
        while (x) {
            arr[x % 10]++;
            x /= 10;
        }
    }
    for (int i = 0; i <= 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[9]);
    return 0;
}
