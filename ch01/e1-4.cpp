//
// Created by hliangzhao on 2022/3/27.
//

#include <cstdio>

int main() {
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    y = (m - 2*n) / 2;
    x = n - y;
    // TODO: 逻辑运算符都是短路运算符
    if (m % 2 == 1 || y < 0 || x < 0) {
        printf("No answer\n");
        return 0;
    }
    printf("%d %d\n", x, y);
    return 0;
}
