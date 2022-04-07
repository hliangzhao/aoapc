//
// Created by hliangzhao on 2022/4/7.
//

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>

using namespace std;

const int max_n = 10005;
const int max_m = 15;

int database[max_n][max_m];     // 存放每行每列的单元格
map<vector<int>, int> mapper;   // 存放(单元格1,单元格2)到所在行编号的映射

map<string, int> e59_IDCache;   // 从单元格到ID
vector<string> entries;         // 从ID到单元格

// 给每一个单元格分配一个编号
int ID(const string &s) {
    if (e59_IDCache.count(s)) return e59_IDCache[s];
    entries.push_back(s);
    return e59_IDCache[s] = (int) entries.size() - 1;
}

// TODO: 字符串分割
void split(const string &s, vector<string> &sv, const char delim = ',') {
    sv.clear();
    istringstream iss(s);
    string tmp;
    while (getline(iss, tmp, delim)) {
        sv.emplace_back(move(tmp));
    }
}

int main() {
    freopen("../ch05/e5-9-data.in", "r", stdin);
    int n, m;
    while (cin >> n >> m) {
        mapper.clear();
        // TODO: 换行符处理掉
        scanf("\n");

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            // 将line按照逗号分割
            vector<string> sv;
            split(line, sv);
            // 将每一个单元格存入对应的位置
            for (int j = 0; j < sv.size(); j++) {
                database[i][j] = ID(sv[j]);
            }
        }

        // 遍历c1和c2
        int found = 0;
        for (int c1 = 0; c1 < m - 1; c1++) {
            for (int c2 = c1 + 1; c2 < m; c2++) {
                // 遍历每一个r
                for (int r = 0; r < n; r++) {
                    // 检查[(r, c1),(r, c2)] --> r1这个映射是否存在
                    vector<int> key;
                    key.push_back(database[r][c1]);
                    key.push_back(database[r][c2]);
                    if (mapper.count(key)) {
                        found = 1;
                        int r1 = mapper[key];
                        // 返回r1，r2，c1，c2
                        cout << "NO" << endl;
                        cout << r1 + 1 << " " << r + 1 << endl;
                        cout << c1 + 1 << " " << c2 + 1 << endl;
                        break;
                    } else {
                        mapper[key] = r;
                    }
                }
                if (found) break;
            }
            if (found) break;
        }
        if (!found) {
            cout << "YES" << endl;
        }
    }
    return 0;
}
