//
// Created by hliangzhao on 2022/4/15.
//

#include <iostream>

using namespace std;

// TODO: 图也有DFS和BFS。和树一样，前者可以通过递归来实现，后者可以借助队列来实现。
//  求二维数组连通块（又名：种子填充、floodfill）是一个十分经典的问题，彻底掌握！

const int maxn = 100 + 5;

char arr[maxn][maxn];
// TODO: 二维数组block_id记录每一个位置所在的连通块的编号。它还间接记录了每个位置是否已经被访问过，从而避免重复访问
int m, n, block_id[maxn][maxn];

void dfs(int r, int c, int id) {
    // 出界
    if (r < 0 || r >= m || c < 0 || c >= n) return;
    // 已访问或不是连通块元素
    // TODO: 为什么第45行已经确认了调用dfs的条件，这里仍然需要再判断一遍？这是因为dfs不仅在第46行被调用，在本函数内也被递归调用了！
    //  对于这些递归进来的调用请求，必须要判断它们的调用是否合法。
    if (block_id[r][c] > 0 || arr[r][c] != '@') return;
    block_id[r][c] = id;
    // 依次遍历上下左右包围着的8个元素
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr != 0 || dc != 0) {     // 二者不同时为零
                dfs(r + dr, c + dc, id);
            }
        }
    }
}

int main() {
    freopen("../ch06/e6-12-data.in", "r", stdin);
    while (scanf("%d %d", &m, &n) == 2 && m && n) {
        for (int i = 0; i < m; i++) {
            scanf("%s", arr[i]);
        }
        memset(block_id, 0, sizeof(block_id));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (block_id[i][j] == 0 && arr[i][j] == '@') {
                    dfs(i, j, ++cnt);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
