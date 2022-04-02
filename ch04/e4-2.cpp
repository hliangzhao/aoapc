//
// Created by hliangzhao on 2022/3/31.
//

#include <cstdio>
#include <cstring>

#define LOCAL

void my_method() {
    int kase;
    char s1[20], s2[20], guessed[20];
    while (scanf("%d", &kase) == 1 && kase != -1) {
        scanf("%s", s1);
        scanf("%s", s2);
        memset(guessed, '\0', sizeof(guessed));

        int win = 0, lose = 0;
        int len1 = strlen(s1), len2 = strlen(s2);
        int left = len1, used_chance = 0;

        // 依次检查s2中的每一个字符
        for (int i = 0; i < len2; i++) {
            char c = s2[i];
            // 判断终止条件
            if (used_chance >= 7) {
                if (left > 0) {
                    lose = 1;
                    break;
                }
            }
            if (left == 0) {
                win = 1;
                break;
            }
            // 判断当前猜测字符是否已经被猜测过
            int is_guessed = 0;
            for (int j = 0; j < strlen(guessed); j++) {
                if (c == guessed[j]) {
                    is_guessed = 1;
                    used_chance++;
                    break;
                }
            }
            if (!is_guessed) {
                guessed[strlen(guessed)] = c;
                int found = 0;
                for (int j = 0; j < len1; j++) {
                    if (c == s1[j]) {
                        found = 1;
                        left--;
                    }
                }
                if (!found) {
                    used_chance++;
                }
            }
        }
        // 在外面还需要再判断一次终止条件
        if (used_chance >= 7) {
            if (left > 0) {
                lose = 1;
            }
        }
        if (left == 0) {
            win = 1;
        }
        if (win) {
            printf("You win.\n");
        }
        if (lose) {
            printf("You lose.\n");
        }
        if (!win && !lose) {
            printf("You chickened out.\n");
        }
    }
}

char e4_2_s1[20], e4_2_s2[20];
int e4_2_win, e4_2_lose, e4_2_left, e4_2_chance;

void guess(char c) {
    int bad = 1;
    for (int i = 0; i < strlen(e4_2_s1); i++) {
        if (e4_2_s1[i] == c) {
            e4_2_left--;
            // TODO: 将已经猜测过的字符设置为' '，这样可以保证下一次猜同样的字符时，会匹配不到，从而使得chance--。
            //  这样就避免了使用guessed这个外部数组。
            e4_2_s1[i] = ' ';
            bad = 0;
        }
    }
    if (bad) --e4_2_chance;
    if (!e4_2_chance) {
        e4_2_lose = 1;
    }
    if (!e4_2_left) {
        e4_2_win = 1;
    }
}

void book_method() {
    int kase;
    while (scanf("%d%s%s", &kase, e4_2_s1, e4_2_s2) == 3 && kase != -1) {
        e4_2_win = e4_2_lose = 0;
        e4_2_left = strlen(e4_2_s1);
        e4_2_chance = 7;
        for (int i = 0; i < strlen(e4_2_s2); i++) {
            guess(e4_2_s2[i]);
            if (e4_2_win || e4_2_lose) {
                break;
            }
        }
        if (e4_2_win) {
            printf("You win.\n");
        }
        if (e4_2_lose) {
            printf("You lose.\n");
        }
        if (!e4_2_win && !e4_2_lose) {
            printf("You chickened out.\n");
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("../ch04/e4-2-data.in", "r", stdin);
#endif
    book_method();
    return 0;
}
