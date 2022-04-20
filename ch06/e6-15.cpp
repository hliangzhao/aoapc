//
// Created by hliangzhao on 2022/4/19.
//

// TODO: 使用DFS求出DAG的拓扑排序。本代码还可以判断给定的图是否有环路。
//  结合e6-19实现DFS版的拓扑排序！

#include <cstdio>
#include <cstring>

const int maxn = 105;
// TODO: vis_state记录每个节点的访问状态
//  0: 当前节点从来没有访问过；
//  1: 已经访问过，并且还递归访问过它的所有孩子节点；
//  -1: 正在访问（递归调用正在栈帧中）
int vis_state[maxn];
// TODO: topo存放拓扑排序的结果
int topo[maxn];
// TODO: 若G[i][j] = 1意味着存在一条从i到j的边
int G[maxn][maxn];
int n, m, t;

bool dfs(int u) {
    // u正在被递归访问
    vis_state[u] = -1;
    for (int v = 0; v < n; v++) {
        // 找到u的所有后继v
        if (G[u][v]) {
            // 存在环路
            if (vis_state[v] < 0) return false;
            // v没有被访问过，但是进去递归访问一下发现存在环路
            else if (!vis_state[v] && !dfs(v)) return false;
        }
    }
    // 对u的递归访问结束，设置状态为1
    vis_state[u] = 1;
    topo[--t] = u;
    return true;
}

bool topo_sort() {
    t = n;
    memset(vis_state, 0, sizeof(vis_state));
    for (int u = 0; u < n ;u++) {
        // 对于每一个尚未访问过的节点u
        if (vis_state[u] == 0) {
            // dfs只要返回false，就意味着存在环路
            if (!dfs(u)) return false;
        }
    }
    return true;
}

int main() {
    freopen("../ch06/e6-15-data.in", "r", stdin);
    while (scanf("%d%d", &n, &m) == 2 && n && m) {
        memset(G, 0, sizeof(G));
        int pre, post;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &pre, &post);
            // 输入从1开始编号，我们从0开始编号
            G[pre - 1][post - 1] = 1;
        }
        if (topo_sort()) {
            int first = 1;
            for (int i = 0; i < n; i++) {
                if (first) {
                    printf("%d", topo[i] + 1);
                    first = 0;
                } else {
                    printf(" %d", topo[i] + 1);
                }
            }
            printf("\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
