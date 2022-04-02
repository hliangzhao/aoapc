//
// Created by hliangzhao on 2022/3/29.
//

/* Periodic Strings */

#include <cstdio>
#include <cstring>
#define maxn 85

char p3_4_s[maxn], sub_str[maxn];

int main() {
    scanf("%s", p3_4_s);
    int len = strlen(p3_4_s), res;
    for (res = 1; res <= len; res++) {
        int res_ok = 1;
        if (len % res != 0) continue;
        // 检查res是否是一个周期长度
        for (int i = 0; i < res; i++) {
            sub_str[i] = p3_4_s[i];
        }
        for (int j = res; j < len; j += res) {
            // 比较p3_4_s[j, j + res - 1]和sub_str
            for (int k = 0; k < res; k++) {
                if (p3_4_s[j + k] != sub_str[k]) {
                    // 说明当前的res不合适
                    res_ok = 0;
                    break;
                }
            }
        }
        if (res_ok) {
            printf("%d\n", res);
            return 0;
        }
    }
    return 0;
}