//
// Created by hliangzhao on 2022/4/1.
//

#include <cstdio>
#include <cstring>

#define LOCAL

// TODO: my_method()这个方法没有实现完！
void my_method() {
#ifdef LOCAL
    freopen("../ch04/e4-5-data-1.in", "e4_5_r", stdin);
#endif
    int r, c, table[55][55];
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &table[i][j]);
        }
    }

    int op_num;
    char op[10][20];
    scanf("%d\n", &op_num);    // 为了防止下面的fgets读取出现问题，这里把换行符也读进来，但是不保存它
    for (int i = 0; i < op_num; i++) {
        fgets(op[i], 20, stdin);
    }

    int query_num, query_x, query_y;
    scanf("%d", &query_num);
    for (int i = 0; i < query_num; i++) {
        scanf("%d %d", &query_x, &query_y);
        // 追踪(query_x, query_y)在经过了这些操作之后的新位置
        for (int j = 0; j < op_num; j++) {
            if (op[j][0] == 'E') {
                // 交换单元格操作。将被交换的位置读出来和query位置进行比较
                int pos1_x, pos1_y, pos2_x, pos2_y;
                sscanf(op[j], "%d %d %d %d", &pos1_x, &pos1_y, &pos2_x, &pos2_y);
                if (pos1_x == query_x && pos1_y == query_y) {
                    query_x = pos2_x;
                    query_y = pos2_y;
                }
                if (pos2_x == query_x && pos2_y == query_y) {
                    query_x = pos1_x;
                    query_y = pos1_y;
                }
            }
            if (op[j][0] == 'D') {
                if (op[j][1] == 'R') {
                    // 删除行操作
                    int A;
                    sscanf(op[j], "%d", &A);
                    // TODO：这里如何读取出后面的各个数字成为了一个难题

                }
                if (op[j][1] == 'C') {
                    // 删除列操作
                    int A;
                    sscanf(op[j], "%d", &A);
                    // TODO：这里如何读取出后面的各个数字成为了一个难题
                }
            }
            if (op[j][0] == 'I') {
                if (op[j][1] == 'R') {
                    // 增加行操作
                    int A;
                    sscanf(op[j], "%d", &A);
                    // TODO：这里如何读取出后面的各个数字成为了一个难题
                }
                if (op[j][1] == 'C') {
                    // 增加列操作
                    int A;
                    sscanf(op[j], "%d", &A);
                    // TODO：这里如何读取出后面的各个数字成为了一个难题
                }
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////
/// 下面给出的是书本上提供的方法1，即完全模拟每一个操作，更新每一个操作后的表格，最后找到原始查询单元格的新位置

#define maxd1 100
#define BIG 10000

int e4_5_r, e4_5_c, e4_5_n, e4_5_d[maxd1][maxd1], e4_5_d2[maxd1][maxd1], e4_5_ans[maxd1][maxd1], e4_5_affected[maxd1];

// 将table d2的第q行（或列）拷贝到table d的第p行（或列）
void copy(char type, int p, int q) {
    if (type == 'R') {
        // 将d2的第q行copy到d的第p行
        for (int i = 1; i <= e4_5_c; i++) {
            e4_5_d[p][i] = e4_5_d2[q][i];
        }
    } else {
        // 将d2的第q列copy到d的第p列
        for (int i = 1; i <= e4_5_r; i++) {
            e4_5_d[i][p] = e4_5_d2[i][q];
        }
    }
}

void del(char type) {
    // 首先将当前的数组d拷贝一份赋值给d2
    memcpy(e4_5_d2, e4_5_d, sizeof(e4_5_d));
    int cnt = type == 'R' ? e4_5_r : e4_5_c, cnt2 = 0;
    for (int i = 1; i <= cnt; i++) {
        // 对于每一行（或列），如果这个行（或列）没有被操作，则将它原封不动地拷贝到当前数组d中
        if (!e4_5_affected[i]) {
            copy(type, ++cnt2, i);
        }
    }
    // 更新当前数组在经过删除操作之后的行（或列）的个数
    if (type == 'R') {
        e4_5_r = cnt2;
    } else {
        e4_5_c = cnt2;
    }
}

void ins(char type) {
    memcpy(e4_5_d2, e4_5_d, sizeof(e4_5_d));
    int cnt = type == 'R' ? e4_5_r : e4_5_c, cnt2 = 0;
    for (int i  =1; i <= cnt; i++) {
        if (e4_5_affected[i]) {
            copy(type, ++cnt2, i);
        }
    }
    if (type == 'R') {
        e4_5_r = cnt2;
    } else {
        e4_5_c = cnt2;
    }
}

void book_method1() {
    int r1, c1, r2, c2, q, kase = 0;
    char cmd[10];
    memset(e4_5_d, 0, sizeof(e4_5_d));
    // 多个测试用例
    while (scanf("%d%d%d", &e4_5_r, &e4_5_c, &e4_5_n) == 3 && e4_5_r) {
        int r0 = e4_5_r, c0 = e4_5_c;
        // 初始化table
        for (int i = 1; i <= e4_5_r; i++) {
            for (int j = 1; j <= e4_5_c; j++) {
                e4_5_d[i][j] = i * BIG + j;
            }
        }
        // 读取每一个指令
        while (e4_5_n--) {
            scanf("%s", cmd);
            if (cmd[0] == 'E') {
                scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
                int t = e4_5_d[r1][c1];
                e4_5_d[r1][c1] = e4_5_d[r2][c2];
                e4_5_d[r2][c2] = t;
            } else {
                // TODO: 书上给出的方法是依次读取各个位置、而非一次性读取进来再去拆分出各个部分。这显然是一个更好的方法
                int a, x;
                scanf("%d", &a);
                memset(e4_5_affected, 0, sizeof(e4_5_affected));
                for (int i = 0; i < a; i++) {
                    scanf("%d", &x);
                    e4_5_affected[x] = 1;
                }
                if (cmd[0] == 'D') {
                    del(cmd[1]); // 删除e4_5_affected所标记的行或列
                } else {
                    ins(cmd[1]); // 插入e4_5_affected所标记的行或列
                }
            }
        }

        memset(e4_5_ans, 0, sizeof(e4_5_ans));
        for (int i = 1; i <= e4_5_r; i++) {
            for (int j = 1; j <= e4_5_c; j++) {
                // TODO: (e4_5_d[i][j] / BIG, e4_5_d[i][j] % BIG)是经过操作之后、存放i * BIG + j这个数的新位置
                //  这个地方理解起来似乎有点问题？
                e4_5_ans[e4_5_d[i][j] / BIG][e4_5_d[i][j] % BIG] = i * BIG + j;
            }
        }
        if (kase > 0) {
            printf("\n");
        }
        printf("Spreadsheet #%d\n", ++kase);

        // 依次处理每一个查询
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d", &r1, &c1);
            printf("Cell data in (%d,%d) ", r1, c1);
            if (e4_5_ans[r1][c1] == 0) {
                printf("GONE\n");
            } else {
                printf("moved to (%d,%d)\n", e4_5_ans[r1][c1] / BIG, e4_5_ans[r1][c1] % BIG);
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////
/// 下面给出的是书本上提供的方法2，和我的想法相同，即对于每个查询，追踪它在一系列操作之后的新位置，但是不需要真的修改表格
/// 基于这种策略，连table本身我们都不需要维护了。

#define maxd2 10000

// TODO: 在定义结构体的同时声明一个对应的数组
struct Command {
    char c[5];
    int r1, c1, r2, c2;
    int a, x[20];
} cmd2[maxd2];

int e4_5_r2, e4_5_c2, e4_5_n2;

int simulate(int *r0, int *c0) {
    // 依次检查每一个操作对输入的坐标的影响
    for (int i = 0; i < e4_5_n2; i++) {
        if (cmd2[i].c[0] == 'E') {
            if (cmd2[i].r1 == *r0 && cmd2[i].c1 == *c0) {
                *r0 = cmd2[i].r2;
                *c0 = cmd2[i].c2;
            }
            if (cmd2[i].r2 == *r0 && cmd2[i].c2 == *c0) {
                *r0 = cmd2[i].r1;
                *c0 = cmd2[i].c1;
            }
        } else {
            // 比较被移动的行列编号和给定坐标之间的大小关系，从而决定新坐标是加还是减
            int dr = 0, dc = 0;
            for (int j = 0; j < cmd2[i].a; j++) {
                int x = cmd2[i].x[j];
                if (cmd2[i].c[0] == 'I') {
                    // 只有当新增的行或列编号小于给定坐标时，才会发生坐标变化
                    if (cmd2[i].c[1] == 'R' && x <= *r0) dr++;
                    if (cmd2[i].c[1] == 'C' && x <= *c0) dc++;
                } else {
                    if (cmd2[i].c[1] == 'R' && x == *r0) return 0;
                    if (cmd2[i].c[1] == 'C' && x == *c0) return 0;
                    if (cmd2[i].c[1] == 'R' && x < *r0) dr--;
                    if (cmd2[i].c[1] == 'C' && x < *c0) dc--;
                }
            }
            *r0 += dr;
            *c0 += dc;
        }
    }
    return 1;
}

void book_method2() {
    int r0, c0, q, kase = 0;
    while (scanf("%d%d%d", &e4_5_r2, &e4_5_c2, &e4_5_n2) == 3 && e4_5_r2) {
        for (int i = 0; i < e4_5_n2; i++) {
            // TODO: 书上给出的方法是依次读取各个位置、而非一次性读取进来再去拆分出各个部分。这显然是一个更好的方法
            scanf("%s", cmd2[i].c);
            if (cmd2[i].c[0] == 'E') {
                scanf("%d%d%d%d", &cmd2[i].r1, &cmd2[i].c1, &cmd2[i].r2, &cmd2[i].c2);
            } else {
                scanf("%d", &cmd2[i].a);
                for (int j = 0; j < cmd2[i].a; j++) {
                    scanf("%d", &cmd2[i].x[j]);
                }
            }
        }
        if (kase > 0) {
            printf("\n");
        }
        printf("Spreadsheet #%d\n", ++kase);

        scanf("%d", &q);
        while (q--) {
            scanf("%d%d", &r0, &c0);
            printf("Cell data in (%d,%d) ", r0, c0);
            if (!simulate(&r0, &c0)) {
                printf("GONE\n");
            } else {
                printf("moved to (%d,%d)\n", r0, c0);
            }
        }
    }
}

int main() {
    book_method2();
    return 0;
}