//
// Created by hliangzhao on 2022/3/28.
//

#include <cstdio>
#include <cstring>

#define SIZE 20

int c33_arr[SIZE][SIZE];

int main() {
    int n;
    scanf("%d", &n);
    memset(c33_arr, 0, sizeof(c33_arr));
    int i, j, val = c33_arr[i = 0][j = n - 1] = 1;
    while (val < n * n) {
        // TODO: 短路原则。先判断是否在数组范围内，然后判断当前位置是否已经被填充
        while (i + 1 < n && !c33_arr[i + 1][j]) {
            c33_arr[++i][j] = ++val;
        }
        while (j - 1 >= 0 && !c33_arr[i][j - 1]) {
            c33_arr[i][--j] = ++val;
        }
        while (i - 1 >= 0 && !c33_arr[i - 1][j]) {
            c33_arr[--i][j] = ++val;
        }
        while (j + 1 < n && !c33_arr[i][j + 1]) {
            c33_arr[i][++j] = ++val;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%5d", c33_arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
