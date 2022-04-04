//
// Created by hliangzhao on 2022/4/4.
//

// TODO: 结构体、构造函数与运算符重载

#include <iostream>

using namespace std;

struct MyPoint {
    double x, y;

    // TODO：带有默认值和成员列表的构造函数
//    MyPoint(double x = 0, double y = 0) : x(x), y(y) {}
    // TODO：使用this（一个指向当前对象实例的指针）实现构造函数内部细节
    MyPoint(double x = 0, double y = 0) {
        this->x = x;
        (*this).y = y;
    }
};

// TODO: 加法运算符重载（参数是引用的形式）
//  Type operator+(const Type &a, const Type &b) {}
//  Type operator-(const Type &a, const Type &b) {}
//  Type operator*(const Type &a, const Type &b) {}
//  Type operator/(const Type &a, const Type &b) {}
MyPoint operator+(const MyPoint &a, const MyPoint &b) {
    return MyPoint(a.x + b.x, a.y + b.y);
}

MyPoint operator/(const MyPoint &a, const MyPoint &b) {
    return MyPoint(a.x / b.x, a.y / b.y);
}

// TODO: 流运算符重载（参数是引用的形式）
//  ostream &operator<<(ostream &out, const Type &a) {}
ostream &operator<<(ostream &out, const MyPoint &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

int main() {
    MyPoint a, b(1, 2);
    a.x = 3;
    cout << a + b << endl;
    return 0;
}