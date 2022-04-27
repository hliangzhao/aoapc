//
// Created by hliangzhao on 2022/4/27.
//

#include <cstdio>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    freopen("../ch06/p6-1-data.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        bool ok = true;
        string line;
        cin >> line;
        stack<char> s;
        for (char c: line) {
            if (c == '(' || c == '[') {
                s.push(c);
            } else {
                if (s.empty()) {
                    ok = false;
                    break;
                }
                if (c == ')') {
                    char t = s.top();
                    if (t != '(') {
                        ok = false;
                        break;
                    } else {
                        s.pop();
                    }
                } else if (c == ']') {
                    char t = s.top();
                    if (t != '[') {
                        ok = false;
                        break;
                    } else {
                        s.pop();
                    }
                }
            }
        }
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
