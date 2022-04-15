//
// Created by hliangzhao on 2022/4/15.
//

#include <iostream>

using namespace std;

// TODO: 题目的输入采取了递归方式定义。因此直接编写一个递归过程进行输入比较。
//  在输入的同时直接完成判断。
bool solve(int &W) {
    int Wl, Dl, Wr, Dr;
    bool bl = true, br = true;
    cin >> Wl >> Dl >> Wr >> Dr;
    // TODO: 如果Wl是0，则直接递归，结果要为true才行
    if (!Wl) {
        bl = solve(Wl);
    }
    // TODO: 如果Wr是0，则直接递归，结果要为true才行
    if (!Wr) {
        br = solve(Wr);
    }
    // TODO: 本身重量为两端之和
    W = Wl + Wr;
    return bl && br && (Wl * Dl == Wr * Dr);
}

int main() {
    freopen("../ch06/e6-9-data.in", "r", stdin);
    int T, W;
    cin >> T;
    while (T--) {
        if (solve(W)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        if (T) {
            cout << endl;
        }
    }
    return 0;
}
