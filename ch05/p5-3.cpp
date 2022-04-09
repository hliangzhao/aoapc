//
// Created by hliangzhao on 2022/4/8.
//

/* Throwing cards away */

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        while (q.size() >= 2) {
            cout << q.front() << endl;
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << endl;
    }
    return 0;
}
