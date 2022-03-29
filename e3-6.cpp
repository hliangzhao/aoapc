//
// Created by hliangzhao on 2022/3/29.
//

#include <cstdio>
#include <cstring>

// TODO: 比较环状字符串的字典顺序
int less(char *s, int p, int q) {
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        if (s[(p + i) % n] != s[(q + i) % n]) {
            return s[(p + i) % n] < s[(q + i) % n];
        }
    }
    return 0;
}

int main() {
    int T;
    char s[105];
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int ans = 0;
        int len = strlen(s);
        // TODO: 这一部分的逻辑和求数组中的最小值是一样的
        for (int i = 1; i < len; i++) {
            if (less(s, i, ans)) {
                ans = i;
            }
        }
        for (int i = 0; i < len; i++) {
            putchar(s[(i + ans) % len]);
        }
        printf("\n");
    }
    return 0;
}
