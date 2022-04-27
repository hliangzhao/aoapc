//
// Created by hliangzhao on 2022/4/27.
//

// TODO: 本题根据先序遍历和中序遍历构建树，并打印后序遍历

#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 256;
string pre_order, in_order;
// 用节点的数值（一个大写字母）的ASCII作为其索引
char lhs[maxn], rhs[maxn];

int n;

char build(int L1, int R1, int L2, int R2) {
    if (L2 > R2) return 0;
    char root = pre_order[L1];
    int p = L2;
    while (in_order[p] != root) p++;
    int cnt = p - L2;
    lhs[root] = build(L1 + 1, L1 + cnt, L2, p - 1);
    rhs[root] = build(L1 + cnt + 1, R1, p + 1, R2);
    return root;
}

void post_order(int u) {
    if (lhs[u] != '\0') {
        post_order(lhs[u]);
    }
    if (rhs[u] != '\0') {
        post_order(rhs[u]);
    }
    printf("%c", u);
}

int main() {
    freopen("../ch06/p6-3-data.in", "r", stdin);
    while (cin >> pre_order) {
        cin >> in_order;
        memset(lhs, 0, sizeof(lhs));
        memset(rhs, 0, sizeof(rhs));
        n = (int) pre_order.length();
        build(0, n - 1, 0, n - 1);
        post_order(pre_order[0]);
        cout << endl;
    }
    return 0;
}

