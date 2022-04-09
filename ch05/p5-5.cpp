//
// Created by hliangzhao on 2022/4/9.
//

#include <iostream>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    freopen("../ch05/p5-5-data.in", "r", stdin);
    vector<string> dict;
    set<string> set_dict, compounded;
    string s;
    while (cin >> s) {
        dict.push_back(s);
        set_dict.insert(s);
    }
    for (int i = 0; i < dict.size(); i++) {
        for (int j = 0; j < dict.size(); j++) {
            if (i != j) {
                string c = dict[i] + dict[j];
                if (set_dict.count(c)) {
                    cout << c << endl;
                }
            }
        }
    }
    return 0;
}