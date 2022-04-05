//
// Created by hliangzhao on 2022/4/4.
//

#include <algorithm>
#include <cstdio>

using namespace std;

const int e5_1_size = 1000;

int main() {
    freopen("../ch05/e5-1-data.in", "r", stdin);
    int n, q, kase = 0;
    int a[e5_1_size], b[e5_1_size];
    while (scanf("%d %d\n", &n, &q) == 2 && n) {
        printf("CASE# %d:\n", ++kase);
        for (int i = 0; i < n - 1; i++) {
            scanf("%d ", &a[i]);
        }
        scanf("%d\n", &a[n - 1]);
        for (int i = 0; i < q - 1; i++) {
            scanf("%d ", &b[i]);
        }
        scanf("%d\n", &b[q - 1]);

        // TODO：使用algorithm头文件提供的sort函数对数组进行排序
        sort(a, a + n);
        for (int i = 0; i < q; i++) {
            // 依次检查每一个查询
//            int found = 0;
//            for (int j = 0; j < n; j++) {
//                if (b[i] == a[j]) {
//                    found = 1;
//                    printf("%d found at %d\n", b[i], j + 1);
//                    break;
//                }
//            }
//            if (!found) {
//                printf("%d not found\n", b[i]);
//            }
            // TODO: 使用algorithm头文件提供的lower_bound函数查找大于等于给定数值的第一个元素的位置。
            //  因此，这个函数适合对已经排好序的数组使用。
            int pos = lower_bound(a, a+n, b[i]) - a;
            if (a[pos] == b[i]) {
                printf("%d found at %d\n", b[i], pos + 1);
            } else {
                printf("%d not found\n", b[i]);
            }
        }
    }
    return 0;
}
