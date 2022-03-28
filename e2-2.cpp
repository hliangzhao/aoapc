//
// Created by hliangzhao on 2022/3/28.
//

#include <cstdio>

int main() {
    int n, s = 0;
    scanf("%d", &n);
    // TODO: 本题的输入n <= 10^9，只比int上限小一点点，因此需要转换为long long类型来存储计算，避免3*n+1时溢出。
    long long n2 = n;
    while (n2 != 1) {
        if (n2 % 2 == 1) {
            n2 = 3 * n2 + 1;
            s++;
        } else {
            n2 = n2 / 2;
            s++;
        }
    }
    printf("%d\n", s);
    return 0;
}
