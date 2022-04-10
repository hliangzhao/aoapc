//
// Created by hliangzhao on 2022/4/8.
//

/* Alignment of Code */

#include <iostream>
#include <sstream>

using namespace std;

const int max_n = 1000 + 5;
const int max_m = 180 + 5;

string p51_code[max_n][max_m];
int max_len[max_m];

int main() {
    freopen("../ch05/p5-1-data.in", "r", stdin);
    int line_num = 0, max_col_num = -1;
    string line, token;
    while (getline(cin, line)) {
        int col_num = 0;
        stringstream ss(line);
        while (ss >> token) {
            p51_code[line_num][col_num++] = token;
        }
        if (col_num > max_col_num) {
            max_col_num = col_num;
        }
        line_num++;
    }

    // 求每一列最宽的字符串宽度
    for (int j = 0; j < max_col_num; j++) {
        int max_len_of_j = -1;
        for (int i = 0; i < line_num; i++) {
            if ((int) p51_code[i][j].length() > max_len_of_j) {
                max_len_of_j = (int) p51_code[i][j].length();
            }
        }
        max_len[j] = max_len_of_j;
    }

    for (int i = 0; i < line_num; i++) {
        // 依次输出本列的每一个元素
        for (int j = 0; j < max_col_num; j++) {
            int cur_len = (int) p51_code[i][j].length();
            int space_num = max_len[j] - cur_len;
            cout << p51_code[i][j];
            if (p51_code[i][j + 1].empty()) {
                printf("\n");
                break;
            } else {
                for (int k = 0; k < space_num + 1; k++) {
                    printf(" ");
                }
            }
        }

    }
    return 0;
}
