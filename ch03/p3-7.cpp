//
// Created by hliangzhao on 2022/3/30.
//

/* DNA Consensus String */

#include <cstdio>

#define max_m 55
#define max_n 1005
#define LOCAL

char p3_7_s[max_m][max_n];

int main() {
#ifdef LOCAL
    freopen("../ch03/p3-7-data.in", "r", stdin);
#endif
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%s", p3_7_s[i]);
    }

    char tmp[] = {'A', 'C', 'G', 'T'};

    int total_distance = 0;
    // 依次找到每一列出现次数最多的字符
    for (int j = 0; j < n; j++) {
        int cnt[4] = {0, 0, 0, 0};
        for (int i = 0; i < m; i++) {
            if (p3_7_s[i][j] == 'A') {
                cnt[0]++;
            } else if (p3_7_s[i][j] == 'C') {
                cnt[1]++;
            } else if (p3_7_s[i][j] == 'G') {
                cnt[2]++;
            } else {
                cnt[3]++;
            }
        }
        int max_val = -max_m, dis = 0;
        char max_c;
        for (int k = 0; k < 4; k++) {
            if (cnt[k] > max_val) {
                max_val = cnt[k];
                max_c = tmp[k];
            }
        }
        printf("%c", max_c);
        for (int k = 0; k < 4; k++) {
            if (tmp[k] != max_c) {
                dis += cnt[k];
            }
        }
        total_distance += dis;
    }
    printf("\nTotal distance: %d\n", total_distance);

    return 0;
}