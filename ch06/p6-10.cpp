//
// Created by hliangzhao on 2022/4/30.
//

#include <iostream>
#include <queue>
#include <list>
#include <set>

using namespace std;

typedef deque<int> Pile;

bool check(int x, int y, int z) {
    int sum = x + y + z;
    return sum == 10 || sum == 20 || sum == 30;
}

int main() {
    freopen("../ch06/p6-10-data.in", "r", stdin);
    int x;
    while (cin >> x && x) {
        queue<int> deck;
        deck.push(x);
        for (int i = 0; i < 51; i++) {
            cin >> x;
            deck.push(x);
        }
        list<Pile> piles;
        // 从最上面开始依次拿出7张牌摆开
        for (int i = 0; i < 7; i++) {
            piles.push_back(Pile{deck.front()});
            deck.pop();
        }
        set<pair<queue<int>, list<Pile>>> s;
        s.emplace(deck, piles);
        int win = 0, draw = 0, times = 7;
        // 当deck不为空的时候，依次对每一个牌堆p执行如下操作
        for (auto p = piles.begin(); !deck.empty();) {
            times++;
            p->push_back(deck.front());
            deck.pop();
            while (p->size() >= 3) {
                Pile &cur = *p;
                // 检查三种可能
                if (check(cur[0], cur[1], cur[cur.size() - 1])) {
                    deck.push(cur[0]);
                    deck.push(cur[1]);
                    deck.push(cur[cur.size() - 1]);
                    cur.pop_front();
                    cur.pop_front();
                    cur.pop_back();
                } else if (check(cur[0], cur[cur.size() - 2], cur[cur.size() - 1])) {
                    deck.push(cur[0]);
                    deck.push(cur[cur.size() - 2]);
                    deck.push(cur[cur.size() - 1]);
                    cur.pop_front();
                    cur.pop_back();
                    cur.pop_back();
                } else if (check(cur[cur.size() - 3], cur[cur.size() - 2], cur[cur.size() - 1])) {
                    deck.push(cur[cur.size() - 3]);
                    deck.push(cur[cur.size() - 2]);
                    deck.push(cur[cur.size() - 1]);
                    cur.pop_back();
                    cur.pop_back();
                    cur.pop_back();
                }
                else {
                    break;
                }
            }
            auto pre = p;
            p++;
            if (p == piles.end()) {
                p = piles.begin();
            }
            if (pre->empty()) {
                // 使用list，移除一个元素之后，后面的元素自动实现左移的效果（因为背后是双向链表）
                piles.erase(pre);
                if (piles.empty()) {
                    win = 1;
                    break;
                }
            }
            // set.emplace()返回插入是否生效。first是插入的元素，second是插入成功或失败
            // 如果当set中已有first元素，则插入失败
            // 因此，这里的判断是「如果形如当前piles」的牌堆已经存在了，则意味着陷入了循环
            if (!s.emplace(deck, piles).second) {
                win = -1;
                break;
            }
        }
        if (win == -1) cout << "Draw: " << times << endl;
        else if (win) cout << "Win: " << times << endl;
        else cout << "Loss: " << times << endl;
    }
    return 0;
}
