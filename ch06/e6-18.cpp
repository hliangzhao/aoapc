//
// Created by hliangzhao on 2022/4/20.
//

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 50 + 5;
const int maxc = 1000 + 5;

int n;
// (x0,y0,z0) 和 (x1,y1,z1) 分别是距离原点最近的点和该点对角线上的点
int x0[maxn], y0[maxn], z0[maxn];
int x1[maxn], y1[maxn], z1[maxn];

// TODO: 存储？
int nx, ny, nz;
// 存放离散化后每一个小方块的xyz坐标值
int xs[maxn * 2], ys[maxn * 2], zs[maxn * 2];

// 每一个小方块周围的6个方块（用于floodfill）
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};
// 整个立方体网格的大小为100 * 100 * 100
int color[maxn * 2][maxn * 2][maxn * 2];

// Cell定位一个特定的小方块
struct Cell {
    int x, y, z;

    explicit Cell(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    bool valid() const {
        return x >= 0 && x < nx - 1 && y >= 0 && y < ny - 1 && z >= 0 && z < nz - 1;
    }

    bool solid() const {
        return color[x][y][z] == 1;
    }

    bool get_vis() const {
        return color[x][y][z] == 2;
    }

    void set_vis() const {
        color[x][y][z] = 2;
    }

    Cell neighbor(int dir) const {
        return Cell(x + dx[dir], y + dy[dir], z + dz[dir]);
    }

    // 在以下两个计算表面积和体积的函数中，我们使用原始坐标

    int volume() const {
        return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
    }

    // 各个朝向的面积（因此有三个）
    int area(int dir) const {
        if (dx[dir] != 0) {
            return (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
        } else if (dy[dir] != 0) {
            return (xs[x + 1] - xs[x]) * (zs[z + 1] - zs[z]);
        } else {
            return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]);
        }
    }
};

// n是数组x中互不相同的元素的个数
void discretize(int *arr, int &len) {
    sort(arr, arr + len);
    n = (int) (unique(arr, arr + len) - arr);
}

// 找到元素p在排好序的数组arr中的index
int id(int *arr, int len, int p) {
    return (int) (lower_bound(arr, arr + len, p) - arr);
}

// 找到所有由空气组成的连通块
void floodfill(int &v, int &s) {
    v = 0;          // 记录空气的体积
    s = 0;          // 记录雕塑的外表面积
    Cell c;
    c.set_vis();
    queue<Cell> q;
    q.push(c);

    while (!q.empty()) {
        Cell c = q.front();
        q.pop();
        v += c.volume();
        for (int i = 0; i < 6; i++) {
            Cell c2 = c.neighbor(i);
            if (!c2.valid()) {
                continue;
            }
            if (c2.solid()) {
                s += c.area(i);
            } else if (!c2.get_vis()) {
                c2.set_vis();
                q.push(c2);
            }
        }
    }

    // 得到雕塑的体积
    v = maxc * maxc * maxc - v;
}

int main() {
    freopen("../ch06/e6-18-data.in", "r", stdin);

    int T;
    scanf("%d", &T);
    while (T--) {
        nx = ny = nz = 2;
        xs[0] = ys[0] = zs[0] = 0;
        xs[1] = ys[1] = zs[1] = maxc;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d%d%d", &x0[i], &y0[i], &z0[i], &x1[i], &y1[i], &z1[i]);
            x1[i] += x0[i];
            y1[i] += y0[i];
            z1[i] += z0[i];

            xs[nx++] = x0[i];
            xs[nx++] = x1[i];

            ys[ny++] = y0[i];
            ys[ny++] = y1[i];

            zs[nz++] = z0[i];
            zs[nz++] = z1[i];
        }
        discretize(xs, nx);
        discretize(ys, ny);
        discretize(zs, nz);

        memset(color, 0, sizeof(color));
        for (int i = 0; i < n; i++) {
            int X1 = id(xs, nx, x0[i]), X2 = id(xs, nx, x1[i]);
            int Y1 = id(ys, ny, y0[i]), Y2 = id(ys, ny, y1[i]);
            int Z1 = id(zs, nz, z0[i]), Z2 = id(zs, nz, z1[i]);
            for (int X = X1; X < X2; X++) {
                for (int Y = Y1; Y < Y2; Y++) {
                    for (int Z = Z1; Z < Z2; Z++) {
                        color[X][Y][Z] = 1;
                    }
                }
            }
        }

        int v, s;
        floodfill(v, s);
        printf("%d %d\n", s, v);
    }
    return 0;
}
