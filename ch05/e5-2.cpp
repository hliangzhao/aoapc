//
// Created by hliangzhao on 2022/4/4.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// TODO: 关于vector的使用：
//  (1) 首先，需要引入#include <vector>；
//  (2) 使用clear()清空，resize()改变大小；
//  (3) 使用push_back()和pop_back()从末尾插入和删除元素；
//  (4) 使用empty()测试是否为空。
//  (5) vector之间可以直接赋值，vector也可以作为函数的返回值（一等公民）。

const int max_blocks_num = 100;
vector<int> e5_2_x[max_blocks_num];
int e5_2_n;

// 从vec数组中找到编号为e的木块
void find_block(int e, int &pos, int &height) {
    for (pos = 0; pos < max_blocks_num; pos++) {
        for (height = 0; height < e5_2_x[pos].size(); height++) {
            if (e5_2_x[pos][height] == e) {
                return;
            }
        }
    }
}

// 将第pos个vec中高度为h的木块上方的所有的木块移除
void clear_above(int pos, int height) {
    int moved_num = (int) e5_2_x[pos].size() - height - 1;
    while (moved_num--) {
        e5_2_x[pos].pop_back();
    }
}

// 将第pos个vec高度为height的木块上方的木块归位
void clear_above_and_move_back(int pos, int height) {
    for (int i = height + 1; i < e5_2_x[pos].size(); i++) {
        int block_num = e5_2_x[pos][i];
        e5_2_x[block_num].push_back(block_num);
    }
    e5_2_x[pos].resize(height + 1);
}

// 将第pos1个vec中高度为h的木块及其上方的全部木块整体放到第pos2个vec上方
void pile_onto(int pos1, int height, int pos2) {
    for (int i = height; i < e5_2_x[pos1].size(); i++) {
        e5_2_x[pos2].push_back(e5_2_x[pos1][i]);
    }
    clear_above(pos1, height - 1);
}

int main() {
    freopen("../ch05/e5-2-data.in", "r", stdin);

    cin >> e5_2_n;
    for (int i = 0; i < e5_2_n; i++) {
        e5_2_x[i].push_back(i);
    }

    string act, prep;
    int a, b;
    while (cin >> act >> a >> prep >> b) {
        if (act == "quit") {
            break;
        }

        int pos_a, height_a, pos_b, height_b;
        find_block(a, pos_a, height_a);
        find_block(b, pos_b, height_b);
        if (pos_a == pos_b) continue;    // 非法指令直接忽略

        if (act == "move") {
            if (prep == "onto") {
                // move onto
                clear_above(pos_a, height_a - 1);  // 从a开始的元素，全部要被移除
                clear_above(pos_b, height_b);
                e5_2_x[pos_b].push_back(a);
            } else {
                // move over
                clear_above(pos_a, height_a - 1);  // 从a开始的元素，全部要被移除
                e5_2_x[pos_b].push_back(a);
            }
        } else {
            if (prep == "onto") {
                // pile onto
                clear_above(pos_b, height_b);
                pile_onto(pos_a, height_a, pos_b);
            } else {
                // pile over
                pile_onto(pos_a, height_a, pos_b);
            }
        }
    }

    for (int i = 0; i < e5_2_n; i++) {
        cout << i << ":";
        // 遍历vec元素并打印
        for (int j : e5_2_x[i]) {
            cout << " " << j;
        }
        cout << endl;
    }

    return 0;
}