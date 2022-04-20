//
// Created by hliangzhao on 2022/4/20.
//

// TODO：把标号（52种）看成节点，正方形（的拼接）看作边，则得到一个有向图。当且仅当图中存在有向环的时候有解。
//  这里采用DFS实现拓扑排序。

#include <cstdio>
#include <cstring>

int G[52][52];
int c[52];

// 按照A+、A-、B+、B-...的顺序从0开始编号
int get_id(char a1, char a2) {
    return (a1 - 'A') * 2 + (a2 == '+' ? 0 : 1);
}

// 把标号看成点，正方形看成边，如果一个点和另一个正方形的一个点有链接的话，那么可以看成「这个点和另一个正方形的剩下三个点之间有有向边」，
// 所以我们可以建立一个有向图，然后找有没有环。建边时，一个点的编号异或1之后可以与这个正方形其他点建边。
void connect(char a1, char a2, char b1, char b2) {
    if (a1 == '0' || b1 == '0') return;
    int u = get_id(a1, a2) ^ 1;         // "a1a2"只被翻转末位，即X+变成X-、X-变成X+（X取A到Z）
    int v = get_id(b1, b2);
    G[u][v] = 1;
}

// 基于DFS判断是否存在从u出发的回路
bool dfs(int u) {
    c[u] = -1;
    for (int v = 0; v < 52; v++) {
        if (G[u][v]) {
            if (c[v] < 0) return true;
            else if (!c[v] && dfs(v)) return true;
        }
    }
    c[u] = 1;
    return false;
}

// 从任意节点出发，判断是否存在回路
bool find_cycle() {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < 52; i++) {
        if (!c[i]) {
            if (dfs(i)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    freopen("../ch06/e6-19-data.in", "r", stdin);
//    for (char a1 = 'A'; a1 <= 'Z'; a1++) {
//        printf("%d %d\n", get_id(a1, '+'), get_id(a1, '+') ^ 1);
//        printf("%d %d\n", get_id(a1, '-'), get_id(a1, '-') ^ 1);
//    }
    int n;
    while (scanf("%d", &n) == 1 && n) {
        memset(G, 0, sizeof(G));
        while (n--) {
            char s[10];
            scanf("%s", s);
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (i != j) {
                        connect(s[i * 2], s[i * 2 + 1], s[j * 2], s[j * 2 + 1]);
                    }
                }
            }
        }
        if (find_cycle()) {
            printf("unbounded\n");
        } else {
            printf("bounded\n");
        }
    }
    return 0;
}
