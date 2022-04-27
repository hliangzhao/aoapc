//
// Created by hliangzhao on 2022/4/27.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

// TODO: 用BFS计算从(r1,c1)到(r2,c2)的最短路径长度

int r1, r2, c1, c2;
int min_step;
int dr[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dc[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int vis[10][10];

struct Node {
    int r, c, step;

    Node(int r = 0, int c = 0, int step = 0) : r(r), c(c), step(step) {}
};

bool valid(int r, int c) {
    // TODO: 尽管是BFS，但是我们使用了vis数组来标示某个位置是否已经被跳到过，这些点应该避免。否则无限循环
    if (r >= 1 && r <= 8 && c >= 1 && c <= 8 && !vis[r][c]) {
        return true;
    }
    return false;
}

void bfs() {
    memset(vis, 0, sizeof(vis));
    queue<Node> q;
    q.push(Node(r1, c1, 0));
    vis[r1][c1] = 1;
    while (!q.empty()) {
        Node n = q.front();
        q.pop();
        if (n.r == r2 && n.c == c2) {
            if (n.step < min_step) {
                min_step = n.step;
            }
        }
        for (int i = 0; i < 8; i++) {
            int next_r = n.r + dr[i];
            int next_c = n.c + dc[i];
            if (valid(next_r, next_c)) {
                q.push(Node(next_r, next_c, n.step + 1));
                vis[next_r][next_c] = 1;
            }
        }
    }
}

int main() {
    freopen("../ch06/p6-4-data.in", "r", stdin);
    string s, t;
    while (cin >> s) {
        cin >> t;
        r1 = s[1] - '0';
        c1 = s[0] - 'a' + 1;
        r2 = t[1] - '0';
        c2 = t[0] - 'a' + 1;
        min_step = 1000;
        bfs();
        cout << "To get from " << s << " to " << t << " takes " << min_step << " knight moves.\n";
    }
    return 0;
}
