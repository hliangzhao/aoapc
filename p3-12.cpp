//
// Created by hliangzhao on 2022/3/30.
//

/* Floating-Point Numbers */

#include <cstdio>
#include <cmath>

int main() {
    double res = 0;
    for (int i = 1; i <= 9; i++) {
        res += 1.0 / pow(2, i);
    }
    printf("%.10lf\n", res);
    return 0;
}

