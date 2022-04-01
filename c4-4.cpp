//
// Created by hliangzhao on 2022/3/31.
//

#include <cstdio>
#include <cmath>

int is_prime(int n) {
    if (n <= 1) return 0;
    // TODO: 有一个小因子，就必然有一个与之对应的大因子，因此只需要判断前半部分是否存在因子即可
    //  注意求整数平方根的写法！
    int m = floor(sqrt(n) + 0.5);
    for (int i = 2; i <= m; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    for (int n = 1; n <= 200; n++) {
        if (is_prime(n)) {
            printf("%d ", n);
        }
    }
    return 0;
}