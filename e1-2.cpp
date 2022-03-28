//
// Created by hliangzhao on 2022/3/27.
//

#include <cstdio>

void method1();
void method2();

int main() {
    method2();
    return 0;
}

void method1() {
    int n;
    scanf("%d", &n);
    printf("%d%d%d\n", n % 10, n / 10 % 10, n / 100);
}

void method2() {
    int n;
    scanf("%d", &n);
    // TODO: 留出宽度为3，前端补0
    printf("%03d\n", (n%10)*100 + (n/10%10)*10 + n/100);
}