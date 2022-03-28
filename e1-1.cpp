//
// Created by hliangzhao on 2022/3/27.
//

#include <cstdio>
#include <cmath>

int main() {
    // TODO: 使用const申明常数pi，使用acos(-1.0)计算pi
    const double pi = acos(-1.0);
    double r, h;
    scanf("%lf %lf", &r, &h);
    double s = 2 * pi * r * h + 2 * pi * r *r;
    printf("Area = %.3f\n", s);
    return 0;
}