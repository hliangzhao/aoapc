//
// Created by hliangzhao on 2022/4/3.
//

// TODO：C++流

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int c5_1_maxn = 100 + 10;
int c5_1_A[c5_1_maxn];

int main() {
    freopen("../ch05/c5-1-data.in", "r", stdin);
    long long a, b;
    // TODO: 浮点数不会被读入到a和b中
    while (cin >> a >> b) {
        cout << min(a, b) << endl;
    }
    return 0;
}