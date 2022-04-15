//
// Created by hliangzhao on 2022/4/15.
//

#include <iostream>

using namespace std;

const int len = 32;
const int maxn = 1024 + 10;
char str[maxn];
int buf[len][len], cnt;

void draw(const char *s, int &start_pos, int r, int c, int w) {
    char ch = s[start_pos++];
    if (ch == 'p') {
        // TODO：依次递归调用画出1、2、3、4四个位置的子树
        draw(s, start_pos, r, c + w / 2, w / 2);
        draw(s, start_pos, r, c, w / 2);
        draw(s, start_pos, r + w / 2, c, w / 2);
        draw(s, start_pos, r + w / 2, c + w / 2, w / 2);
    } else if (ch == 'f') {
        for (int i = r; i < r + w; i++) {
            for (int j = c; j < c + w; j++) {
                if (buf[i][j] == 0) {
                    // TODO: 同一个位置的黑色只需要被统计1次
                    buf[i][j] = 1;
                    cnt++;
                }
            }
        }
    }
}

int main() {
    freopen("../ch06/e6-11-data.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        memset(buf, 0, sizeof(buf));
        cnt = 0;
        for (int i = 0; i < 2; i++) {
            scanf("%s", str);
            int p = 0;
            draw(str, p, 0, 0, len);
        }
        cout << "There are " << cnt << " black pixels." << endl;
    }
    return 0;
}