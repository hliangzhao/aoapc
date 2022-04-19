//
// Created by hliangzhao on 2022/4/19.
//

// TODO：欧拉回路问题（又称"一笔画"）。
//  无向图版本：能否从一个节点出发走一条道路，使得每一条边恰好走一次？如果可以，打印这条道路（被称为欧拉道路）。
//             显然，在欧拉道路中，进和出是对应的，即「除了起点和终点」，其他点的度数都需要是偶数。
//             我们可以得到欧拉道路存在的「充要条件」——
//             如果一个无向图是「连通」的，且「最多」只有两个奇点，则一定存在欧拉道路。
//             如果有两个奇点，则必须从其中一个奇点出发，另一个奇点终止；如果奇点不存在，则可以从任意点出发，最终一定会回到该点（这种欧拉道路被称为欧拉回路）。
//  有向图版本：能否从一个节点出发走一条道路，使得每一条边恰好走一次？如果可以，打印这条道路（被称为欧拉回路）。
//             我们可以得到欧拉道路存在的「充要条件」——
//             首先要求该有向图在忽略边的方向后是连通的，
//             其次，最多只能有两个点的入度不等于出度，而且必须是其中一个点的出度恰好比入度大1（作为起点），另一个点的入度恰好比出度大1（作为终点）。
//  在实现时，首先需要判断图是否连通（可以使用DFS或查并集的方法），然后使用DFS构造欧拉道路（回路）。

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1000 + 5;
int used[256], degree[256];   // 使用过，used = 1，否则 used = 0；出度 +1，入度 -1

// TODO：并查集代码（没彻底理解）
int pa[256];

// 父亲节点和自身不是同一个节点，则递归查找到最远的位置
// 本质上是从本节点出发，判断所有伸展出去的路径中的节点
int find_set(int x) {
    return pa[x] != x ? pa[x] = find_set(pa[x]) : x;
}

int main() {
    freopen("../ch06/e6-16-data.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        char word[maxn];
        scanf("%d", &n);

        memset(used, 0, sizeof(used));
        memset(degree, 0, sizeof(degree));
        for (int ch = 'a'; ch <= 'z'; ch++) {
            pa[ch] = ch;
        }
        int cc = 26;

        for (int i = 0; i < n; i++) {
            scanf("%s", word);
            char c1 = word[0], c2 = word[strlen(word) - 1];
            degree[c1]++;
            degree[c2]--;
            used[c1] = used[c2] = 1;

            // TODO：并查集代码（没彻底理解）
            int s1 = find_set(c1), s2 = find_set(c2);
            if (s1 != s2) {
                // 进入这个if判断说明s1和s2是连通的，设定二者之间的连通关系，并且让不连通块自减1
                pa[s1] = s2;
                cc--;
            }
        }

        vector<int> d;
        for (int ch = 'a'; ch <= 'z'; ch++) {
            // 没有出现的字母不参与不连通块的计数，直接减掉
            if (!used[ch]) cc--;
            else if (degree[ch] != 0) {
                d.push_back(degree[ch]);
            }
        }

        bool ok = false;
        // cc = 1意味着可以形成一个连通块。这是欧拉道路存在的条件1
        // 入度不等于出度的节点，要么是0，要么是2。若是2，则必然一个出度 = 入度 + 1，另一个入度 = 出度 + 1
        if(cc == 1 && (d.empty() || (d.size() == 2 && (d[0] == 1 || d[0] == -1)))) ok = true;
        if(ok) printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
    return 0;
}
