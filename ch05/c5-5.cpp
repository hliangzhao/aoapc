//
// Created by hliangzhao on 2022/4/4.
//

// TODO: 模版
//  就做竞赛题而言，对模版的了解到可以理解STL的程度即可

#include <iostream>

using namespace std;

// TODO：模版方法
template<typename T>
T sum(T *begin, T *end) {
    T ans = 0;
    for (T *p = begin; p != end; p++) {
        ans = ans + *p;
    }
    return ans;
}

struct MyPoint2 {
    double x, y;

    MyPoint2(double x = 0, double y = 0) {
        this->x = x;
        (*this).y = y;
    }
};

MyPoint2 operator+(const MyPoint2 &a, const MyPoint2 &b) {
    return {a.x + b.x, a.y + b.y};
}

ostream &operator<<(ostream &out, const MyPoint2 &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

int main() {
    double a[] = {1.1, 2.2, 3.3};
    cout << sum(a, a + 3) << endl;

    MyPoint2 ps[] = {MyPoint2(1, 2), MyPoint2(3, 4)};
    cout << sum(ps, ps + 2) << endl;

    return 0;
}
