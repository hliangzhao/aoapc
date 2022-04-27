//
// Created by hliangzhao on 2022/4/27.
//

#include <iostream>

using namespace std;

int main() {
    freopen("../ch06/p6-2-data.in", "r", stdin);
    int depth, query_num, kase = 0;
    string vars, leafs, queries;
    while (scanf("%d\n", &depth) != EOF && depth) {
        // TODO: vars其实是用不到的，我们只需要根据输入的串判断最终落到的叶子的编号即可
        //  例如，110 ---> 1*2^2 + 1*2 + 0*1 = 6，leafs[6] = '1'
        getline(cin, vars);
        cin >> leafs;
        cin >> query_num;
        cout << "S-Tree #" << ++kase << ":\n";
        while (query_num--) {
            cin >> queries;
            int pos = 0, scale = 1;
            for (int i = (int) queries.length() - 1; i >= 0; i--) {
                pos += (queries[i] - '0') * scale;
                scale *= 2;
            }
            cout << leafs[pos];
        }
        cout << endl << endl;
    }
    return 0;
}
