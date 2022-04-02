//
// Created by hliangzhao on 2022/3/30.
//

/* Crossword Answers */

#include <cstdio>
#include <cstring>

#define LOCAL

const int max_r = 15, max_c = 15, max_words_num = 80;

bool is_start(int i, int j, int r, int c, char grid[max_r][max_c]) {
    if (i < 0 || i >= r || j < 0 || j >= c) {
        return false;
    }
    if (grid[i][j] == '*') {
        return false;
    }
    if (j - 1 < 0 || i - 1 < 0) {
        return true;
    }
    if (grid[i - 1][j] == '*' || grid[i][j - 1] == '*') {
        return true;
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("../ch03/p3-6-data.in", "r", stdin);
#endif
    char grid[max_r][max_c];
    char across_words[max_words_num][max_c], down_words[max_words_num][max_r];
    memset(across_words, '\0', sizeof(across_words));
    memset(down_words, '\0', sizeof(down_words));

    int r, c;
    // 读取数据
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", grid[i]);
    }

    // 检查每一个位子是否为起始格，若是，找到自此开始的横向单词
    printf("Across words:\n");
    int across_words_num = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (is_start(i, j, r, c, grid)) {
//                printf("%d %d\n", i, j);
                int k = j;
                while (k < c && grid[i][k] != '*') {
                    across_words[across_words_num][k - j] = grid[i][k];
                    k++;
                }
                across_words_num++;
            }
        }
    }

    for (int k = 0; k < across_words_num; k++) {
        for (int p = 0; p < strlen(across_words[k]); p++) {
            putchar(across_words[k][p]);
        }
        printf("\n");
    }

    printf("\n");

    // 检查每一个位子是否为起始格，若是，找到自此开始的纵向单词
    printf("Down words:\n");
    int down_words_num = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (is_start(i, j, r, c, grid)) {
                int k = i;
                while (k < r && grid[k][j] != '*') {
                    down_words[down_words_num][k - i] = grid[k][j];
                    k++;
                }
                down_words_num++;
            }
        }
    }

    for (int k = 0; k < down_words_num; k++) {
        for (int p = 0; p < strlen(down_words[k]); p++) {
            putchar(down_words[k][p]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

