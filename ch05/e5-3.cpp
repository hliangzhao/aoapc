//
// Created by hliangzhao on 2022/4/5.
//

#include <iostream>
#include <set>
#include <cstdio>
#include <sstream>

using namespace std;

// TODO：使用set
//  set有insert、erase等方法。

set<string> dict;

int main() {
    freopen("../ch05/e5-3-data.in", "r", stdin);
    string line, word;
    // TODO: cin >> line读取一个被空格、tab、换行符等分割的字符串，
    //  就本题目而言，它和getline(cin, line)的效果一致
//    while (cin >> line) {
    while (getline(cin, line)) {
        for (int i = 0; i < line.length(); i++) {
            // do sth.
        }
        // TODO: 使用新的loop写法简化代码
        for (char &c : line) {
            if (isalpha(c)) {
                c = (char) tolower(c);
            } else {
                c = ' ';
            }
        }
        stringstream ss(line);
        while (ss >> word) {
            dict.insert(word);
        }
    }
//    for (set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
//        cout << *it << endl;
//    }
    // TODO: 使用const auto简化代码
    for (const auto &it : dict) {
        cout << it << endl;
    }
    return 0;
}