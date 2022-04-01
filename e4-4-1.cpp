//
// Created by hliangzhao on 2022/4/1.
//

#include <cstdio>
#include <cstring>

#define max_len 10
#define max_val 1024
#define LOCAL

char codes[max_len][max_val], head[100], content[1000], tmp[100];

void set_codes() {
    int head_len = strlen(head), pos = 0, binary_len = 1, all_set = 0;
    while (true) {
        int val_len = (binary_len << 1) - 1;
        for (int i = 0; i < val_len; i++) {
            codes[binary_len][i] = head[pos++];
//            printf("%c ", codes[binary_len][i]);
            if (pos >= head_len) {
                all_set = 1;
                break;
            }
        }
        binary_len++;
        if (all_set) {
            break;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("../e4-4-data.in", "r", stdin);
#endif
    memset(content, '\0', sizeof(content));
    scanf("%s", head);
    set_codes();

    // TODO: 读取跨行文本的一种方法
    int content_pos = 0;
    while (scanf("%s", tmp) == 1) {
        int tmp_len = strlen(tmp);
        for (int i = 0; i < tmp_len; i++) {
            content[i + content_pos] = tmp[i];
        }
        content_pos += tmp_len;
    }

    // 至此，正文部分的字符串已经全部存入content数组
    // 开始进行解码
    content_pos = 0;
    while (true) {
        int cur_len = 0;
        for (int i = content_pos; i < content_pos + 3; i++) {
            cur_len = cur_len * 2 + content[i] - '0';
        }
        if (cur_len == 0) {
            break;
        }
        content_pos += 3;

        while (true) {
            int val = 0;
            for (int i = content_pos; i < content_pos + cur_len; i++) {
                val = val * 2 + content[i] - '0';
            }
            content_pos += cur_len;
            if (val == (1 << cur_len) - 1) {
                break;
            }
            printf("%c", codes[cur_len][val]);
        }
    }
    printf("\n");

    return 0;
}
