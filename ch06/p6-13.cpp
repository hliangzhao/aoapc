//
// Created by hliangzhao on 2022/4/28.
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// TODO: 未完成

struct Pos {
    int r, c;

    Pos(int r = 0, int c = 0) : r(r), c(c) {}
};

const int maxn = 20 + 5;
int spread[maxn][maxn];
bool already_set[maxn][maxn];
vector<Pos> express[maxn][maxn];
int R, C;           // 行列都从0开始编号

int get_row_idx(char c) {
    return c - 'A';
}

int get_col_idx(char c) {
    return c - '0';
}

bool is_number(const string &s) {
    for (auto c: s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool str2num(const string &s) {
    int num = 0;
    for (auto c: s) {
        num = num * 10 + (c - '0');
    }
    return num;
}

int main() {
    while (cin >> R >> C && R && C) {
        memset(spread, 0, sizeof(spread));
        memset(already_set, false, sizeof(already_set));
        string line;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> line;
                if (is_number(line)) {
                    spread[i][j] = str2num(line);
                    already_set[i][j] = true;
                } else {
                    stringstream ss(line);
                    char c;
                    ss >> c;
                    int r1 = get_row_idx(c);
                    ss >> c;
                    int c1 = get_col_idx(c);
                    express[i][j].emplace_back(r1, c1);
                    char sign;
                    while (ss >> sign) {
                        ss >> c;
                        r1 = get_row_idx(c);
                        ss >> c;
                        c1 = get_col_idx(c);
                        if (sign == '+') {
                            express[i][j].emplace_back(r1, c1);
                        } else {
                            express[i][j].emplace_back(-r1, -c1);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
