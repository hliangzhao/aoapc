//
// Created by hliangzhao on 2022/4/30.
//

#include <iostream>
#include <vector>

using namespace std;

// TODO: 思路 —— 本题本质上是通过BFS求最短路径。难点是骰子的移动以及要设计四维的vis矩阵。

const int maxn = 10 + 5;
char name[30];
int n, m;
int die[6 + 1][6 + 1];
int vis[maxn][maxn][6 + 1][6 + 1];
int sx, sy, u, f;
int maze[maxn][maxn];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct State {
    // 状态由4个元素组成，当前所在格子的坐标以及骰子的顶面和正面
    int x, y, u, f;
    int pre;

    State() {}

    State(int x, int y, int u, int f, int pre) : x(x), y(y), u(u), f(f), pre(pre) {}
} states[10000 + 5];

// 将骰子逆时针转动90度，面向我们的面的数值
void init() {
    die[1][2] = 4;
    die[1][3] = 2;
    die[1][4] = 5;
    die[1][5] = 3;

    die[2][1] = 3;
    die[2][3] = 6;
    die[2][4] = 1;
    die[2][6] = 4;

    die[3][1] = 5;
    die[3][2] = 1;
    die[3][5] = 6;
    die[3][6] = 2;

    die[4][1] = 2;
    die[4][2] = 6;
    die[4][5] = 1;
    die[4][6] = 5;

    die[5][1] = 4;
    die[5][3] = 1;
    die[5][4] = 6;
    die[5][6] = 3;

    die[6][2] = 3;
    die[6][3] = 5;
    die[6][4] = 2;
    die[6][5] = 4;
}

// d是4个滚动方向，上下左右依次编号
void roll(int &vu, int &vf, int d) {
    if (d == 0) {
        int tmp = vf;
        vf = 7 - vu;
        vu = tmp;
    } else if (d == 1) {
        int tmp = vu;
        vu = 7 - vf;
        vf = tmp;
    } else if (d == 2) {
        vu = 7 - die[vu][vf];
    } else if (d == 3) {
        vu = die[vu][vf];
    }
}

typedef pair<int, int> pos;
vector<pos> trace;

// 回溯到起点（将整个经过的pos按照顺序插入trace中）
void dfs(int idx) {
    if (idx == -1) return;
    dfs(states[idx].pre);
    trace.emplace_back(states[idx].x, states[idx].y);
}

void bfs() {
    trace.clear();
    int head = 0, rear = 0;
    states[rear++] = State(sx, sy, u, f, -1);
    memset(vis, 0, sizeof(vis));
    vis[sx][sy][u][f] = 1;
    while (head < rear) {
        State s = states[head++];
        for (int i = 0; i < 4; i++) {
            State s2 = s;
            s2.x += dr[i];
            s2.y += dc[i];
            if (s2.x <= 0 || s2.x > n || s2.y <= 0 || s2.y > m) continue;
            if (maze[s2.x][s2.y] != -1 && s.u != maze[s2.x][s2.y]) continue;
            if (s2.x == sx && s2.y == sy) {
                dfs(head - 1);
                // 最后回到了起点，别忘了将起点也插入到trace中
                trace.emplace_back(sx, sy);
                for (int j = 0; j < (int) trace.size(); j++) {
                    if (j % 9 == 0) printf("\n  ");
                    printf("(%d,%d)%c", trace[j].first, trace[j].second, j == (int) trace.size() - 1 ? '\n' : ',');
                }
                return;
            }
            roll(s2.u, s2.f, i);
            if (vis[s2.x][s2.y][s2.u][s2.f]) continue;
            vis[s2.x][s2.y][s2.u][s2.f] = 1;
            s2.pre = head - 1;
            states[rear++] = s2;
        }
    }
    cout << endl << "  No Solution Possible" << endl;
}

int main() {
    freopen("../ch06/p6-12-data.in", "r", stdin);
    init();
    while (cin >> name && strcmp(name, "END") != 0) {
        cout << name;
        cin >> n >> m >> sx >> sy >> u >> f;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> maze[i][j];
            }
        }
        bfs();
    }
    return 0;
}
