//
// Created by hliangzhao on 2022/4/3.
//

#include <cstdio>

#define EPS 1e-4

int main() {
    double f;
    for (f = 2; f > 1; f -= 1e-6);
    // TODO: 以下部分的输出：
    //  0.9999990（正确答案应当是1.0000000）
    //  0.2499998
    //  0.2（正确答案应当是0.25四舍五入得0.3）
    //  也就是说，浮点数在不断减去一个小数的时候出现了误差，是的循环终止时f不为1
    printf("%.7f\n", f);
    printf("%.7f\n", f / 4);
    printf("%.1f\n", f / 4);

    // TODO: 通过加上一个小数来缓解这个问题
    printf("%.1f\n", f / 4 + EPS);
    return 0;
}
