//
// Created by hliangzhao on 2022/4/29.
//

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const int maxn = 100 + 5;
int n;                  // 节点个数
int m;                  // 边个数

struct Transition {
    vector<int> s, t;       // 一次迁移的（多个）输入及（多个）输出

    Transition(vector<int> s, vector<int> t) : s(std::move(s)), t(std::move(t)) {}
};

vector<Transition> transitions;
int tokens[maxn];

// TODO: 下面给出了将一个数组排序后保存原元素index的方法
struct element {
    int data;
    size_t idx;
} sorted_tokens[maxn];

int cmp(const void *a, const void *b) {
    return ((const element *) a)->data > ((const element *) b)->data;
}

void sort_tokens() {
    // assignment
    for (int i = 1; i <= n; i++) {
        sorted_tokens[i].data = tokens[i];
        sorted_tokens[i].idx = i;
    }
    qsort(sorted_tokens, n, sizeof(sorted_tokens[0]), cmp);
}

bool check(const Transition &trans) {
    int tokens_copy[maxn];
    copy(tokens + 1, tokens + n + 1, tokens_copy + 1);
    for (auto in: trans.s) {
        tokens_copy[in]--;
    }
    for (int i = 1; i <= n; i++) {
        if (tokens_copy[i] < 0) {
            return false;
        }
    }
    return true;
}

void make_transition(const Transition &trans) {
    // 将token按照要求转移
    for (auto in: trans.s) {
        tokens[in]--;
    }
    for (auto out: trans.t) {
        tokens[out]++;
    }
}

int main() {
    freopen("../ch06/p6-7-data.in", "r", stdin);
    int kase = 0;
    while (cin >> n && n) {
        transitions.clear();
        memset(tokens, 0, sizeof(tokens));

        // 读取token
        int num;
        for (int i = 1; i <= n; i++) {
            cin >> num;
            tokens[i] = num;
        }

        // 读取transition
        cin >> m;
        for (int i = 1; i <= m; i++) {
            // 读取本行的数字
            int e;
            vector<int> s, t;
            while (cin >> e) {
                if (e == 0) break;
                if (e < 0) {
                    s.push_back(-e);
                } else {
                    t.push_back(e);
                }
            }
            transitions.emplace_back(s, t);
        }

        // simulate
        int sim_num, act_sim_num = 0;
        cin >> sim_num;
        bool stop;
        for (int i = 0; i < sim_num; i++) {
            stop = true;
            for (const auto &trans: transitions) {
                if (check(trans)) {
                    stop = false;
                    make_transition(trans);
                    act_sim_num++;
                }
            }
            if (stop) {
                cout << "Case " << ++kase << ": dead after " << act_sim_num << " transitions" << endl;
                cout << "Places with tokens: ";
                sort_tokens();
                for (int j = 1; j <= n; j++) {
                    if (sorted_tokens[j].data > 0) {
                        cout << sorted_tokens[j].idx << " " << "(" << sorted_tokens[j].data << ")" << endl;
                    }
                }
                break;
            }
        }
        if (!stop) {
            cout << "Case " << ++kase << ": still live after " << sim_num << " transitions" << endl;
            cout << "Places with tokens: ";
            sort_tokens();
            for (int j = 1; j <= n; j++) {
                if (sorted_tokens[j].data > 0) {
                    cout << sorted_tokens[j].idx << " " << "(" << sorted_tokens[j].data << ")" << endl;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
