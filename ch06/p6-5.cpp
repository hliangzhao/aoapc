//
// Created by hliangzhao on 2022/4/27.
//

#include <iostream>
#include <queue>

using namespace std;

// TODO: 标记数组多一维作为连续穿的障碍物数，这样相同的位置就会可以bfs多次了

const int maxn = 20 + 5;
int n, m, k;
int arr[maxn][maxn];
int dis[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];

struct Node {
    int x, y, k;

    Node(int x = 0, int y = 0, int k = 0) : x(x), y(y), k(k) {}
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// 注意不能连续穿越k个障碍
void bfs() {
    queue<Node> q;
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));

    dis[0][0][0] = 0;
    vis[0][0][0] = 1;
    q.push(Node(0, 0, 0));
    while (!q.empty()) {
        Node v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int r = v.x + dr[i];
            int c = v.y + dc[i];
            // 设置cur_k
//            int cur_k;
//            if (arr[r][c] == 0) {
//                // 这是一个空地
//                cur_k = 0;
//            } else {
//                if (arr[v.x][v.y] == 1) {
//                    // 障碍到障碍
//                    cur_k = v.k + 1;
//                } else {
//                    // 空地到障碍
//                    cur_k = 1;
//                }
//            }
            int cur_k = v.k;
            if (arr[r][c] == 0) {
                cur_k = 0;
            } else {
                cur_k++;
            }
            if (r >= 0 && r < m && c >= 0 && c < n && !vis[r][c][cur_k] && cur_k <= k) {
                dis[r][c][cur_k] = dis[v.x][v.y][v.k] + 1;
                vis[r][c][cur_k] = 1;
                q.push(Node(r, c, cur_k));
            }
        }
    }
}

int main() {
    freopen("../ch06/p6-5-data.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        cin >> m >> n >> k;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        // 开始处理
        bfs();
        int min_dis = 1000;
        for (int i = 0; i < maxn; i++) {
            int cur_dis = dis[m - 1][n - 1][i];
            if (cur_dis > -1) {
                if (cur_dis < min_dis) {
                    min_dis = cur_dis;
                }
            }
        }
        if (min_dis != 1000) {
            cout << min_dis << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}
