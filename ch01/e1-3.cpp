//
// Created by hliangzhao on 2022/3/27.
//

#include <cstdio>

void method1() {
    int a, b;
    scanf("%d %d", &a, &b);
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    printf("%d %d\n", a, b);
}

void method2() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", b, a);   // TODO: 打印满足要求的输出。解决问题最重要
}

int main() {
    method2();
    return 0;
}
