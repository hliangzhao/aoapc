//
// Created by hliangzhao on 2022/3/31.
//

#include <cstdio>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swap_err1(int *a, int *b) {
    // TODO: 这样写存在风险。这是因为t是一个在函数内申明的指针，在使用前无法知晓其所在的内存单元是否是可以写入的
    int *t;
    int *p = 0; // TODO: 将零地址赋值给变量显然是不被允许的！
    *t = *a;
    *a = *b;
    *b = *t;
}

void swap_err2(int *a, int *b) {
    // TODO: 需要交换的，不是地址，而是指针所指向的元素
    int *t = a;
    a = b;
    b = t;
}

int main() {
    int a = 3, b = 4;
    swap(&a, &b);
    printf("%d %d\n", a, b);

    swap_err1(&a, &b);
    printf("%d %d\n", a, b);

    swap_err2(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}
