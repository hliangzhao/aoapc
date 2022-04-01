//
// Created by hliangzhao on 2022/3/31.
//

// TODO: 将数组作为函数参数的几种正确写法

#include <cstdio>

int sum_of_arr1(int *a, int len) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        res += a[i];
    }
    return res;
}

int sum_of_arr2(int *start, int *end) {
    int res = 0;
    for (int i = 0; i < end - start; i++) {
        res += start[i];
    }
    return res;
}

int sum_of_arr3(int *start, int *end) {
    int res = 0;
    for (int *p = start; p != end; p++) {
        res += *p;
    }
    return res;
}

// TODO：int *a这个参数和int a[]是等价的
int sum_of_arr_err(int *a) {
    int res = 0;
    // TODO：仅仅输入数组首地址是无法通过sizeof得知数组大小的
    for (int i = 0; i < sizeof(a); i++) {
        res += a[i];
    }
    return res;
}

int main() {
    return 0;
}