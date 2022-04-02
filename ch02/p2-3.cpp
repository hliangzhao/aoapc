//
// Created by hliangzhao on 2022/3/28.
//

#include <cstdio>

/* triangle */

int main() {
    int n;
    scanf("%d", &n);
    for (int i = n; i >= 1; i--) {
        int space = n - i;
        int c = 2 * i - 1;
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        for (int j = 1; j <= c; j++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
