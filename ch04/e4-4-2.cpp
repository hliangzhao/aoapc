//
// Created by hliangzhao on 2022/4/1.
//

// e4-4是我的代码，本文件是作者给出的代码

#include <cstdio>
#include <cstring>

#define LOCAL

int read_char() {
    for (;;) {
        int ch = getchar();
        if (ch != '\n' && ch != '\r') {
            return ch;
        }
    }
}

int read_int(int c) {
    int v = 0;
    while (c--) {
        v = v * 2 + read_char() - '0';
    }
    return v;
}

int code[8][1 << 8];

// TODO: 读取跨行文本的一种方法
int read_codes() {
    memset(code, 0, sizeof(code));
    code[1][0] = read_char();
    for (int len = 2; len <= 7; len++) {
        for (int i = 0; i < (1 << len) - 1; i++) {
            int ch = getchar();
            if (ch == EOF) {
                return 0;
            }
            if (ch == '\n' || ch == '\r') {
                return 1;  // 换行继续读
            }
            code[len][i] = ch;
        }
    }
    return 1;
}

int main() {
#ifdef LOCAL
    freopen("../ch04/e4-4-data.in", "r", stdin);
#endif
    while (read_codes()) {
        for (;;) {
            int len = read_int(3);
            if (len == 0) {
                break;
            }
            for (;;) {
                int v = read_int(len);
                if (v == (1 << len) - 1) {
                    break;
                }
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}
