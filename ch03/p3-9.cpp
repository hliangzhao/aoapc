//
// Created by hliangzhao on 2022/3/30.
//

/* All in All */

#include <cstdio>
#include <cstring>

#define maxn 200
char p3_9_s[maxn], p3_9_t[maxn];

int main() {
    scanf("%s", p3_9_s);
    scanf("%s", p3_9_t);
    int len_s = strlen(p3_9_s), len_t = strlen(p3_9_t);

    int cur_pos = 0;
    for (int i = 0; i < len_s; i++) {
        char c = p3_9_s[i];
        // 没有可供检查的字符了，这意味着匹配不到
        if (cur_pos >= len_t) {
            printf("False\n");
            return 0;
        }
        // 检查是否能从p3_9_t[cur_pos:]中找到s
        bool found_c = false;
        int j;
        for (j = cur_pos; j < len_t; j++) {
            if (p3_9_t[j] == c) {
                found_c = true;
                break;
            }
        }
        if (found_c) {
            cur_pos = j;
        } else {
            printf("False\n");
            return 0;
        }
    }
    printf("True\n");
    return 0;
}
