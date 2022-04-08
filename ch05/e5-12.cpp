//
// Created by hliangzhao on 2022/4/8.
//

#include <iostream>
#include <algorithm>

using namespace std;

// TODO: 反思 —— 目前仍然缺乏结构体和类的思想，想不到为之创建结构体和重载比较运算符，从而导致代码冗长。

const int maxn = 100 + 5;

struct Building {
    int id;
    int x, y, w, d, h;

    // TODO: 这个比较运算符的重载用于给Building进行排序
    bool operator<(const Building &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
} b[maxn];

int e512_n;                         // building num
double e512_x[maxn * 2];            // 用于离散化

// TODO: 判断位置mx是否横跨building i
bool cover(int i, double mx) {
    return b[i].x <= mx && b[i].x + b[i].w >= mx;
}

// TODO: 判断building i是否在位置mx可见
bool visible(int i, double mx) {
    if (!cover(i, mx)) return false;
    for (int k = 0; k < e512_n; k++) {
        if (cover(k, mx) && b[k].y < b[i].y && b[k].h >= b[i].h) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("../ch05/e5-12-data.in", "r", stdin);
    int kase = 0;
    while (cin >> e512_n && e512_n) {
        for (int i = 0; i < e512_n; i++) {
            cin >> b[i].x >> b[i].y >> b[i].w >> b[i].d >> b[i].h;
            e512_x[i * 2] = b[i].x;
            e512_x[i * 2 + 1] = b[i].x + b[i].w;
            b[i].id = i + 1;
        }
        sort(b, b + e512_n);
        sort(e512_x, e512_x + 2 * e512_n);
        // TODO: 两个要点
        //  (1) unique函数要在sort之后使用；
        //  (2) unique函数返回的是去重之后的尾元素的地址，因此这个差值就是去重之后的元素个数。
        //      这里的「去重」只是将重复元素移到了容器的末尾。
        long m = unique(e512_x, e512_x + 2 * e512_n) - e512_x;

        if (kase++) {
            cout << endl;
        }
        cout << "For map #" << kase << ", the visible buildings are numbered as follows:\n" << b[0].id;
        for (int i = 1; i < e512_n; i++) {
            bool is_visible = false;
            for (int j = 0; j < m - 1; j++) {
                double mx = (e512_x[j] + e512_x[j + 1]) / 2;
                if (visible(i, mx)) {
                    is_visible = true;
                    break;
                }
            }
            if (is_visible) {
                cout << " " << b[i].id;
            }
        }
        cout << endl;
    }
    return 0;
}
