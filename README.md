## AOAPC

论文灌多了，觉得打代码十分手生，遂做做算法题。所有题解均不严格遵守输入输出规范，旨在算法设计、套路总结和错误处理。
题目来自《算法竞赛入门经典（第二版）》。

### 题解编号

所有题解均以`[cep]-chapter_num-problem_num.cpp`的方式命名。
其中`p`表示practice，指代每一章节的习题。例如，`p3-6.cpp`是原书习题3-6（Crossword Answers, ACM/ICPC World Finals 1994）。
`e`表示example，指代每一章节的习题。`c`指代每章非例题部分的案例。
例如，`c3-3.cpp`是原书第40页的"蛇形填数"。

全部题解均是自己独立思考后给出，除非不会做。
不保证能通过所有测试用例。


### 注意事项

* 常数pi的申明：`const double pi = acos(-1.0);`
* 验证平方数的方法：
  ```C++
  int m = floor(sqrt(s) + 0.5);
  if (m * m == s) {
      printf("%d\n", s);
  }
  ```
* 保证数字运算不溢出，使用`long long`存储数据：
  ```C++
  scanf("%d", &n);
  long long n2 = n; 
  ```
* 熟练运用"逻辑运算符"是短路运算的特点。 
  例如，想检查一个数组的某个位置上的元素是否为需要的数字，首先需要判断这个位置是否合法，然后判断上面存放的数字。
  如果不合法，则数组元素引用不会发生。
* 使用`clock()`函数测试程序运行时间：
  ```C++
  #include <ctime>
  
  int main() {
      // do sth...
      printf("Time used: %.6f sec\n", (double)clock() / CLOCKS_PER_SEC);
      return 0;
  }
  ```
* 善用条件编译指令`#ifdef`和输入输出重定向：
  ```C++
  #define LOCAL
  #ifdef LOCAL
      // TODO: 将stdin和stdout重定向为文件
      freopen("../ch02/e2-5-data.in", "r", stdin);
      freopen("../ch02/e2-5-data.out", "w", stdout);
  #endif
  ```
* 使用文本流：
  ```C++
  FILE *fin, *fout;
  fin = fopen("../ch02/e2-5-data.in", "rb");
  fout = fopen("../ch02/e2-5-data.out", "wb");
  while (fscanf(fin, "%d", &x) == 1) {
      // do sth...
  }
  fclose(fin);
  fclose(fout);
  ```
* 读取不给定输入个数的多个输入：
  ```C++
  int e4_5_n;
  while (scanf("%d", &n) == 1) {
      // do sth.
  }
  ```
* 比较大的数组应当申明在函数外（在堆而非栈上，防止栈溢出）：
  ```C++
  #define SIZE 105
  int arr[SIZE];
  
  void func() { ... }
  int main() {
      // ...
      return 1;
  }
  ```
* 使用`first`消除最后一个元素之后可能会打印的空格：
  ```C++
  int first = 1;
    for (int i = 1; i <= n; i++) {
        // TODO: 使用first消除最后一个元素的空格
        if (arr[i] == 1) {
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
  #include <cstring>
  memset(arr, 0, sizeof(arr));
  ```
* 使用`scanf`直接将文本读入字符数组中。`scanf`遇到空白字符（空格、Tab等）就会停下来：
  ```C++
  char s[20];
  scanf("%s", s);
  ```
  使用`fscanf`可以从文本流中读取。上面已经有了一个例子。
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
   
   + 使用`fgets(buf, maxn, fin)`从`fin`中读取不超过`maxn-1`个字符到字符数组`buf`，然后在末尾添加上`\0`。
   使用`fgets`可以读取完整的一行，这是因为它一旦读取到回车符，就会将`\n`作为最后一个有效字符。
* `type.h`提供了函数`isalpha()`, `isdigit()`, `isprint()`, `toupper()`, `tolower()`等。在合适的地方使用它们。
* 比较环状字符串的字典顺序：
  ```C++
  int less(char *s, int p, int q) {
      int n = strlen(s);
      for (int i = 0; i < n; i++) {
          if (s[(p + i) % n] != s[(q + i) % n]) {
              return s[(p + i) % n] < s[(q + i) % n];
          }
      }
      return 0;
  }
  ```
* 当题目给定了结果的范围，这时可以通过（枚举）计算后查表的方式求解（参见`p3-5`和`p3-12`）。
* C语言中的数组为定长数组，数组长度可用常数、`const int len = 100`或`#define SIZE 100`中的常量来标记。
* 掌握`sscanf`的使用。这个函数从一个字符串中按照类似正则表达式匹配的方式读取到我们想要的变量值（参见`p3-12`）。
* 对于如阶乘之类的复杂运算，最好进行简化，以免中间结果溢出。
* 判断是否是素数的高效实现：
  ```C++
  int is_prime(int n) {
      if (n <= 1) return 0;
      // 有一个小因子，就必然有一个与之对应的大因子，因此只需要判断前半部分是否存在因子即可
      int m = floor(sqrt(n) + 0.5);
      for (int i = 2; i <= m; i++) {
          if (n % i == 0) {
              return 0;
          }
      }
      return 1;
  }
  ```
* 将数组首地址作为函数参数的正确用法，参见`c4-6`和`c4-8`。
* 使用`cstdlib`的`qsort`函数对数组进行排序。需要自己实现`compare`函数。
  ```C++
  // 注意，cmp的参数为const void *类型，在使用时转换成对应的数据类型指针
  int cmp(const void *a, const void *b) {
      return *(int *) a - *(int *) b;
  }
  
  qsort(cnt1, 26, sizeof(int), cmp);
  qsort(cnt2, 26, sizeof(int), cmp);
  ```
* 读取跨行文本的几种方法参见`e4-4-1`和`e4-4-2`。
  + 方法1：拼接到一个大的字符数组中。
    ```C++
    char content[1000];
    int content_pos = 0;
    while (scanf("%s", tmp) == 1) {
        int tmp_len = strlen(tmp);
        for (int i = 0; i < tmp_len; i++) {
            content[i + content_pos] = tmp[i];
        }
        content_pos += tmp_len;
    }
    ```
  + 方法2：使用`getchar`。
    ```C++
    while (true) {
        int ch = getchar();
        if (ch == EOF) {
            return 0;
        }
        if (ch == '\n' || ch == '\r') {
            return 1;  // 换行继续读
        }
        code[len][i] = ch;
    }
    ```
* 浮点数在加减一个很小的小数时常常会面临精度问题。
  这个时候，在打印输出时，可以加上一个比输出精度小几个数量级的一个小数来缓解由此带来的问题。