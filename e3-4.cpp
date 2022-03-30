//
// Created by hliangzhao on 2022/3/29.
//

#include <cstdio>
#include <cstring>

#define SIZE 20
#define LOCAL

int result[SIZE], guess[SIZE], matched[SIZE], used[SIZE];

int main() {
#ifdef LOCAL
    freopen("../e3-4-data.in", "r", stdin);
#endif
    int n, kase = 0;
    while (scanf("%d", &n) == 1 && n) {
        printf("Game %d:\n", ++kase);

        for (int i = 0; i < n; i++) {
            scanf("%d", &result[i]);
        }

        while (true) {
            memset(matched, 0, sizeof(matched));
            memset(used, 0, sizeof(used));

            for (int i = 0; i < n; i++) {
                scanf("%d", &guess[i]);
            }
            int end = 1;
            for (int i = 0; i < n; i++) {
                if (guess[i] != 0) {
                    end = 0;
                    break;
                }
            }
            if (end) {
                break;
            }

            // 开始匹配
            int A = 0, B = 0;
            for (int i = 0; i < n; i++) {
                if (result[i] == guess[i]) {
                    matched[i] = 1;
                    A++;
                }
            }
            for (int j = 0; j < n; j++) {
                if (matched[j] == 1) {
                    continue;
                }
                // 从result中匹配guess[j]
                for (int i = 0; i < n; i++) {
                    if (matched[i] == 1 || used[i] == 1) {
                        continue;
                    }
                    if (guess[j] == result[i]) {
                        used[i] = 1;
                        B++;
                        break;
                    }
                }
            }
            printf("    (%d, %d)\n", A, B);
        }
        printf("\n");
    }
    return 0;
}