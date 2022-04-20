//
// Created by hliangzhao on 2022/4/20.
//

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 5;
const double W = 1000.0;

int n, vis[maxn];
double x[maxn], y[maxn], r[maxn];
double left, right;
bool ok;

// 判断两个敌人的攻击范围是否交叉
bool intersect(int c1, int c2) {
    return sqrt(pow(x[c1] - x[c2], 2) + pow(y[c1] - y[c2], 2)) < r[c1] + r[c2];
}

// 题目没有对进入战场的点的高度做要求
void check_circle(int c) {
    // 该圆和左边界相交，求出两个交点中更低的那个交点的高度（y值）
    if (x[c] - r[c] < 0) {
        left = min(left, y[c] - sqrt(pow(r[c], 2) - pow(x[c], 2)));
    }
    // 该圆和右边界相交，求出两个交点中更低的那个交点的高度（y值）
    if (x[c] + r[c] > W) {
        right = min(right, y[c] - sqrt(pow(r[c], 2) - pow(W - x[c], 2)));
    }
}

// 从北到南通过dfs判断是否存在一条连通南北的「踏脚石道路」
bool dfs(int c) {
    if (vis[c]) return false;
    vis[c] = 1;
    // 和下边界相交
    if (y[c] - r[c] < 0) return true;
    for (int v = 0; v < n; v++) {
        if (intersect(c, v) && dfs(v)) return true;
    }
    // 如果这一条「踏脚石道路」是和左边界或者右边界相交的，那么就更新left和right
    // TODO: 这里最牛的地方在于，dfs是从和上边界相交的圆开始遍历的，如果左右边界最上面的圆不和上边界相交，
    //  则left和right不会被更新，即从高度为1000进入，从高度为1000出去！
    check_circle(c);
    return false;
}

int main() {
    freopen("../ch06/e6-22-data.in", "r", stdin);
    while (scanf("%d", &n) == 1) {
        ok = true;
        // 最低高度为顶端
        left = right = W;
        memset(vis, 0, sizeof(vis));
        for (int c = 0; c < n; c++) {
            scanf("%lf%lf%lf", &x[c], &y[c], &r[c]);
        }
        for (int c = 0; c < n; c++) {
            if (y[c] + r[c] >= W && dfs(c)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            printf("0.00 %.2lf 1000.00 %.2lf\n", left, right);
        }
    }
    return 0;
}
