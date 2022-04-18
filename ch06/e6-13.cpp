//
// Created by hliangzhao on 2022/4/18.
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// TODO: 这道题非常有意思，刘老板的处理也非常聪明！

// 01矩阵的最大大小
const int max_height = 200 + 5;
const int max_width = 50 * 4 + 5;

// 01矩阵的实际大小
int H, W;

// pic存放01矩阵、color用于标识每个位置的颜色（背景颜色编号为1、连通的线条、白色的洞依次往下编号）
int pic[max_height][max_width];
int color[max_height][max_width];

// 存放每一行读入的十六进制字符串
char line[max_width];

// 存放每一个十六进制的字符到二进制串的映射
// 第一维度之所以是256，是因为我们直接用char隐式转换为int作为index，而ASCII码中有256个字符。
char hex2bin[256][5];

void set_hex2bin() {
    strcpy(hex2bin['0'], "0000");
    strcpy(hex2bin['1'], "0001");
    strcpy(hex2bin['2'], "0010");
    strcpy(hex2bin['3'], "0011");
    strcpy(hex2bin['4'], "0100");
    strcpy(hex2bin['5'], "0101");
    strcpy(hex2bin['6'], "0110");
    strcpy(hex2bin['7'], "0111");
    strcpy(hex2bin['8'], "1000");
    strcpy(hex2bin['9'], "1001");
    strcpy(hex2bin['a'], "1010");
    strcpy(hex2bin['b'], "1011");
    strcpy(hex2bin['c'], "1100");
    strcpy(hex2bin['d'], "1101");
    strcpy(hex2bin['e'], "1110");
    strcpy(hex2bin['f'], "1111");
}

// 将输入的十六进制矩阵转换为01矩阵存入pic
void decode(char ch, int r, int c) {
    for (int i = 0; i < 4; i++) {
        pic[r][c + i] = hex2bin[ch][i] - '0';
    }
}

// 这两个数组组合起来用于遍历一个位置上下左右的四个位置
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

// 基于dfs标记01矩阵中每个位置的编号
// 本函数是递归调用。从本函数的递归调用栈中彻底退出时，所有和位置(r,c)颜色应该相同的位置都被标记好了正确的颜色编号
void dfs(int r, int c, int clr) {
    color[r][c] = clr;
    for (int i = 0; i < 4; i++) {
        int r2 = r + dr[i];
        int c2 = c + dc[i];
        // TODO：dfs的条件 —— 位置(r2, c2)合法、该位置没有被探索过、且该位置和(r, c)数字一致（要么同为0、要么同为1）
        //  满足这3个条件的位置才和本位置属于同一个颜色
        if (r2 >= 0 && r2 < H && c2 >= 0 && c2 < W && pic[r][c] == pic[r2][c2] && color[r2][c2] == 0) {
            dfs(r2, c2, clr);
        }
    }
}

// neighbors是一个vector，大小为输入的pic中不同的颜色的个数
// 对于每个颜色，用一个set记录与其接壤（相邻）的其他颜色的个数
vector<set<int>> neighbors;

// 按照白色洞（连通块）的个数来排序（0-5）6个象形文字
const char *code = "WAKJSD";

int main() {
    set_hex2bin();
    int kase = 0;

    while (scanf("%d%d", &H, &W) == 2 && H) {
        // 读取十六进制矩阵转换为01矩阵存入pic中
        memset(pic, 0, sizeof(pic));
        for (int i = 0; i < H; i++) {
            scanf("%s", line);
            for (int j = 0; j < W; j++) {
                // 这里字符从位置(1,1)开始写入
                decode(line[j], i + 1, j * 4 + 1);
            }
        }

        // TODO：这里行列都+2，是为了将整个图扩展1圈（padding one empty line/column）
        //  从而保证白色背景的color编号为1（第1种颜色）
        H += 2;
        W = W * 4 + 2;

        int cnt = 0;
        // TODO: cc存放了符号（黑色线条）的颜色编号。因此，cc的大小等于pic中字符的个数。
        //  以我在书p165绘制的图为例，cc中存放了2、4、5
        vector<int> cc;
        memset(color, 0, sizeof(color));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (!color[i][j]) {
                    // 基于dfs探索每个没有探索过的位置
                    dfs(i, j, ++cnt);
                    if (pic[i][j] == 1) {
                        cc.push_back(cnt);
                    }
                }
            }
        }

        neighbors.clear();
        neighbors.resize(cnt + 1);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (pic[i][j] == 1) {
                    // 对于每一个黑线（黑线连在一起组成一个符号），判断它的邻居
                    for (int k = 0; k < 4; k++) {
                        int r2 = i + dr[k];
                        int c2 = j + dc[k];
                        // color的编号为1意味这这个位置属于背景板，与我们要找的白色洞没有关系。因此要去掉
                        if (r2 >= 0 && r2 < H && c2 >= 0 && c2 < W && pic[r2][c2] == 0 && color[r2][c2] != 1) {
                            // 以我在书p165绘制的图为例，有
                            // neighbors[element = 2] = {3}
                            // neighbors[element = 4] = {}
                            // neighbors[element = 5] = {6, 7}
                            neighbors[color[i][j]].insert(color[r2][c2]);
                        }
                    }
                }
            }
        }

        // 用白色洞的个数来决定它属于哪一个符号，然后按照字母顺序输出
        vector<char> ans;
        for (int i : cc) {
            int white_block_num = (int) neighbors[i].size();
            ans.push_back(code[white_block_num]);
        }
        // 将识别出来的字符按照字母表顺序排序输出
        sort(ans.begin(), ans.end());

        printf("Case %d: ", ++kase);
        for (char c : ans) {
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}
