//
// Created by hliangzhao on 2022/3/30.
//

/* Box */

#include <cstdio>

int main() {
    // TODO: 处理思路 —— 每个数字必须出现4次。
    int len[20];
    for (int i = 0; i < 12; i++) {
        scanf("%d", &len[i]);
    }
    int cnt, ok = 1;
    for (int i = 0; i < 12; i++) {
        cnt = 0;
        int val = len[i];
        for (int j = 0; j < 12; j++) {
            if (val == len[j]) {
                cnt++;
            }
        }
        if (cnt != 4) {
            ok = 0;
        }
    }
    if (ok) {
        printf("Can\n");
    } else {
        printf("Cannot\n");
    }

    return 0;
}
