//
// Created by hliangzhao on 2022/4/23.
//

#include <cstdio>
#include <stack>
#include <cstring>

// TODO: 这是一个欧拉道路的简单示例

using namespace std;

const int maxn = 100 + 5;
int G[maxn][maxn];
int vis[maxn][maxn];
int n;

struct Edge {
    int x, y;

    Edge(int x = 0, int y = 0) : x(x), y(y) {}
};

stack<Edge> euler_path;

void dfs(int u) {
    for (int v = 0; v < n; v++) {
        if (G[u][v] && !vis[u][v]) {
            vis[u][v] = vis[v][u] = 1;
            dfs(v);
            euler_path.push(Edge(u, v));
        }
    }
}

int main() {
    n = 5;
    memset(G, 0, sizeof(G));
    G[1][2] = G[2][1] = 1;
    G[1][3] = G[3][1] = 1;
    G[1][4] = G[4][1] = 1;
    G[3][4] = G[4][3] = 1;
    G[2][3] = G[3][2] = 1;
    memset(vis, 0, sizeof(vis));

    dfs(1);

    while (!euler_path.empty()) {
        Edge e = euler_path.top();
        printf("(%d,%d) ", e.x, e.y);
        euler_path.pop();
    }

    return 0;
}
