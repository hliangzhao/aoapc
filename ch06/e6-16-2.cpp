//
// Created by hliangzhao on 2022/4/19.
//

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1000 + 5;
int degree[256];    // 出度 +1，入度 -1
int used[256];      // 1: used, 0: not used
int G[256][256];    // 是否存在边
int vis[256];       // visited or not

void dfs(int ch, int cnt) {
    if (vis[ch] != 0 || !used[ch]) return;
    vis[ch] = 1;
    for (int ch2 = 'a'; ch2 <= 'z'; ch2++) {
        if (used[ch2] && G[ch][ch2]) {
            dfs(ch2, cnt);
        }
    }
}

int main() {
    freopen("../ch06/e6-16-data.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        char word[maxn];
        scanf("%d", &n);

        memset(degree, 0, sizeof(degree));
        memset(G, 0, sizeof(G));
        memset(vis, 0, sizeof(vis));
        memset(used, 0, sizeof(used));

        for (int i = 0; i < n; i++) {
            scanf("%s", word);
            char c1 = word[0], c2 = word[strlen(word) - 1];
            degree[c1]++;
            degree[c2]--;
            used[c1] = used[c2] = 1;
            // 注意，要判断连通性的，是底图，因此我们去掉边的方向性
            G[c1][c2] = G[c2][c1] = 1;
        }

        // 使用dfs判断是否连通
        int cnt = 0;
        // 经过递归之后，若cnt等于1，说明只有一个连通块，即是一个连通图
        for (int ch = 'a'; ch <= 'z'; ch++) {
            if (!vis[ch] && used[ch]) {
                dfs(ch, ++cnt);
            }
        }

        vector<int> d;
        for (int ch = 'a'; ch <= 'z'; ch++) {
            if (degree[ch] != 0) {
                d.push_back(degree[ch]);
            }
        }

        bool ok = false;
        // cnt = 1意味着可以形成一个连通块。这是欧拉道路存在的第一个条件
        // 入度不等于出度的节点，要么是0，要么是2。若是2，则必然一个出度 = 入度 + 1，另一个入度 = 出度 + 1。这是第二个条件
        if (cnt == 1 && (d.empty() || (d.size() == 2 && (d[0] == 1 || d[0] == -1)))) ok = true;
        if (ok) printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
    return 0;
}
