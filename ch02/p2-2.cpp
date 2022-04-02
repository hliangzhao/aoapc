//
// Created by hliangzhao on 2022/3/28.
//

/* hanxin */

#include <cstdio>

#define LOCAL

int main() {
    int a, b, c, kase = 1;
#ifdef LOCAL
    freopen("../ch02/p2-2-data.in", "r", stdin);
    freopen("../ch02/p2-2-data.out", "w", stdout);
#endif
    while (scanf("%d", &a) == 1) {
        bool found = false;
        scanf("%d", &b);
        scanf("%d", &c);
        for (int n = 10; n <= 100; n++) {
            if (n % 3 == a && n % 5 == b && n % 7 == c) {
                printf("Case %d: %d\n", kase, n);
                found = true;
                break;
            }
        }
        if (!found) {
            printf("Case %d: No answer\n", kase);
        }
        kase++;
    }
    return 0;
}