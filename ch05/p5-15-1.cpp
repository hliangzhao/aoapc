//
// Created by hliangzhao on 2022/4/10.
//

/* Revenge of Fibonacci */

// TODO: 本代码有问题！

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> p515_v;

int main() {
    freopen("../ch05/p5-15-data.in", "r", stdin);

    p515_v.emplace_back("1");
    p515_v.emplace_back("1");
    string res;
    // TODO: unsigned long long仍然会溢出，看来只有使用大整数类了
    unsigned long long i = 2, a = 1, b = 1, tmp;
    while (i < 100000) {
        stringstream ss;
        ss << a + b;
        ss >> res;
        cout << res.length() << endl;
        p515_v.push_back(res);

        tmp = b;
        b = a;
        a += tmp;
        i++;
    }

    int T, kase = 1;
    scanf("%d\n", &T);
    string line;
    while (T--) {
        cout << "Case #" << kase++ << ": ";
        int found = 0;
        cin >> line;
        for (i = 0; i < p515_v.size(); i++) {
            if (p515_v[i].rfind(line, 0) != string::npos) {
                found = 1;
                cout << i << endl;
                break;
            }
        }
        if (!found) {
            cout << "-1" << endl;
        }
    }
    return 0;
}