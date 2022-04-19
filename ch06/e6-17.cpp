//
// Created by hliangzhao on 2022/4/19.
//

#include <cstdio>
#include <cstring>
#include <cctype>

const int maxn = 200 + 5;
int n;
char tree[maxn][maxn];

void dfs(int r, int c) {
    printf("%c(", tree[r][c]);
    if (r + 1 < n && tree[r + 1][c] == '|') {
        // 存在孩子节点。找到第一个横杠的纵坐标
        int j = c;
        while (j - 1 >= 0 && tree[r + 2][j - 1] == '-') j--;
        // 依次检查每一个横杠下面的元素是否是非空格、换行符，若是，则意味着它是一个节点，递归遍历它
        // 之所以加上"tree[r + 3][j] != '\0'"这个判断是因为横杠的宽度大于全部字符的展开，即横杠下面可能没有字符，已经是\n或者\0了
        while (tree[r + 2][j] == '-' && tree[r + 3][j] != '\0') {
            if (!isspace(tree[r + 3][j])) dfs(r + 3, j);
            j++;
        }
    }
    printf(")");
}

int main() {
    freopen("../ch06/e6-17-data.in", "r", stdin);

    int T;
    fgets(tree[0], maxn, stdin);
    sscanf(tree[0], "%d", &T);
    // TODO: 将T作为int变量直接读进来会导致第二行第一个字符前导空格被忽视！
//    scanf("%d\n", &T);
    while (T--) {
        n = 0;
        for (;;) {
            fgets(tree[n], maxn, stdin);
            if (tree[n][0] == '#') break;
            else n++;
        }
        printf("(");
        if (n) {
            for (int i = 0; i < strlen(tree[0]); i++) {
                if (tree[0][i] != ' ') {
                    dfs(0, i);
                    break;
                }
            }
        }
        printf(")\n");
    }
}