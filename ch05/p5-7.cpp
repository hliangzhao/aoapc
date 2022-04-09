//
// Created by hliangzhao on 2022/4/9.
//

/* Printer Queue */

#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
    freopen("../ch05/p5-7-data.in", "r", stdin);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n, m, task;
        cin >> n >> m;
        queue<int> tasks;
        map<int, int> priorities;    // task_id --> task_priority
        for (int j = 0; j < n; j++) {
            cin >> task;
            tasks.push(j);
            priorities[j] = task;
        }
        int waiting_time = 0;
        while (true) {
            int first_task = tasks.front(), more_important_exist = 0;
            for (auto &it: priorities) {
                if (it.second > priorities[first_task]) {
                    more_important_exist = 1;
                    break;
                }
            }
            if (more_important_exist) {
                tasks.pop();
                tasks.push(first_task);
            } else {
                tasks.pop();
                priorities.erase(first_task);       // TODO: 别忘了将这个任务从map中也删除，否则总是存在优先级更高的任务
                if (first_task == m) {
                    cout << waiting_time + 1 << endl;
                    break;
                }
                waiting_time++;
            }
        }
    }
    return 0;
}
