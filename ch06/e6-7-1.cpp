//
// Created by hliangzhao on 2022/4/13.
//

// TODO: 使用「结构体+指针」的方式存储节点和树

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

// TODO: 通过new运算符申明新的内存空间。内部自动调用构造函数，返回新分配的变量的地址
Node *new_node() {
    return new Node();
}

// TODO: 全局的根节点
Node *root;
// 输入数据是否存在问题
bool failed;

// pos example: LLR)
void add_node(int val, char *pos) {
    int n = (int) strlen(pos);
    Node *u = root;
    for (int i = 0; i < n; i++) {
        // TODO: 把途径的节点先创建出来
        if (pos[i] == 'L') {
            if (u->left == nullptr) {
                u->left = new_node();
            }
            u = u->left;
        } else if (pos[i] == 'R') {
            if (u->right == nullptr) {
                u->right = new_node();
            }
            u = u->right;
        }
    }
    if (u->have_value) {
        failed = true;
    }
    u->val = val;
    u->have_value = true;
}

void remove_tree(Node *u) {
    if (u == nullptr) return;
    remove_tree(u->left);
    remove_tree(u->right);
    // TODO：通过delete运算符释放u所代表的变量占用的空间。内部自动调用析构函数。
    delete u;
}

const int maxn = 256;
char s[maxn];

bool read_input() {
    failed = false;
    root = new_node();
    for (;;) {
        // s example: (2,LLR)
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
        remove_tree(root);
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
