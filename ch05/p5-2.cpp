//
// Created by hliangzhao on 2022/4/8.
//

/* Ducci Sequence */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    freopen("../ch05/p5-2-data.in", "r", stdin);
    int T, n, seq[20];
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            cin >> seq[j];
            sum += seq[j];
        }
        if (sum == 0) {
            cout << "ZERO" << endl;
            continue;
        }
        sum = 0;
        for (int step = 0; step < 1000; step++) {
            // TODO: 注意，第一个数值被修改之后会影响到最后一个数值
            int original_first = seq[0];
            for (int j = 0; j < n - 1; j++) {
                seq[j] = abs(seq[j] - seq[j + 1]);
            }
            seq[n - 1] = abs(seq[n - 1] - original_first);
        }
        for (int j = 0; j < n; j++) {
            sum += seq[j];
        }
        if (sum == 0) {
            cout << "ZERO" << endl;
        } else {
            cout << "LOOP" << endl;
        }
    }
    return 0;
}
