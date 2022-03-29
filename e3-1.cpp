//
// Created by hliangzhao on 2022/3/29.
//

// TODO: 关于字符读取的一些梳理：
//  (1) 使用scanf("%s", s)可以读取一个字符串，但是它遇到空白字符就会停下；
//  (2) 使用fgetc(fin)从输入流中读取一个字符。fgetc返回的其实是int变量，需要转换为char变量。
//      fgetc在流的末尾会读取到一个特殊标记EOF。
//  (3) 从标准输入流中读取一个字符，可以用getchar()，他等价于fgetc(stdin)。
//  (4) 使用fgets(buf, maxn, fin)从fin中读取不超过maxn-1个字符，然后在末尾添加上"\0"。
//      使用fgets可以读取完整的一行，这是因为它一旦读取到回车符，就会将"\n"作为最后一个有效字符。

#include <cstdio>

#define LOCAL

void test_fgetc1();

void test_fgetc2();

void test_fgets();

int main() {
#ifdef LOCAL
    freopen("../e3-1-data.in", "r", stdin);
#endif
    char c;
    int sign = 1;
    while ((c = getchar()) != EOF) {
        if (c == '"') {
            printf("%s", sign ? "``" : "''");
            sign = !sign;
        } else {
            printf("%c", c);
        }
    }
    return 0;
}

void test_fgetc1() {
    int c = fgetc(stdin);
    printf("%c %d", (char) c, c);
}

void test_fgetc2() {
    int c;
    while ((c = fgetc(stdin)) != EOF) {
        printf("%c %d\n", (char) c, c);
    }
}

void test_fgets() {
    char buf[20];
    fgets(buf, 20, stdin);
    printf("%s", buf);
}