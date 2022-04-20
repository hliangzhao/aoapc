//
// Created by hliangzhao on 2022/4/20.
//

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100000 + 5;            // 最大节点个数
const int maxc = 1000000000;            // 最大颜色个数
int n;                                  // 节点个数
int vis[maxn], min_dis[maxn];           // 访问标记、每个节点到终点的最短距离

struct Edge {
    int u, v, c;

    Edge(int u = 0, int v = 0, int c = 0) : u(u), v(v), c(c) {}
};

vector<Edge> edges;
vector<int> G[maxn];                    // G[u]记录了和u相连的边的编号

void add_edge(int u, int v, int c) {
    edges.emplace_back(u, v, c);
    int edge_idx = (int) edges.size() - 1;
    G[u].push_back(edge_idx);
}

// 从终点 (idx = n-1) 开始倒着BFS，求出每个节点u到终点的最短距离min_dis[u]
void rev_bfs() {
    memset(vis, 0, sizeof(vis));
    min_dis[n - 1] = 0;
    vis[n - 1] = true;

    queue<int> q;
    q.push(n - 1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < G[u].size(); i++) {
            int e = G[u][i];
            int v = edges[e].v;
            if (!vis[v]) {
                vis[v] = true;
                min_dis[v] = min_dis[u] + 1;
                q.push(v);
            }
        }
    }
}

vector<int> res;                        // 存放理想路径

// 从起点 (idx = 0) 开始BFS，找到字典序最小的边的序列
void bfs() {
    memset(vis, 0, sizeof(vis));
    vis[0] = true;
    res.clear();

    vector<int> next;
    next.push_back(0);
    // 遍历每一个距离，就是在遍历每一个「下一步」
    for (int i = 0; i < min_dis[0]; i++) {
        int min_color = maxc;
        for (int u : next) {
            for (int k = 0; k < G[u].size(); k++) {
                int e = G[u][k];
                int v = edges[e].v;
                if (min_dis[u] == min_dis[v] + 1) {
                    // 说明 (u,v) 是最短路径上的一条边
                    // 从中选择颜色编号最小的作为理想路径中的边
                    min_color = min(min_color, edges[e].c);
                }
            }
        }
        res.push_back(min_color);

        vector<int> next2;
        for (int u : next) {
            for (int k = 0; k < G[u].size(); k++) {
                int e = G[u][k];
                int v = edges[e].v;
                // 将上面找到的理想路径中的边（即color == min_color）的终点扔进vector用于BFS
                if (min_dis[u] == min_dis[v] + 1 && !vis[v] && edges[e].c == min_color) {
                    next2.push_back(v);
                    vis[v] = true;
                }
            }
        }
        next = next2;
    }

    printf("%d\n", (int) res.size());
    printf("%d", res[0]);
    for (int i = 1; i < res.size(); i++) printf(" %d", res[i]);
    printf("\n");
}

int main() {
    freopen("../ch06/e6-20-data.in", "r", stdin);
    int u, v, c, m;
    while (scanf("%d%d", &n, &m) == 2) {
        edges.clear();
        for (int i = 0; i < n; i++) G[i].clear();
        while (m--) {
            scanf("%d%d%d", &u, &v, &c);
            add_edge(u - 1, v - 1, c);
            add_edge(v - 1, u - 1, c);
        }
        rev_bfs();
        bfs();
    }
    return 0;
}
