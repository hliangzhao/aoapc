//
// Created by hliangzhao on 2022/4/9.
//

#include <iostream>
#include <set>
#include <cstdio>
#include <cmath>

using namespace std;

const double eps = 1e-4;

struct p56_Point {
    double x, y;

    bool operator==(const p56_Point rhs) const {
        return abs(this->x - rhs.x) < eps && abs(this->y - rhs.y) < eps;
    }

    // TODO: 小于运算符必须要被重载，否则本结构体无法作为set的元素
    bool operator<(const p56_Point rhs) const {
        if (this->x < rhs.x) {
            return true;
        }
        if (this->y < rhs.y) {
            return true;
        }
        return false;
    }
};


p56_Point mirror(p56_Point p, double x) {
    p56_Point new_p{p.x, p.y};
    new_p.x = 2 * x - p.x;
    return new_p;
}

int main() {
    freopen("../ch05/p5-6-data.in", "r", stdin);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        set<p56_Point> s;
        int x, y;
        double middle_x = 0;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            s.insert(p56_Point{(double) x, (double) y});
            middle_x += x;
        }
        middle_x /= n;
        int ok = 1;
        for (auto &it: s) {
            p56_Point tmp = mirror(it, middle_x);
            int found = 0;
            for (auto &it2: s) {
                if (it2 == tmp) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
