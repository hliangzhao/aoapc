//
// Created by hliangzhao on 2022/4/10.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    freopen("../ch05/p5-11-data.in", "r", stdin);
    int T;
    scanf("%d\n", &T);
    while (T--) {
        string d1, d2;
        getline(cin, d1);
        getline(cin, d2);
        // 去掉首尾的花括号
        d1 = d1.substr(1, d1.length() - 2);
        d2 = d2.substr(1, d2.length() - 2);

        map<string, string> dict1, dict2;
        int k;
        string kv, tmp;
        while (!d1.empty()) {
            k = (int) d1.find_first_of(',');
            kv = d1.substr(0, k);
            tmp = d1;
            d1 = d1.substr(k + 1);
            k = (int) kv.find(':');
            dict1[kv.substr(0, k)] = kv.substr(k + 1);
            if (tmp == d1) break;
        }
        while (!d2.empty()) {
            k = (int) d2.find_first_of(',');
            kv = d2.substr(0, k);
            tmp = d2;
            d2 = d2.substr(k + 1);
            k = (int) kv.find(':');
            dict2[kv.substr(0, k)] = kv.substr(k + 1);
            if (tmp == d2) break;
        }

        // 比较dict1和dict2的异同
        // 1: 判断是否有新增键
        set<string> s1;
        for (auto &it2: dict2) {
            int found = 0;
            for (auto &it1: dict1) {
                if (it2.first == it1.first) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                s1.insert(it2.first);
            }
        }
        // 2: 判断是否有删除键
        set<string> s2;
        for (auto &it1: dict1) {
            int deleted = 1;
            for (auto &it2: dict2) {
                if (it1.first == it2.first) {
                    deleted = 0;
                    break;
                }
            }
            if (deleted) {
                s2.insert(it1.first);
            }
        }
        // 3: 判断是否有修改键
        set<string> s3;
        for (auto &it1: dict1) {
            for (auto &it2: dict2) {
                if (it1.first == it2.first && it1.second != it2.second) {
                    s3.insert(it1.first);
                    break;
                }
            }
        }
        int no_change = 1;
        if (!s1.empty()) {
            no_change = 0;
            cout << "+";
            int first = 1;
            for (auto &it: s1) {
                if (first) {
                    cout << it;
                    first = 0;
                } else {
                    cout << "," << it;
                }
            }
            cout << endl;
        }
        if (!s2.empty()) {
            no_change = 0;
            cout << "-";
            int first = 1;
            for (auto &it: s2) {
                if (first) {
                    cout << it;
                    first = 0;
                } else {
                    cout << "," << it;
                }
            }
            cout << endl;
        }
        if (!s3.empty()) {
            no_change = 0;
            cout << "*";
            int first = 1;
            for (auto &it: s3) {
                if (first) {
                    cout << it;
                    first = 0;
                } else {
                    cout << "," << it;
                }
            }
            cout << endl;
        }
        if (no_change) {
            cout << "No changes" << endl;
        }
        cout << endl;
    }
    return 0;
}