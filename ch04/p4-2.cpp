//
// Created by hliangzhao on 2022/4/3.
//

/* Squares */
#include <cstdio>
#include <cstring>

#define LOCAL
#define square_size 10

int H[square_size][square_size], V[square_size][square_size], res[square_size];

int main() {
#ifdef LOCAL
    freopen("../ch04/p4-2-data.in", "r", stdin);
#endif
    memset(H, 0, sizeof(H));
    memset(V, 0, sizeof(V));
    memset(res, 0, sizeof(res));
    int n, m;
    // TODO: 记得把换行符读进来！
    scanf("%d %d\n", &n, &m);
    for (int edge_idx = 0; edge_idx < m; edge_idx++) {
        char type;
        int i, j;
        // TODO: 记得把换行符读进来！
        scanf("%c %d %d\n", &type, &i, &j);
        if (type == 'H') {
            H[i][j] = 1;
        } else {
            V[i][j] = 1;
        }
    }

    // 遍历每一个节点
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 以(i,j)作为正方形的左上节点
            for (int len = 1; len <= n - i && len <= n - j; len++) {
                // 判断长度为len的正方形是否存在
                int ok = 1;
                for (int duration = 0; duration <= len - 1; duration++) {
                    // 上 下 左 右
                    if (H[i][j + duration] == 0 || H[i + len][j + duration] == 0 || V[i + duration][j] == 0 ||
                        V[i + duration][j + len] == 0) {
                        ok = 0;
                        break;
                    }
                }
                if (!ok) {
                    continue;
                }
                res[len]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (res[i] > 0) {
            printf("side length: %d, number of squares: %d\n", i, res[i]);
        }
    }

    return 0;
}