//
// Created by hliangzhao on 2022/4/28.
//

#include <iostream>
#include <map>

using namespace std;

// TODO: 思路 —— 让出现次数最多的节点数值维持不变，其他都改掉

string s;
map<long long, int> values;     // 存放叶子的value到出现次数的映射
int leaf_num, max_value;

// TODO：这个递归函数的设计十分牛逼
void dfs(int level, int begin, int len) {
    if (s[begin] == '[') {
        int p = 0;
        for (int i = begin + 1; i < len; i++) {
            // 下面两行是为了确保找到当前深度的前后两个子树
            if (s[i] == '[') p++;
            if (s[i] == ']') p--;
            // p为0意味着'['和']'成对出现，即能跨越一个（或多个）完整的子树
            if (p == 0 && s[i] == ',') {
                // 逗号分开了左右子树，分别递归
                dfs(level + 1, begin + 1, i - 1);
                dfs(level + 1, i + 1, len - 1);
            }
        }
    } else {
        // 不是'[', ']', '.'，则只能是数字，即叶子节点的值
        long long w = 0;
        for (int i = begin; i <= len; i++) {
            w = w * 10 + s[i] - '0';
        }
        // cnt记录了叶子结点的数量
        leaf_num++;
        // value的计算方式：从当前叶子节点溯源至root，即 w * 2^level
        values[w << level]++;
        max_value = max(max_value, values[w << level]);
    }
}

int main() {
    freopen("../ch06/p6-6-data.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        values.clear();
        leaf_num = 0;
        max_value = 0;
        dfs(0, 0, (int) s.size() - 1);
        cout << leaf_num - max_value << endl;
    }
    return 0;
}
