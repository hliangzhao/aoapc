//
// Created by hliangzhao on 2022/3/28.
//

#include <cstdio>
#include <cmath>

void method1() {
    double res = 0;
    for (int i = 0; ; i++) {
        double local = 1.0 / (2*i+1);
        if (i % 2 == 0) {
            res += local;
        } else {
            res -= local;
        }
        if (local < 1e-6) {
            break;
        }
    }
    printf("%.6f\n", res);
}

void method2() {
    double res = 0;
    for (int i = 1; ; i++) {
        double local = 1.0 / (2*i-1);
        if (i % 2 == 0) {
            local = -local;
        }
        res += local;
        // TODO: 注意local可能是一个负数了，因此这里需要abs()
        if (abs(local) < 1e-6) {
            break;
        }
    }
    printf("%.6f\n", res);
}

int main() {
    method2();
    return 0;
}
