//
// Created by hliangzhao on 2022/3/29.
//

/* Score */

#include <cstdio>
#include <cstring>

int main() {
    int c = 0, score = 0;
    char s[85];
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'X') {
            c = 0;
        } else {
            c++;
            score += c;
        }
    }
    printf("%d\n", score);
    return 0;
}
