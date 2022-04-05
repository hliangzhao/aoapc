//
// Created by hliangzhao on 2022/4/5.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <map>

// TODO：对于队列queue，我们重点关注push、pop和front三个操作。

using namespace std;

int main() {
    freopen("../ch05/e5-6-data.in", "r", stdin);

    // 假设团队个数不超过100个
    queue<int> q, x[100];
    map<int, int> mapper;
    int team_num, member_num, member_id;
    cin >> team_num;
    for (int i = 0; i < team_num; i++) {
        cin >> member_num;
        for (int j = 0; j < member_num; j++) {
            cin >> member_id;
            mapper[member_id] = i;
        }
    }

    string op;
    int member;
    while (cin >> op) {
        if (op == "STOP") break;
        if (op == "ENQUEUE") {
            cin >> member;
            // 检查member所在的team是否在q中，具体地，检查x[member_team]是否为空
            int member_team = mapper[member];
            if (x[member_team].empty()) {
                // 团队member_team没有成员入队，则将该团队插入q，然后将该成员插入对应queue的末尾
                q.push(member_team);
                x[member_team].push(member);
            } else {
                // 团队member_team有成员入队，直接将该成员插入对应queue的末尾
                x[member_team].push(member);
            }
        }
        if (op == "DEQUEUE") {
            int team = q.front();
            // 将team队首的成员出队
            cout << x[team].front() << endl;
            x[team].pop();
            if (x[team].empty()) {
                q.pop();
            }
        }
    }

    return 0;
}
