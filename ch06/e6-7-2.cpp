//
// Created by hliangzhao on 2022/4/13.
//

// TODO: 使用「数组」的方式存储节点和树

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

// TODO：定义节点结构体
//  用cnt表示当前已存在的节点编号的最大值
//  用left和right数组分别表示每个节点的左孩子和右孩子的编号（注意区分节点的编号和节点中存放的数值）
//  用values数组记录每一个节点中存放的数值
//  用have_value数组记录每一个节点是否已经被赋值
int cnt;
const int max_node_num = 256;
int left[max_node_num], right[max_node_num];
int values[max_node_num];
bool have_value[max_node_num];

// TODO：根节点的编号为1
const int root = 1;

// TODO: 只需要重置计数器和根节点的左右子树即可清空整棵树
void new_tree() {
    left[root] = right[root] = 0;
    have_value[root] = false;
    cnt = root;
}

// TODO：创建一个节点，只需要初始化其左右子树即可。返回的是当前节点的编号
int new_node() {
    int u = ++cnt;
    left[u] = right[u] = 0;
    have_value[u] = false;
    return u;
}

// 输入数据是否存在问题
bool failed;

// path example: "LLR)"
void add_node(int val, char *path) {
    int n = (int) strlen(path);
    int u = root;
    for (int i = 0; i < n; i++) {
        // TODO: 把途径的节点先创建出来
        if (path[i] == 'L') {
            if (left[u] == 0) {
                int left_child_idx = new_node();
                left[u] = left_child_idx;
            }
            u = left[u];
        } else if (path[i] == 'R') {
            if (right[u] == 0) {
                int right_child_idx = new_node();
                right[u] = right_child_idx;
            }
            u = right[u];
        }
    }
    if (have_value[u]) {
        failed = true;
    }
    // 将val存入编号为u的节点中
    values[u] = val;
    have_value[u] = true;
}

const int maxn = 256;
char s[maxn];

bool read_input() {
    failed = false;
    new_tree();
    for (;;) {
        // s example: "(2,LLR)"
        if (scanf("%s", s) != 1) return false;
        if (!strcmp(s, "()")) break;
        int val;
        sscanf(&s[1], "%d", &val);
        add_node(val, strchr(s, ',') + 1);
    }
    return true;
}

// 参数为引用类型
bool dfs(vector<int> &ans) {
    queue<int> q;
    ans.clear();
    q.push(root);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // 创建树的时候途径的节点都被构造出来了，但是如果一个节点没有数值意味着对应的输入存在问题
        if (!have_value[u]) return false;
        ans.push_back(u);
        if (left[u] != 0) q.push(left[u]);
        if (right[u] != 0) q.push(right[u]);
    }
    return true;
}

int main() {
    freopen("../ch06/e6-7-data.in", "r", stdin);
    while (true) {
        if (!read_input()) break;
        vector<int> ans;
        if (failed || !dfs(ans)) {
            printf("-1\n");
        } else {
            for (auto &it: ans) {
                printf("%d ", values[it]);
            }
            printf("\n");
        }
    }
    return 0;
}
