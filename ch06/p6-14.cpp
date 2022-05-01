//
// Created by hliangzhao on 2022/4/28.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// TODO：这道题看起来是BFS求最短路径，其实是欧拉道路问题。
//  需要通过构造边使得构建出来的图具有欧拉道路。

const int maxn = 1000 + 5;
vector<int> G[maxn];
bool used[maxn];
int V, E, T, num;

void dfs(int s) {
    used[s] = true;
    // 若G[s].size()是奇数，则num++
    // 这里是判断本连通块中奇度顶点的个数
    if (G[s].size() & 1) {
        num++;
    }
    // 递归找到本连通块中全部的节点
    for (int t: G[s]) {
        if (!used[t]) {
            dfs(t);
        }
    }
}

int main() {
    freopen("../ch06/p6-14-data.in", "r", stdin);
    int kase = 0;
    while (cin >> V >> E >> T && V && E && T) {
        if (E == 0) {
            cout << "Case " << ++kase << ": 0\n";
            continue;
        }

        memset(used, 0, sizeof(used));
        for (auto &edges: G) {
            edges.clear();
        }

        for (int i = 0; i < E; i++) {
            int s, t;
            cin >> s >> t;
            G[s].push_back(t);
            G[t].push_back(s);
        }

        // cnt记录当前图G中连通块的个数
        // num记录当前编号为cnt的连通块中奇度顶点的个数
        int add_edge_num = 0, cnt = 0;
        for (int s = 1; s <= V; s++) {
            if (!used[s] && !G[s].empty()) {
                cnt++;
                num = 0;
                dfs(s);
                // 经过dfs之后，当前连通块（编号为cnt）中奇度顶点的个数已经存储在num中
                // 若当前连通块中奇度顶点的个数 <= 2，则说明这个连通块本身具有欧拉道路，不用管
                if (num >= 2) {
                    add_edge_num += (num - 2) / 2;
                }
            }
        }
        // 有多少个连通块，我们只需要加上 "连通块个数 - 1" 条边，就可以把这些连通块连起来，从而形成一整个大连通图
        add_edge_num += cnt - 1 + E;
        add_edge_num *= T;
        cout << "Case " << ++kase << ": " << add_edge_num << endl;
    }
    return 0;
}
