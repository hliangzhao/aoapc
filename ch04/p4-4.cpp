//
// Created by hliangzhao on 2022/4/3.
//

/* Cube painting */

#include <cstdio>
#include <cstring>

int main() {
    int seq[10][6] = {{1, 6, 2, 5, 3, 4},  // TODO: 新的观察顺序
                      {1, 6, 3, 4, 5, 2},  // TODO: 沿着上下轴依次逆时针旋转90度、180度、270度
                      {1, 6, 5, 2, 4, 3},
                      {1, 6, 4, 3, 2, 5},
                      {4, 3, 2, 5, 1, 6},  // TODO: 沿着前后轴依次逆时针旋转90度、180度、270度
                      {6, 1, 2, 5, 4, 3},
                      {3, 4, 2, 5, 6, 1},
                      {5, 2, 1, 6, 3, 4},  // TODO: 沿着左右轴依次逆时针旋转90度、180度、270度
                      {6, 1, 5, 2, 3, 4},
                      {2, 5, 6, 1, 3, 4}};
    char in[15], s1[10], s2[10], s1_new[10], s2_new[10];
    memset(s1, '\0', sizeof(s1));
    memset(s2, '\0', sizeof(s2));
    memset(s1_new, '\0', sizeof(s1_new));
    memset(s2_new, '\0', sizeof(s2_new));

    scanf("%s", in);
    for (int i = 0; i < 6; i++) {
        s1[i] = in[i];
    }
    for (int i = 0; i < 6; i++) {
        s2[i] = in[i + 6];
    }
    for (int i = 0; i < 6; i++) {
        s1_new[i] = s1[seq[0][i] - 1];
        s2_new[i] = s2[seq[0][i] - 1];
    }
    if (strcmp(s1_new, s2_new) == 0) {
        printf("True\n");
        return 0;
    }
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 6; j++) {
            // 计算s1的新序列
            s1_new[j] = s1[seq[i][j] - 1];
        }
        if (strcmp(s1_new, s2_new) == 0) {
            printf("True\n");
            return 0;
        }
    }
    printf("False\n");
    return 0;
}
