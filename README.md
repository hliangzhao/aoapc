## AOAPC

论文灌多了，觉得打代码十分手生，遂做做算法题。所有题解均不严格遵守输入输出规范，旨在算法设计、套路总结和错误处理。
题目来自《算法竞赛入门经典（第二版）》。

### 题解编号

所有题解均已`[cep]-chapter_num-problem_num.cpp`的方式命名。
其中`p`表示practice，指代每一章节的习题。例如，`p3-6.cpp`是原书习题3-6（Crossword Answers, ACM/ICPC World Finals 1994）。
`e`表示example，指代每一章节的习题。`c`指代每章非例题部分的案例。
例如，`c3-3.cpp`是原书第40页的"蛇形填数"。

全部题解均是自己独立思考后给出，没有参照任何网上材料。不保证能通过所有测试用例。


### 注意事项

* 常数pi的申明：`const double pi = acos(-1.0);`
* 验证平方数的方法：
  ```C++
  int m = floor(sqrt(s) + 0.5);
  if (m*m == s) {
      printf("%d\n", s);
  }
  ```
* 保证数字运算不溢出，使用`long long`存储数据：
  ```C++
  scanf("%d", &n);
  long long n2 = n; 
  ```
* 善用条件编译指令`#ifdef`和输入输出重定向：
  ```C++
  #define LOCAL
  #ifdef LOCAL
      // TODO: 将stdin和stdout重定向为文件
      freopen("../e2-5-data.in", "r", stdin);
      freopen("../e2-5-data.out", "w", stdout);
  #endif
  ```
* 使用文本流：
  ```C++
  FILE *fin, *fout;
  fin = fopen("../e2-5-data.in", "rb");
  fout = fopen("../e2-5-data.out", "wb");
  // ...
  fclose(fin);
  fclose(fout);
  ```
* 读取不给定输入个数的多个输入：
  ```C++
  int n;
  while (scanf("%d", &n) == 1) {
      // do sth.
  }
  ```
* 比较大的数组应当申明在函数外（堆而非栈上）：
  ```C++
  #define SIZE 105
  int c31_arr[SIZE];
  ```
* 使用`first`消除最后一个元素打印时的空格：
  ```C++
  int first = 1;
    for (int i = 1; i <= n; i++) {
        // TODO: 使用first消除最后一个元素的空格
        if (c32_arr[i] == 1) {
            if (first) {
                printf("%d", i);
                first = 0;
            } else {
                printf(" %d", i);
            }
        }
    }
  ```
* 使用`memset`设置数组元素的统一初值：
  ```C++
  memset(arr, 0, sizeof(arr));
  ```
* 使用`scanf`直接将文本读入字符数组中。`scanf`遇到空白字符（空格、Tab等）就会停下来：
  ```C++
  char s[20];
  scanf("%s", s);
  ```
* 使用`sprintf`直接将变量的字面量作为字符写入字符数组中：
  ```C++
  // 当五个int变量的值分别为12、13、5、17、90时，
  // buf为"121351790"
  sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
  ```
* 使用`strlen`返回字符结束标记`\0`之前的字符个数。
* 使用`strchr`检查每个字符是否在字符串内：
  ```C++
  int ok = 1;
  for (int i = 0; i < strlen(buf); i++) {
      if (strchr(s, buf[i]) == NULL) {
          ok = 0;
      }
  }
  ```
* 关于字符读取的一些梳理：

   + 使用`scanf("%s", s)`可以读取一个字符串，但是它遇到空白字符就会停下；

   + 使用`fgetc(fin)`从输入流中读取一个字符。`fgetc`返回的其实是`int`变量，需要转换为`char`变量。
   `fgetc`在流的末尾会读取到一个特殊标记`EOF`。
   
   + 从标准输入流中读取一个字符，可以用`getchar()`，他等价于`fgetc(stdin)`。
   
   + 使用`fgets(buf, maxn, fin)`从`fin`中读取不超过`maxn-1`个字符，然后在末尾添加上`\0`。
   使用`fgets`可以读取完整的一行，这是因为它一旦读取到回车符，就会将`\n`作为最后一个有效字符。
* `type.h`提供了函数`isalpha()`, `isdigit()`, `isprint()`, `toupper()`, `tolower()`等。在合适的地方使用它们。