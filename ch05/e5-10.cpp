//
// Created by hliangzhao on 2022/4/7.
//

#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

const int INF = 100000;

int main() {
//    freopen("../ch05/e5-10-data.in", "r", stdin);
    int kase = 1;

    cin >> kase;
    while (kase--) {
        int player_num;                             // 选手数量
        map<int, string> idx2name;                  // 选手ID到name的映射（用于最后的打印输出）

        double total_reward, ratios[75];            // 总奖金与前70名的奖金比例

        int scores[150][5];                         // 第一维为选手个数，第二维为四轮比赛的分数
        memset(scores, INF, sizeof(scores));        // 默认值为INF，即犯规所得分数

        bool professional[150];                     // 是否为职业选手
        memset(professional, true, sizeof(professional));

        int first_rank[150], sec_rank[150];         // 前两轮与后两轮选手ID到排名的映射
        memset(first_rank, 0, sizeof(first_rank));
        memset(sec_rank, 0, sizeof(sec_rank));
        map<int, double> rewards;                   // 晋级者ID到所得奖金的映射

        // TODO: 经过测试，数据读取部分无误

        // 读取总奖金数与奖金比例
        cin >> total_reward;
        for (int i = 1; i <= 70; i++) {
            cin >> ratios[i];
        }

        // 读取选手数与各个选手的得分
        cin >> player_num;
        scanf("\n");
        for (int i = 0; i < player_num; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            string first_name, parent_name;
            int score;
            ss >> first_name >> parent_name;
            first_name += " ";
            first_name += parent_name;
            idx2name[i] = first_name;

            // 识别业余选手
            if (parent_name[parent_name.length() - 1] == '*') {
                professional[i] = false;
            }

            int score_idx = 0;
            // 如果出现了字符串（"DQ"），则score的值会被置为0，while内的代码不会被执行。
            // DQ对应的分数为默认值，即INF
            while (ss >> score) {
                scores[i][score_idx++] = score;
            }
        }

        // 开始处理
        // 首先，选出晋级选手，用一个vector存放所有选手前两轮的总分。前两轮犯规者不可晋级
        vector<int> first_rnd_scores;
        first_rnd_scores.reserve(player_num);
        for (int i = 0; i < player_num; i++) {
            first_rnd_scores.push_back(scores[i][0] + scores[i][0]);  // 犯规者的分数为INF * 2
        }
        sort(first_rnd_scores.begin(), first_rnd_scores.end());
        for (int i = 0; i < player_num; i++) {
            int r = 1;
            for (auto &it: first_rnd_scores) {
                if (scores[i][0] + scores[i][1] > it) {
                    r++;
                }
            }
            first_rank[i] = r;
        }

        // 至此，所有选手前两轮的排名已经存入first_rank。现在需要从中选出前70名
        // 输入保证至少能够有70名选手晋级。因此不用担心这些晋级选手是否有犯规的（即他们前两轮的分数和必然小于INF）
        // 用一个vector存放所有晋级选手后两轮的总分
        vector<int> sec_rnd_scores;
        for (int i = 0; i < player_num; i++) {
            if (first_rank[i] <= 70) {
                // 选手i晋级了，将其四轮分数和保存下来
                sec_rnd_scores.push_back(first_rnd_scores[i] + scores[i][2] + scores[i][3]);
            }
        }
        sort(sec_rnd_scores.begin(), sec_rnd_scores.end());
        for (int i = 0; i < player_num; i++) {
            if (first_rank[i] <= 70) {
                int r = 1;
                for (auto &it: sec_rnd_scores) {
                    if (first_rnd_scores[i] + scores[i][0] + scores[i][1] > it) {
                        r++;
                    }
                }
                sec_rank[i] = r;
            }
        }

        // 至此，所有晋级选手的排名已经存入sec_rank。
        // 可能存在晋级了的选手第三轮或第四轮比赛犯规，他们会被取消资格。
        // 接下来计算所有没有犯规的、前70名的专业选手分得的奖金
        for (int r = 1; r <= 70; r++) {
            int player_num_on_r = 0;
            for (int i = 0; i < player_num; i++) {
                if (sec_rank[i] == r) {
                    if (sec_rnd_scores[i] < INF && professional[i]) {
                        player_num_on_r++;
                    } else {
                        // 虽然选手i第二轮排名后仍在前70名中，但是他犯规了。因此不参与评奖。
                    };
                }
            }
            // player_num_on_r存放了排名为r的、可以参与分钱的选手个数
            double ratios_on_r = 0;
            for (int i = r; i < r + player_num_on_r; i++) {
                ratios_on_r += ratios[i];
            }
            ratios_on_r /= player_num_on_r;
            for (int i = 0; i < player_num; i++) {
                if (sec_rank[i] == r) {
                    rewards[i] = total_reward * ratios_on_r;
                }
            }
        }

        // 最后，输出
        cout << "Player name          Place     RDJ  RD2  RD3  RD4  TOTAL     Money Won " << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        // 有奖金的选手
        for (int r = 1; r <= 70; r++) {
            for (int i = 0; i < player_num; i++) {
                // TODO: 这里没有处理「并列时按轮数、各轮得分、姓名的方式排序输出」等问题
                if (sec_rank[i] == r) {
                    cout << idx2name[i];
                    for (int j = 0; j < 21 - idx2name[i].length(); j++) {
                        cout << " ";
                    }
                    cout << r;
                    // TODO: cout << 特定数量的空格
                    for (int j = 0; j < 4; j++) {
                        if (scores[i][j] != INF) {
                            cout << scores[i][j];
                            // TODO: cout << 特定数量的空格
                        } else {
                            // TODO: cout << 特定数量的空格
                        }
                    }
                    if (sec_rnd_scores[i] > INF) {
                        cout << "DQ";
                        // TODO: cout << 特定数量的空格
                    } else {
                        cout << sec_rnd_scores[i];
                    }
                    if (rewards.count(i)) {
                        printf("$%.2f\n", rewards[i]);
                    }
                }
            }
        }
        // 没奖金的选手
        for (int r = 71; r < player_num; r++) {
            for (int r1 = 1; r1 <= 70; r1++) {
                for (int i = 0; i < player_num; i++) {
                    // 满足这个if条件的，是那些第一轮晋级了，但是第二轮被淘汰了的选手，他们也需要被输出
                    // 这里可以保证是按照第二轮的分数排序输出的
                    if (first_rank[i] == r1 && sec_rank[i] == r) {
                        cout << idx2name[i];
                        for (int j = 0; j < 21 - idx2name[i].length(); j++) {
                            cout << " ";
                        }

                        if (sec_rank[i] < INF) {
                            // 这个选手虽然第二轮被淘汰，但是并没有犯规
                            cout << r;
                            // TODO: cout << 特定数量的空格
                            for (int j = 0; j < 4; j++) {
                                if (scores[i][j] != INF) {
                                    cout << scores[i][j];
                                    // TODO: cout << 特定数量的空格
                                } else {
                                    // TODO: cout << 特定数量的空格
                                }
                            }
                            if (sec_rnd_scores[i] > INF) {
                                cout << "DQ";
                                // TODO: cout << 特定数量的空格
                            } else {
                                cout << sec_rnd_scores[i];
                            }
                        } else {
                            // 犯规者不输出排名
                            // TODO: cout << 特定数量的空格
                            for (int j = 0; j < 4; j++) {
                                if (scores[i][j] != INF) {
                                    cout << scores[i][j];
                                    // TODO: cout << 特定数量的空格
                                } else {
                                    // TODO: cout << 特定数量的空格
                                }
                            }
                            if (sec_rnd_scores[i] > INF) {
                                cout << "DQ";
                                // TODO: cout << 特定数量的空格
                            } else {
                                cout << sec_rnd_scores[i];
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}