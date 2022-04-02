//
// Created by hliangzhao on 2022/3/30.
//

/* Floating-Point Numbers */

#include <cstdio>
#include <cmath>

#define LOCAL

// TODO：处理思路 —— 全部计算出300种可能的结果，然后根据输入查表

double max_res[10][31], M[10], E[31];

void calculate() {
    for (int i = 0; i < 10; i++) {
        // TODO：例如，(0.1111)_2，它的数值为1-(0.5)^{4+1}
        M[i] = 1 - pow(0.5, i + 1);
    }
    for (int j = 0; j < 31; j++) {
        E[j] = pow(2, j) - 1;
    }
    // TODO：将结果取log后存入数组max_res中，防止溢出（好吧，这个真想不到）
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 31; j++) {
            max_res[i][j] = log10(M[i]) + E[j] * log10(2);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("../ch03/p3-12-data.in", "r", stdin);
#endif
    calculate();
    double A, val;
    int i, j, B;
    char input[30];
    while (scanf("%s", input) == 1) {
        // 将读入的字符串中的e设置为' '，从而方便sscanf的使用
        for (i = 0; ; i++) {
            if (input[i] == 'e') {
                input[i] = ' ';
                break;
            }
        }
        // TODO: 掌握sscanf的使用!（分别匹配A和B并读取）
        sscanf(input, "%lf %d", &A, &B);
        if (A == 0 && B == 0) {
            break;
        }
        val = log10(A) + B;
        // 查表，找到和val相等（最接近）的元素
        int found = 0;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 31; j++) {
                if (fabs(max_res[i][j] - val) < 1e-4) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        printf("%d %d\n", i, j);
    }
    return 0;
}

