//
// Created by hliangzhao on 2022/4/3.
//

/* IP networks */
// TODO: 处理思路 —— 找到一个最小的n，使得[11...10..0]（前32-n位都是1，后n位都是0）和输入的各个IP地址按位做与运算的结果全部相同

#include <cstdio>

void test_and() {
    printf("%d\n", 176 & 208);
}

int main() {
    freopen("../ch04/p4-5-data.in", "r", stdin);

    int n, input_IP_num;
    int IPs[10][4], mask[4], masked_IPs[10][4], masked_result[4], network[4];
    scanf("%d\n", &input_IP_num);
    for (int i = 0; i < input_IP_num; i++) {
        char tmp[30];
        scanf("%s", tmp);
        sscanf(tmp, "%d.%d.%d.%d", &IPs[i][0], &IPs[i][1], &IPs[i][2], &IPs[i][3]);
    }

    // 从小到大遍历n的取值
    for (n = 1; n <= 31; n++) {
        int ok = 1;
        // TODO：设置子网掩码
        int x = n / 8, y = n % 8;
        for (int i = 3; i >= 3 - x + 1; i--) {
            mask[i] = 0;
        }
        mask[3 - x] = 255 - ((1 << y) - 1);
        for (int i = 3 - x - 1; i >= 0; i--) {
            mask[i] = 255;
        }
        // TODO：将子网掩码按照4个段分别和每个网络执行按位与运算，将结果保存到masked_IPs中并判断所有与的结果是否都相等
        for (int i = 0; i < input_IP_num; i++) {
            for (int j = 0; j < 4; j++) {
                masked_IPs[i][j] = mask[j] & IPs[i][j];
                if (i == 0) {
                    masked_result[j] = masked_IPs[i][j];
                }
            }
            if (i > 0) {
                for (int j = 0; j < 4; j++) {
                    if (masked_result[j] != masked_IPs[i][j]) {
                        ok = 0;
                        break;
                    }
                }
            }
        }
        if (ok) {
            printf("network: %d.%d.%d.%d\n   mask: %d.%d.%d.%d\n",
                   masked_result[0], masked_result[1], masked_result[2], masked_result[3],
                   mask[0], mask[1], mask[2], mask[3]);
            return 0;
        }
    }

    return 0;
}
