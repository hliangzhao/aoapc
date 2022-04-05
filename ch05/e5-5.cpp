//
// Created by hliangzhao on 2022/4/5.
//

// TODO: 本题综合了几种容器，值得细细品味。
//  (1) 将题目中自定义的「数据类型」映射到整数，从而使得STL提供的容器可以被使用；
//  (2) 使用宏（这不是必须的）；
//  (3) 对于stack本身，我们重点关注push, pop和top三种操作。

#include <iostream>
#include <cstdio>
#include <stack>
#include <set>
#include <map>
#include <vector>

using namespace std;

// 将集合映射到整数，则集合的集合就是整数的集合
typedef set<int> Set;

// 记录集合的集合和对应的整数的映射关系
map<Set, int> IDCache;

// 存放所有已经出现的集合（的集合）。元素的下标就是集合（的集合）所映射到的整数。
// SetCache和IDCache相互交换kv
vector<Set> SetCache;

// 题目中的栈
stack<int> e55_s;

// 对应给定的Set，如没有id则创建，否则从cache中返回
int get_id(const Set &x) {
    if (IDCache.count(x)) {
        return IDCache[x];
    }
    SetCache.push_back(x);
    return IDCache[x] = (int) SetCache.size() - 1;
}

// 使用宏
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

int main() {
    freopen("../ch05/e5-5-data.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op[0] == 'P') {
            // 创建一个空Set实例，将其ID入栈
            e55_s.push(get_id(Set()));
        } else if (op[0] == 'D') {
            e55_s.push(e55_s.top());
        } else {
            Set x1 = SetCache[e55_s.top()];
            e55_s.pop();
            Set x2 = SetCache[e55_s.top()];
            e55_s.pop();
            Set x;
            if (op[0] == 'U') {
                // 宏存在的意义是整体代换
                set_union(ALL(x1), ALL(x2), inserter(x, x.begin()));
            }
            if (op[0] == 'I') {
                set_intersection(x1.begin(), x1.end(), ALL(x2), INS(x));
            }
            if (op[0] == 'A') {
                x = x2;
                x.insert(get_id(x1));
            }
            e55_s.push(get_id(x));
        }
        cout << SetCache[e55_s.top()].size() << endl;
    }
    return 0;
}
