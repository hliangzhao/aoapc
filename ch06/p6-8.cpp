//
// Created by hliangzhao on 2022/4/28.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 64 + 5;
int pic[maxn][maxn];
vector<int> black_nodes;

// 指定区域是否全白
bool white(int r, int c, int w) {
    for (int i = r; i < r + w; i++) {
        for (int j = c; j < c + w; j++) {
            if (pic[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

// 指定区域是否全黑
bool black(int r, int c, int w) {
    for (int i = r; i < r + w; i++) {
        for (int j = c; j < c + w; j++) {
            if (pic[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

// dir有NW, NE, SW, SE，分别取值1 2 3 4
void build(int depth, int dir, int res, int r, int c, int w) {
    if (!w) return;                 // 空树
    if (white(r, c, w)) return;     // 空树
    if (black(r, c, w)) {           // 叶子结点
        res += dir * int(pow(5, depth - 1));
        black_nodes.push_back(res);
        return;
    }
    // 中间节点
    res += dir * int(pow(5, depth - 1));
    depth++;
    build(depth, 1, res, r, c, w / 2);
    build(depth, 2, res, r, c + w / 2, w / 2);
    build(depth, 3, res, r + w / 2, c, w / 2);
    build(depth, 4, res, r + w / 2, c + w / 2, w / 2);
}

// 每次把叶子结点对应的区域描黑即可
void tree2pic(int r, int c, int w, int src) {
    int dir;
    if (src) {
        dir = src % 5;
        src /= 5;
        if (dir == 1) {
            tree2pic(r, c, w / 2, src);
        } else if (dir == 2) {
            tree2pic(r, c + w / 2, w / 2, src);
        } else if (dir == 3) {
            tree2pic(r + w / 2, c, w / 2, src);
        } else if (dir == 4) {
            tree2pic(r + w / 2, c + w / 2, w / 2, src);
        }
        // TODO: 为什么dir会出现非1～4的结果？
//        else
//            tree2pic(r + w / 2, c + w / 2, w / 2, src);
//        }
    } else {
        // 抵达叶子结点
        for (int i = r; i < r + w; i++) {
            for (int j = c; j < c + w; j++) {
                pic[i][j] = 1;
            }
        }
    }
}

int main() {
    freopen("../ch06/p6-8-data.in", "r", stdin);
    int kase = 0;
    int n;
    while (cin >> n) {
//        fill(pic[0], pic[0] + maxn * maxn, 0);
        memset(pic, 0, sizeof(pic));
        if (n == 0) break;
        if (kase) cout << endl;
        if (n > 0) {
            // pic --> tree
            black_nodes.clear();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    char c;
                    cin >> c;
                    pic[i][j] = c - '0';
                }
            }
            build(0, 0, 0, 0, 0, n);
            sort(black_nodes.begin(), black_nodes.end());
            cout << "Image " << ++kase;
            for (int i = 0; i < black_nodes.size(); i++) {
                if (i % 12 == 0) {
                    cout << endl;
                    cout << black_nodes[i];
                } else {
                    cout << " " << black_nodes[i];
                }
            }
            cout << endl;
            cout << "Total number of black nodes = " << black_nodes.size() << endl;
        } else {
            // tree --> pic
            n = -n;
            int src = 0;
            while (src != -1) {
                cin >> src;
                tree2pic(0, 0, n, src);
            }
            cout << "Image " << ++kase << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (pic[i][j] == 0) {
                        cout << '.';
                    } else {
                        cout << '*';
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
