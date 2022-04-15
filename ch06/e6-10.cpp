//
// Created by hliangzhao on 2022/4/15.
//

#include <iostream>

using namespace std;

const int maxn = 1000;
int sum[maxn];

void build(int p) {
    int v;
    cin >> v;
    if (v == -1) return;
    sum[p] += v;
    build(p - 1);
    build(p + 1);
}

bool init() {
    int v;
    cin >> v;
    if (v == -1) return false;
    memset(sum, 0, sizeof(sum));
    int pos = maxn / 2;
    sum[pos] = v;
    build(pos - 1);
    build(pos + 1);
    return true;
}

int main() {
    freopen("../ch06/e6-10-data.in", "r", stdin);
    int kase = 0;
    while (init()) {
        int p = 0;
        // 只要对应的元素不为0，则意味着该水平位置上有数值，打印即可
        while (sum[p] == 0) {
            p++;
        }
        cout << "Case " << ++kase << ":\n" << sum[p++];
        while (sum[p] != 0) {
            cout << " " << sum[p++];
        }
        cout << endl << endl;
    }
    return 0;
}