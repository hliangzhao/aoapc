//
// Created by hliangzhao on 2022/4/12.
//

#include <iostream>
#include <stack>

using namespace std;

// TODO: 使用栈

const int maxn = 100;

int main() {
    freopen("../ch06/e6-2-data.in", "r", stdin);
    int n;
    while (scanf("%d\n", &n) && n) {
        while (true) {
            // 读取一行排列存入seq
            int seq[maxn];
            scanf("%d", &seq[0]);
            if (seq[0] == 0) break;
            for (int i = 1; i < n; i++) {
                scanf("%d", &seq[i]);
            }
            scanf("\n");

            stack<int> s;
            int in_num = 0, out_idx = 0, ok = 1;
            s.push(++in_num);
            while (!s.empty()) {
                if (s.top() != seq[out_idx]) {
                    if (in_num <= n) {
                        s.push(++in_num);
                    } else {
                        printf("No\n");
                        ok = 0;
                        break;
                    }
                } else {
                    s.pop();
                    out_idx++;
                };
            }
            if (ok) {
                printf("Yes\n");
            }
        }
        printf("\n");
    }
    return 0;
}
