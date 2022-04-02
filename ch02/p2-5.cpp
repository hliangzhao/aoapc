//
// Created by hliangzhao on 2022/3/28.
//

/* decimal */

#include <cstdio>

// TODO: 这个程序有bug，因为它无法考虑到不断向前进位的场景。
//  测试用例：1694 10000 3。
//  这需要修改前面已经记录的数字，因此这里需要（借助数组等）暂存下来，修改后再打印输出。

int main() {
    int a, b, c, kase = 1;
    while (scanf("%d %d %d", &a, &b, &c) == 3 && (a || b || c)) { // a、b、c不同时为零即合法
        printf("Case %d: %d", kase++, a / b); // TODO: 先输出整数部分
        if (c > 0) {
            printf(".");
        }
        int k = a;
        // TODO: 输出前c-1个小数
        for (int i = 1; i < c; i++) {
            k = (k % b) * 10;
            printf("%d", k / b);
        }
        k = (k % b) * 10;
        int d = k / b;                      // TODO: d记录的是第c个小数
        int e = (k % b) * 10 / b;           // TODO: e记录的是第c+1个小数
        if (e >= 5) {
            printf("%d\n", d + 1);          // 判断d分位的数字是否需要加1
        } else {
            printf("%d\n", d);
        }
    }
    return 0;
}