//
// Created by hliangzhao on 2022/4/8.
//

/* Foreign Exchange */

#include <iostream>
#include <map>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 500000 + 5;
int A[maxn], B[maxn];


int main() {
    freopen("../ch05/p5-4-data.in", "r", stdin);
    int n;
    while (cin >> n && n) {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        for (int i = 0; i < n; i++) {
            int fir, sec;
            cin >> fir >> sec;
            A[fir] = sec;
            B[sec] = fir;
        }
        int ok = 1;
        for (int i = 1; i < maxn; i++) {
            int j = A[i];
            if (B[i] != j) {
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
