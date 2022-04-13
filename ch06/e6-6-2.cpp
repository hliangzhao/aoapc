//
// Created by hliangzhao on 2022/4/13.
//

#include <cstdio>
#include <cstring>

const int max_depth = 20;
const int max_idx = 1 << max_depth;

int main() {
    freopen("../ch06/e6-6-data.in", "r", stdin);
    int D, I;
    while (scanf("%d %d", &D, &I) == 2) {
        // TODO：这种解法节省了大量的计算过程，并且减免了大数组的开销
        int k = 1;
        for (int i = 0; i < D - 1; i++) {
            if (I % 2 == 1) {
                // 是奇数，则必然往左走。是走过左子树跟节点的第(I + 1) / 2个元素
                k = 2 * k;
                I = (I + 1) / 2;
            } else {
                // 是偶数，是走过右子树的第I / 2个元素
                k = 2 * k + 1;
                I = I / 2;
            }
        }
        printf("%d\n", k);
    }
    return 0;
}
