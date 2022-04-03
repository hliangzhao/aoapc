//
// Created by hliangzhao on 2022/3/28.
//

#include <cstdio>
#include <ctime>

const int MOD = 1000000;

int main() {
    int n, s = 1;
    scanf("%d", &n);
    int tmp = 1;
    for (int i = 2; i <= n; i++) {
        // TODO: 在每一步计算之后就取模，就可以利用"25末尾有6个零"这个结论！
        tmp = tmp * i % MOD;
        s += tmp;
    }
    s %= MOD;
    printf("Time used: %.6f sec\n", (double)clock() / CLOCKS_PER_SEC);
    printf("%d\n", s);
    return 0;
}
