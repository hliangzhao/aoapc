//
// Created by hliangzhao on 2022/4/6.
//

#include <iostream>
#include <set>
#include <map>
#include <cstdio>

using namespace std;

int main() {
    freopen("../ch05/e5-8-data.in", "r", stdin);
    int n, max_len = -10000;
    string input;
    // TODO: 本方法采用set存放字符串，借助了其自动排序的功能。
    //  采用字符串数组也可，可以借助algorithm头文件提供的sort对其排序。
    set<string> s;

    cin >> n;
    while (cin >> input) {
        s.insert(input);
        // TODO: 下面的错误极易犯！input.length()返回的是unsigned long类型，如果不转换为int类型，则-10000会被转换为unsigned和前者进行比较。
        //  因为符号（首位为1）是一个很大的unsigned数字，因此这个if不成立，从而导致max_len无法更新。
        if ((int) input.length() > max_len) {
            max_len = (int) input.length();
        }
    }

    // m存放每一个filename排序之后的编号和对应的filename
    map<int, string> m;
    int i = 0;
    for (const auto &it : s) {
        m[++i] = it;
    }

    for (i = 0; i < max_len * 5 + 8; i++) {
        cout << "-";
    }
    cout << endl;

    int line_num = ((int) s.size() - 1) / 5 + 1;
    // 遍历i和j，编号为i + 4 * j
    for (i = 1; i <= line_num; i++) {
        for (int j = 0;; j++) {
            if (i + 4 * j > n) break;
            cout << m[i + 4 * j];
            // 补充特定数量的空格
            int blank_num = max_len - (int) m[i + 4 * j].length();
            for (int k = 0; k < blank_num; k++) {
                cout << ' ';
            }
            if (j != 4) {
                cout << "  ";
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}