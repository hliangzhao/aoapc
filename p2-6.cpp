//
// Created by hliangzhao on 2022/3/28.
//

/* permutation */

#include <cstdio>

int main() {
    int start = 123, end = 987 / 3;
    for (int abc = start; abc <= end; abc++) {
        int arr[10];
        int def = 2 * abc;
        int ghi = 3 * abc;
        int a = abc / 100, b = abc / 10 % 10, c = abc % 10;
        int d = def / 100, e = def / 10 % 10, f = def % 10;
        int g = ghi / 100, h = ghi / 10 % 10, i = ghi % 10;
        arr[a]++;
        arr[b]++;
        arr[c]++;
        arr[d]++;
        arr[e]++;
        arr[f]++;
        arr[g]++;
        arr[h]++;
        arr[i]++;
        bool legal = true;
        for (int j = 1; j <= 9; j++) {
            if (arr[j] != 1) {
                legal = false;
                break;
            }
        }
        if (legal) {
            printf("%d %d %d\n", abc, def, ghi);
        }
        for (int j = 1; j <= 9; j++) {
            arr[j] = 0;
        }
    }
    return 0;
}