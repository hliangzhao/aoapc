//
// Created by hliangzhao on 2022/4/3.
//
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

// TODO: 题目 —— 输入多行，每行给出不定数量的非负整数，计算每行之和并打印。

void cpp_method() {
    string line;
    // TODO：使用getline直接读取一行内容到字符串中
    while (getline(cin, line)) {
        int sum = 0, x;
        // TODO：创建一个字符串流，然后从字符串中读取出想要的变量值（和sscanf类似）
        stringstream ss(line);
        while (ss >> x) {
            sum += x;
        }
        cout << sum << endl;
    }
}

void c_method() {
    int sum = 0, val = 0;
    // TODO: C语言的getchar写法。不断读入字符，根据它是换行符、EOF、空格还是数字进行相应的处理。
    //  如果输入有小数、负数，则处理起来会更加麻烦，这个时候C++中的getline和stringstream的组合的优势就反应出来了
    while (true) {
        int ch = getchar();
        if (ch == EOF) {
            break;
        }
        if (ch == '\n' || ch == '\r') {
            // 输出结果并重置变量
            printf("%d\n", sum + val);
            val = 0;
            sum = 0;
            continue;
        }
        if (ch != ' ') {
            val = val * 10 + (char) ch - '0';
        } else {
            sum += val;
            val = 0;
        }
    }
}

int main() {
    freopen("../ch05/c5-3-data.in", "r", stdin);
    c_method();
    return 0;
}
