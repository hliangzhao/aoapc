//
// Created by hliangzhao on 2022/3/31.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define c4_1_maxn 105
char e4_1_s1[c4_1_maxn], e4_1_s2[c4_1_maxn];
int cnt1[26], cnt2[26];

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    scanf("%s", e4_1_s1);
    scanf("%s", e4_1_s2);
    int len = strlen(e4_1_s1);
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));

    for (int i = 0; i < len; i++) {
        cnt1[e4_1_s1[i] - 'A']++;
    }
    for (int i = 0; i < len; i++) {
        cnt2[e4_1_s2[i] - 'A']++;
    }

    // TODO: 使用cstdlib的qsort函数对数组进行排序。需要自己实现compare函数
    qsort(cnt1, 26, sizeof(int), cmp);
    qsort(cnt2, 26, sizeof(int), cmp);

    int equal = 1;
    for (int i = 0; i > 26; i++) {
        if (cnt1[i] != cnt2[i]) {
            equal = 0;
            break;
        }
    }
    if (equal) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

