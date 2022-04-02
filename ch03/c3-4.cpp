//
// Created by hliangzhao on 2022/3/29.
//

#include <cstdio>
#include <cstring>

int main() {
    int cnt = 0;
    char s[20], buf[100];
    scanf("%s", s);   // TODO: 使用scanf直接将文本读入字符数组中。遇到空白字符就会停下来
    for (int abc = 111; abc <= 999; abc++) {
        for (int de = 11; de <= 99; de++) {
            int x = abc * (de % 10);
            int y = abc * (de / 10);
            int z = abc * de;
            // TODO: 将xyz作为字符写入字符串中
            sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
            int ok = 1;
            // TODO: 使用strlen返回字符结束标记之前的字符个数
            for (int i = 0; i < strlen(buf); i++) {
                // TODO: 使用strchr检查每个字符是否在字符串内
                if (strchr(s, buf[i]) == NULL) {
                    ok = 0;
                }
            }
            if (ok) {
                printf("<%d>\n", ++cnt);
                printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n", abc, de, x, y, z);
            }
        }
    }
    printf("The number of solutions = %d\n", cnt);
    return 0;
}

