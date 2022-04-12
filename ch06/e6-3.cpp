//
// Created by hliangzhao on 2022/4/12.
//

#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <cctype>

using namespace std;

// TODO: 简单的表达式可以通过栈来完成。

const int maxn = 26;

int rows[maxn], cols[maxn];

int main() {
    freopen("../ch06/e6-3-data.in", "r", stdin);
    int n;
    char var;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%c", &var);
        scanf("%d %d\n", &rows[var - 'A'], &cols[var - 'A']);
    }

    string in_str;
    while (getline(cin, in_str)) {
        stack<vector<int>> s;
        int res = 0, error = 0;
        for (char &i : in_str) {
            if (isalpha(i)) {
                vector<int> v;
                v.push_back(rows[i - 'A']);
                v.push_back(cols[i - 'A']);
                s.push(v);
            } else if (i == ')') {
                vector<int> sec = s.top();
                s.pop();
                vector<int> fir = s.top();
                s.pop();
                if (fir[1] != sec[0]) {
                    printf("error\n");
                    error = 1;
                    break;
                } else {
                    res += fir[0] * fir[1] * sec[1];
                    vector<int> v;
                    v.push_back(fir[0]);
                    v.push_back(sec[1]);
                    s.push(v);
                }
            }
        }
        if (!error) {
            if (!s.empty()) {
                printf("%d\n", res);
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}