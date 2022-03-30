//
// Created by hliangzhao on 2022/3/30.
//

/* Repeating Decimals */

#include <cstdio>

#define p3_8_maxn 20000
int p3_8_digits[p3_8_maxn];

int main() {
    int a, b, repeat_test_num = 90;
    scanf("%d %d", &a, &b);

    // TODO：思路 —— 模仿除法，将小数全部存入数组中，然后找到一个最小的子串，使得该子串至少被重复repeat_test_num次。
    //  这个方法不够鲁棒。
    //  首先，当除法结果不循环时，该方法出错。
    //  其次，这里repeat_test_num是个经验数字，因此对于某些案例可能会错解。
    for (int i = 0; i < p3_8_maxn; i++) {
        p3_8_digits[i] = a / b;
        a = (a % b) * 10;
    }
    int span, ok;
    for (span = 0; span < 200; span++) {
        ok = 1;
        // 判断p3_8_digits[1:1+span]是否被连续重复repeat_test_num次
        for (int k = 1; k <= repeat_test_num; k++) {
            // 比较p3_8_digits[1:1+span]是否和p3_8_digits[1+(1+span)*k:(1+span)*(k+1)]
            for (int i = 1; i <= 1 + span; i++) {
                if (p3_8_digits[i] != p3_8_digits[i + (1 + span) * k]) {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok) {
            // found
            printf("(");
            for (int i = 1; i <= 1 + span; i++) {
                printf("%d", p3_8_digits[i]);
            }
            printf(")\n%d\n", span + 1);
            return 0;
        }
    }
    return 0;
}
