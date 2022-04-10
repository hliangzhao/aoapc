//
// Created by hliangzhao on 2022/4/5.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

// TODO：我的方法 —— 结合map和set
//  set和map都支持insert、erase、count、find操作，后者还支持[]运算符。

map<string, int> word_cnt;
map<string, string> word_shadow;

int main() {
    freopen("../ch05/e5-4-data.in", "r", stdin);
    string line, word, revised_word;
    while (getline(cin, line)) {
        if (line == "#") {
            break;
        }
        stringstream ss(line);
        while (ss >> word) {
            revised_word = word;
            // 转换为小写
            for (char &c: revised_word) {
                if (isupper(c)) {
                    c = (char) tolower(c);
                }
            }
            // TODO：直接使用algorithm提供的sort对string自身进行排序
            sort(revised_word.begin(), revised_word.end());
            // 存入map中
            word_shadow[revised_word] = word;
            // TODO：如果一个k-v不在map中，则对应的v为默认零值
            if (word_cnt[revised_word] == 0) {
                word_cnt[revised_word] = 1;
            } else {
                word_cnt[revised_word]++;
            }
        }
    }

    set<string> tmp;
    for (auto &it : word_cnt) {
        // TODO：map使用first和second标识kv
        if (it.second == 1) {
            tmp.insert(word_shadow[it.first]);
        }
    }
    // 借助set自带的排序功能首先按序打印
    for (auto &it: tmp) {
        cout << it << endl;
    }

    return 0;
}
