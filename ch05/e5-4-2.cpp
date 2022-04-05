//
// Created by hliangzhao on 2022/4/5.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

// TODO：书本的方法 —— 结合map和vector

map<string, int> e542_word_cnt;
vector<string> e542_words;

// 将字符串转换为lower并排序
// TODO: 这里的const修饰的是字符串本身还是字符串的地址？
string repr(const string &s) {
    string ans = s;
    for (char &c: ans) {
        c = (char) tolower(c);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    freopen("../ch05/e5-4-data.in", "r", stdin);
    string s;
    while (cin >> s) {
        if (s[0] == '#') break;
        e542_words.push_back(s);
        string r = repr(s);
        if (!e542_word_cnt.count(r)) {
            e542_word_cnt[r] = 0;
        }
        e542_word_cnt[r]++;
    }
    vector<string> ans;
    for (const auto &w: e542_words) {
        if (e542_word_cnt[repr(w)] == 1) {
            ans.push_back(w);
        }
    }
    sort(ans.begin(), ans.end());
    for (const auto &w: ans) {
        cout << w << endl;
    }

    return 0;
}
