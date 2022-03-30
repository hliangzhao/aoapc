//
// Created by hliangzhao on 2022/3/30.
//

/* Puzzle */

#include <cstdio>
#include <cstring>

#define LOCAL

void illegal() {
    printf("This puzzle has no final configuration.\n");
}

int main() {
#ifdef LOCAL
    freopen("../p3-5-data.in", "r", stdin);
#endif
    // TODO: 这里如果不将maxn申明为const，二维数组申明会报错！
    const int maxn = 5, config_len = 80;
    char grid[maxn + 1][maxn + 1], config[config_len];

    memset(grid, '\0', sizeof(grid));
    memset(config, '\0', sizeof(config));

    for (int i = 0; i < maxn; i++) {
        scanf("%s", grid[i]);
    }
    scanf("%s", config);

    // 找到空格的位置
    int x, y;
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            if (grid[i][j] == '*') {
                x = i;
                y = j;
            }
        }
    }

    // 执行指令
    for (int k = 0; k < strlen(config); k++) {
        char move = config[k];
        if (move == '0') break;
        if (move == 'A') {
            if (x - 1 < 0) {
                illegal();
                return 0;
            }
            grid[x][y] = grid[x - 1][y];
            grid[x - 1][y] = '*';
            x -= 1;
        } else if (move == 'B') {
            if (x + 1 >= maxn) {
                illegal();
                return 0;
            }
            grid[x][y] = grid[x + 1][y];
            grid[x + 1][y] = '*';
            x += 1;
        } else if (move == 'L') {
            if (y - 1 < 0) {
                illegal();
                return 0;
            }
            grid[x][y] = grid[x][y - 1];
            grid[x][y - 1] = '*';
            y -= 1;
        } else {
            if (y + 1 >= maxn) {
                illegal();
                return 0;
            }
            grid[x][y] = grid[x][y + 1];
            grid[x][y + 1] = '*';
            y += 1;
        }
    }

    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}

