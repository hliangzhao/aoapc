//
// Created by hliangzhao on 2022/3/28.
//

#include <cstdio>

#define LOCAL
#define INF 10000000

void method1() {
    // TODO: 使用文件重定向
#ifdef LOCAL
    // TODO: 将stdin和stdout重定向为文件
    freopen("../ch02/e2-5-data.in", "r", stdin);
    freopen("../ch02/e2-5-data.out", "w", stdout);
#endif
    int x, n = 0, min = INF, max = -INF, sum = 0;
    // TODO: 读取多个输入的方法。scanf函数返回的是成功输入的变量的个数
    while (scanf("%d", &x) == 1) {
        sum += x;
        n++;
        if (x < min) {
            min = x;
        }
        if (x > max) {
            max = x;
        }
    }
    printf("%d %d %.3f\n", min, max, (double) sum / n);
}

void method2() {
    // TODO: 使用文件流（注意，以binary的方式读取）
    FILE *fin, *fout;
    fin = fopen("../ch02/e2-5-data.in", "rb");
    fout = fopen("../ch02/e2-5-data.out", "wb");
    int x, n = 0, min = INF, max = -INF, sum = 0;
    // TODO: 读取多个输入的方法。fscanf函数返回的是成功输入的变量的个数
    while (fscanf(fin, "%d", &x) == 1) {
        sum += x;
        n++;
        if (x < min) {
            min = x;
        }
        if (x > max) {
            max = x;
        }
    }
    fprintf(fout, "%d %d %.3f\n", min, max, (double) sum / n);

    fclose(fin);
    fclose(fout);
}

int main() {
    method2();
    return 0;
}
