//
// Created by hliangzhao on 2022/4/13.
//

// TODO: 使用「静态结构体数组 + 内存池技术」的方式存储节点和树

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

// TODO：定义节点结构体
struct Node {
    bool have_value;
    int val;
    Node *left, *right;

    Node() : have_value(false), val(0), left(nullptr), right(nullptr) {}
};

// TODO：静态申请的结构体数组
const int maxn = 256;
Node nodes[maxn];

// TODO: 空闲数组列表
queue<Node *> free_nodes;

// TODO: 初始化内存池
void init() {
    for (auto &node : nodes) {
        free_nodes.push(&node);
    }
}

// TODO: 创建一个新的node，本质上就是从内存池中申请一个node空间占用
Node *new_node() {
    Node *u = free_nodes.front();
    u->left = u->right = nullptr;
    u->have_value = false;
    free_nodes.pop();
    return u;
}

// TODO: 释放一个node，本质上就是将其放回空闲内存池中
void delete_node(Node *u) {
    free_nodes.push(u);
}

// TODO: 全局的根节点
Node *root;
// 输入数据是否存在问题
bool failed;

// path example: "LLR)"
void add_node(int val, char *path) {
    int n = (int) strlen(path);
    Node *u = root;
    for (int i = 0; i < n; i++) {
        // TODO: 把途径的节点先创建出来
        if (path[i] == 'L') {
            if (u->left == nullptr) {
                u->left = new_node();
            }
            u = u->left;
        } else if (path[i] == 'R') {
            if (u->right == nullptr) {
                u->right = new_node();
            }
            u = u->right;
        }
    }
    if (u->have_value) {
        failed = true;
    }
    // 将val存入编号为u的节点中
    u->val = val;
    u->have_value = true;
}

char s[maxn];

bool read_input() {
    init();
    failed = false;
    root = new_node();
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
    queue<Node *> q;
    ans.clear();
    q.push(root);
    while (!q.empty()) {
        Node *u = q.front();
        q.pop();
        // 创建树的时候途径的节点都被构造出来了，但是如果一个节点没有数值意味着对应的输入存在问题
        if (!u->have_value) return false;
        ans.push_back(u->val);
        if (u->left != nullptr) q.push(u->left);
        if (u->right != nullptr) q.push(u->right);
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
                printf("%d ", it);
            }
            printf("\n");
        }
    }
    return 0;
}
