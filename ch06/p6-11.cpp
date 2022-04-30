//
// Created by hliangzhao on 2022/4/29.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// TODO：思路 —— 拿dfs的序列，分成若干段，每一段相当一个子树，
//  这样就可以利用bfs的序列去将dfs的序列分段，然后利用一个队列去存放每一段，不断求出子树即可。

const int maxn = 1000 + 5;
int n;                          // 节点个数
int BFS[maxn], DFS[maxn];       // BFS 和 DFS的序列（从 index = 0 开始存储）
int cur;                        // 当前游标所在位置
vector<int> children[maxn];     // 从1开始计数

struct Seq {
    int l, r;                   // [l, r)

    Seq(int l, int r) : l(l), r(r) {}
};

// 从DFS序列中得到一个个分段（子树）
void bfs() {
    cur = 1;
    queue<Seq> q;
    q.push(Seq(0, n));
    while (!q.empty()) {
        Seq s = q.front();
        q.pop();
        int u = DFS[s.l];
        if (cur == n || s.l + 1 == s.r) continue;
        // 在DFS中，pre紧跟着u，因此pre必然是u的孩子
        int pre = s.l + 1;
        children[u].push_back(DFS[pre]);            // 这里是直接记录孩子节点的代码
        cur++;
        for (int i = s.l + 2; i < s.r; i++) {
            // 在 DFS 序列中找到 u 的下一个直接孩子节点 DFS[i]
            if (BFS[cur] == DFS[i]) {
                children[u].push_back(DFS[i]);      // 这里是直接记录孩子节点的代码
                // pre和i分别是u的前后相邻的两个孩子的index
                // 因为可能是多叉树，所以更新pre为i，再继续找下一个孩子的index i（如果有的话）
                q.push(Seq(pre, i));
                pre = i;
                cur++;
            }
        }
        if (pre < s.r) {
            // 这一部分是最后一棵子树（从最后一个孩子的index到序列末尾）
            q.push(Seq(pre, s.r));
        }
    }
}

int main() {
    freopen("../ch06/p6-11-data.in", "r", stdin);
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            children[i + 1].clear();
            cin >> BFS[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> DFS[i];
        }
        bfs();
        for (int i = 1; i <= n; i++) {
            cout << i << ":";
            for (int j: children[i]) {
                cout << " " << j;
            }
            cout << endl;
        }
    }
    return 0;
}
