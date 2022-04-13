//
// Created by hliangzhao on 2022/4/13.
//

// TODO: 使用数组构造双向链表

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 5;

int left[maxn], right[maxn];

// 将元素L和R链接起来
void link(int L, int R) {
    right[L] = R;
    left[R] = L;
}

int main() {
    freopen("../ch06/e6-5-data.in", "r", stdin);
    int n, m, kase = 0;
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) {
            left[i] = i - 1;                    // 当 i = 1时，左边元素为0，即没有元素
            right[i] = (i + 1) % (n + 1);       // 当 i = n时，右边元素为0，即没有元素
        }
        // 设置边界（构成了一个循环双向链表）
        right[0] = 1;
        left[0] = n;

        int op, X, Y, inv = 0;
        while (m--) {
            scanf("%d", &op);
            if (op == 4) inv = !inv;
            else {
                scanf("%d %d", &X, &Y);
                // TODO: 并不需要真正在双向链表中交换这两个元素，只需要先"标记"以下，
                //  注意它会对op1和op2产生影响
                if (op == 3 && right[Y] == X) {
                    swap(X, Y);
                }
                // TODO: inv对op1和op2的影响是使他们的作用效果相互交换了
                if (op != 3 && inv) {
                    op = 3 - op;
                }
                if (op == 1 && X == left[Y]) continue;
                if (op == 2 && X == right[Y]) continue;

                int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
                if (op == 1) {
                    link(LX, RX);
                    link(LY, X);
                    link(X, Y);
                } else if (op == 2) {
                    link(LX, RX);
                    link(Y, X);
                    link(X, RY);
                } else if (op == 3) {
                    if (right[X] == Y) {
                        link(LX, Y);
                        link(Y, X);
                        link(X, RY);
                    } else {
                        link(LX, Y);
                        link(Y, RX);
                        link(LY, X);
                        link(X, RY);
                    }
                }
            }
        }

        int b = 0;
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            b = right[b];
            if (i % 2 == 1) {
                res += b;
            }
        }
        // TODO: 若是奇数个元素，则inv不会有影响；
        //  若是偶数个，inv有影响。
        if (inv && n % 2 == 0) {
            res = (long long) n * (n + 1) / 2 - res;
        }
        printf("Case %d: %lld\n", ++kase, res);
    }
    return 0;
}
