//
// Created by hliangzhao on 2022/4/4.
//

// TODO: 模版

#include <iostream>

using namespace std;

// TODO：模版结构体
template<typename T>
struct MyPoint3 {
    T x, y;

    MyPoint3(T x = 0, T y = 0) {
        this->x = x;
        this->y = y;
    }
};

template<typename T>
MyPoint3<T> operator+(const MyPoint3<T> &a, const MyPoint3<T> &b) {
    return MyPoint3<T>(a.x + b.x, a.y + b.y);
}

template<typename T>
ostream &operator<<(ostream &out, const MyPoint3<T> &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

int main() {
    MyPoint3<int> a(1, 2), b(3, 4);
    MyPoint3<double> c(1.1, 2.2), d(3.3, 4.4);
    cout << a + b << " " << c + d << endl;
    return 0;
}

