//
// Created by hliangzhao on 2022/3/31.
//

/* Kickdown */

#include <cstdio>
#include <cstring>

#define container_len 105
char c1[container_len], c2[container_len];

int main() {
    scanf("%s", c1);
    scanf("%s", c2);
    int len1 = strlen(c1), len2 = strlen(c2);

    int res1, res2, i;
    // TODO: 固定c1，将c2在c1的基础上右移
    for (i = 0; i < len1; i++) {
        int ok = 1;
        for (int j = 0; j < len2; j++) {
            if (j + i >= len1) {
                break;
            }
            if (c1[i + j] - '0' + c2[j] - '0' > 3) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    if (len1 > len2 + i) {
        res1 = len1;
    } else {
        res1 = len2 + i;
    }

    // TODO: 固定c2，将c1在c2的基础上右移
    for (i = 0; i < len2; i++) {
        int ok = 1;
        for (int j = 0; j < len1; j++) {
            if (j + i >= len2) {
                break;
            }
            if (c2[i + j] - '0' + c1[j] - '0' > 3) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
    if (len2 > len1 + i) {
        res2 = len2;
    } else {
        res2 = len1 + i;
    }

    // TODO: 选择两个结果中小的那一个
    if (res1 > res2) {
        printf("%d\n", res2);
    } else {
        printf("%d\n", res1);
    }

    return 0;
}