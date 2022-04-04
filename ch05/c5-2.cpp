//
// Created by hliangzhao on 2022/4/3.
//

// TODO：使用参数引用作为函数参数（实参与形参）

#include <iostream>
#include <algorithm>

using namespace std;

// 不叫swap，是为了避免了头文件algorithm中的函数重名
void swap2(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a = 3, b = 4;
    swap2(a, b);
    cout << a << " " << b << endl;
    return 0;
}
