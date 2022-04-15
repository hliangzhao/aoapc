//
// Created by hliangzhao on 2022/4/14.
//

#include <iostream>
#include <sstream>
#include <algorithm>

// TODO: 对于二叉树T，其深度优先遍历有：
//  先序遍历PreOrder：T的根节点，PreOder(T的左子树)，PreOder(T的右子树)
//  中序遍历InOrder：InOrder(T的左子树)，T的根节点，InOrder(T的右子树)
//  后序遍历PostOrder：PostOrder(T的左子树)，PostOrder(T的右子树)，T的根节点

using namespace std;

// 直接用节点的数值作为节点的编号（省下一个数组的空间）
const int max_val = 10000 + 10;

// 存放中序遍历和后续遍历
int in_order[max_val], post_order[max_val];

// 用数组来存储二叉树
int left_node[max_val], right_node[max_val];

// 节点个数
int n;

// 读取中序遍历和后续遍历到数组中
bool read_list(int *a) {
    string line;
    if (!getline(cin, line)) return false;
    stringstream ss(line);
    n = 0;
    int x;
    while (ss >> x) {
        a[n++] = x;
    }
    return n > 0;
}

// TODO: 根据in_order[L1...R1]和post_order[L2...R2]构建二叉树，返回树根
int build_bin_tree(int L1, int R1, int L2, int R2) {
    // 空树
    if (L1 > R1) return 0;
    // TODO: 后序遍历的最后一个元素就是当前（子）树的根。
    //  在中序遍历中找到根 (idx = p)，这个数左边的就是左子树，右边的就是右子树。然后分别构建左右子树。
    int root = post_order[R2];
    int p = L1;
    while (in_order[p] != root) p++;
    int cnt = p - L1;
    // build_bin_tree(L1, p - 1, L2, L2 + cnt - 1)返回的是左子树的根，它是当前根的左孩子节点。同理设定右孩子
    left_node[root] = build_bin_tree(L1, p - 1, L2, L2 + cnt - 1);
    right_node[root] = build_bin_tree(p + 1, R1, L2 + cnt, R2 - 1);
    return root;
}

int best_node, best_sum;

void dfs(int node, int sum) {
    sum += node;
    if (!left_node[node] && !right_node[node]) {
        if (sum < best_sum || (sum == best_sum && node < best_node)) {
            best_node = node;
            best_sum = sum;
        }
    }
    // TODO: 当递归返回的时候，加上的数值会自动减回去
    if (left_node[node]) {
        dfs(left_node[node], sum);
    }
    if (right_node[node]) {
        dfs(right_node[node], sum);
    }
}

int main() {
    freopen("../ch06/e6-8-data.in", "r", stdin);
    while (read_list(in_order)) {
        read_list(post_order);
        build_bin_tree(0, n - 1, 0, n - 1);
        best_sum = 1000000000;
        // dfs从根节点开始
        dfs(post_order[n - 1], 0);
        cout << best_node << endl;
    }
    return 0;
}
