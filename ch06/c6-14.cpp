//
// Created by hliangzhao on 2022/4/23.
//

// TODO: 教材p165求迷宫最短路问题解答

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 100 + 5;
int arr[maxn][maxn];
int dis[maxn][maxn];
int c[maxn][maxn];
int m, n;

struct Node {
    int x, y;
    Node(int x = 0, int y = 0) : x(x), y(y) {}
};

Node parent[maxn][maxn];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs() {
    queue<Node> q;
    memset(dis, -1, sizeof(dis));
    memset(c, 0, sizeof(c));
    int cnt = 1;

    Node u(0, 0);               // 起点
    dis[0][0] = 0;
    c[0][0] = cnt;
    q.push(u);
    while (!q.empty()) {
        Node v = q.front();
        q.pop();
        int i = v.x, j = v.y;
        for (int k = 0; k < 4; k++) {
            int i2 = v.x + dr[k], j2 = v.y + dc[k];
            if (i2 >= 0 && i2 < m && j2 >= 0 && j2 < n && arr[i2][j2] == 1 && dis[i2][j2] < 0) {
                dis[i2][j2] = dis[i][j] + 1;
                parent[i2][j2] = v;
                c[i2][j2] = ++cnt;
                q.push(Node(i2, j2));
            }
        }
    }
}

int main() {
    m = 6;
    n = 5;
    memset(arr, 0, sizeof(arr));
    arr[0][2] = arr[1][1] = arr[2][1] = arr[3][1] = arr[2][3] = arr[2][4] = arr[4][3] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = !arr[i][j];
        }
    }
    bfs();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
