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


#### C输入输出与常用套路

* 常数pi的申明：`const double pi = acos(-1.0);`
* 验证平方数的方法：
  ```C++
  int mapper = floor(sqrt(s) + 0.5);
  if (mapper * mapper == s) {
      printf("%d\n", s);
  }
  ```
* 保证数字运算不溢出，使用`long long`存储数据：
  ```C++
  scanf("%d", &n);
  long long n2 = n; 
  ```
* 熟练运用「逻辑运算符是短路运算」的特点。 
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
      // 将stdin和stdout重定向为文件
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
* 使用指示变量`first`消除最后一个元素之后可能会打印的空格：
  ```C++
  int first = 1;
    for (int i = 1; i <= n; i++) {
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
  // buf为"12xyz1351790"
  sprintf(buf, "%dxyz%d%d%d%d", abc, de, x, y, z);
  ```
* 使用`strlen`返回字符结束标记`\0`之前的字符个数。
* 使用`strchr`检查每个字符是否在字符串内：
  ```C++
  int ok = 1;
  for (int i = 0; i < strlen(buf); i++) {
      // 若不在，则返回NULL
      if (strchr(s, buf[i]) == NULL) {
          ok = 0;
      }
  }
  ```
* 关于字符读取的一些梳理：

   + 使用`scanf("%s", s)`可以读取一个字符串，但是它遇到空白字符就会停下；

   + 使用`fgetc(fin)`从输入流`fin`中读取一个字符。`fgetc`返回的其实是`int`变量，需要转换为`char`变量。
   `fgetc`在流的末尾会读取到一个特殊标记`EOF`。
   
   + 从标准输入流中读取一个字符，可以用`getchar()`，他等价于`fgetc(stdin)`。
   
   + 使用`fgets(buf, maxn, fin)`从`fin`中读取不超过`maxn-1`个字符到字符数组`buf`，然后在末尾添加上`\0`。
   使用`fgets`可以读取完整的一行，这是因为它一旦读取到回车符，就会将`\n`作为最后一个有效字符。
* `type.h`提供了函数`isalpha()`, `isdigit()`, `isprint()`, `toupper()`, `tolower()`等。在合适的地方使用它们。
* 比较环状字符串的字典顺序：
  ```C++
  // p和q分别是起始位置
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
* 当题目给定了结果的范围，这时可以通过「先（枚举）计算后查表」的方式求解（参见`p3-5`和`p3-12`）。
* C语言中的数组为定长数组，数组长度可用常数、`const int len = 100`或`#define SIZE 100`中的常量来标记。
* 掌握`sscanf`的使用。这个函数从一个字符串中按照类似正则表达式匹配的方式读取到我们想要的变量值（参见`p3-12`）。
* 对于如阶乘之类的复杂运算，最好在计算过程中就进行简化，以免中间结果溢出。
* 判断是否是素数的高效实现：
  ```C++
  int is_prime(int n) {
      if (n <= 1) return 0;
      // 有一个小因子，就必然有一个与之对应的大因子，因此只需要判断前半部分是否存在因子即可
      int mapper = floor(sqrt(n) + 0.5);
      for (int i = 2; i <= mapper; i++) {
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
  int cnt1[26], cnt2[26];
  
  // 注意，cmp的参数为const void *类型，在使用时转换成对应的数据类型指针
  int cmp(const void *a, const void *b) {
      // 若lhs > rhs，则返回正数
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
  这个时候，在打印输出时，可以加上一个比输出精度小几个数量级的一个小数`EPS`来缓解由此带来的问题。
* `p4-5`给出了按位与运算的一个示例（找到最小网段）。
* 使用`cin`和`cout`进行IO比`scanf`和`printf`更加方便。但是要慢一些。观察题目情况合理进行选择。
  使用`scanf进行读取时，如果输入有多行，则需要注意把换行符也读进来，否则会造成后续读取错误。
* 使用参数引用作为函数参数（实参与形参）：
  ```C++
  void my_swap(int &a, int &b) {
      int t = a;
      a = b;
      b = t;
  }
  ```


#### C++基础与套路

* 多行输入的处理：
  + C语言的`getchar`写法。不断读入字符，根据它是换行符、EOF、空格还是数字进行相应的处理。
    如果输入有小数、负数，则处理起来会更加麻烦。
  + C++语言中，使用`getline`直接读取一行内容到字符串中，创建一个字符串流`stringstream`，然后从字符串中读取出想要的变量值（和`sscanf`类似）。
  
  具体内容参加`c5-3`。
* C++中的结构体、构造函数与运算符重载的案例，参见`c5-4`。
* C++中的模版的案例，参见`c5-5`和`c5-6`。
* C++中关于生成随机数相关的思考、总结和误区参考`c5-7`。
* `c5-8`提供了大整数类BigInteger的实现。其思路为：以1亿作为基底，而非10。
  整个操作都是将以10进位的模式改为以1亿进位。`c5-8`给出了这个结构体的实现、对应方法的重载等。需要彻底掌握。


#### STL与容器的熟练使用

* 利用`algorithm`头文件提供的`sort`、`lower_bound`等方法简化代码：
  ```C++
  int a[100], n = 100;
  
  // 排序
  sort(a, a + n);
  
  // lower_bound()适合对已经排好序的数组使用
  int pos = lower_bound(a, a+n, b[i]) - a;
  ```
* 关于vector的使用参考`e5-2`。总结如下：
  + 首先，需要引入`#include <vector>`；
  + 使用`clear()`清空，`size()`获取大小，`resize()`改变大小；
  + 使用`push_back()`和`pop_back()`从末尾插入和删除元素；
  + 使用`empty()`测试是否为空。
  + vector之间可以直接赋值，vector也可以作为函数的返回值（一等公民）。
  + 既可以用类似数组的方式遍历vector，也可以使用`auto`关键字。
* 关于set的使用参考`e5-3`。
* set和map都支持`insert`、`erase`、`count`、`find`操作，后者还支持`[]`运算符。map使用`first`和`second`标识kv。
* 多种容器的配合使用参见`e5-5`。本题有如下几点值得细细玩味：
  + 将题目中自定义的「数据类型」映射到整数，从而使得STL提供的容器可以被使用（这种思想在`e5-9`中也得到了使用）；
  + 使用宏（这不是必须的）；
  + 对于stack本身，我们重点关注`push`, `pop`和`top`三种操作。
  ```C++
  // 将集合映射到整数，则集合的集合就是整数的集合
  typedef set<int> Set;
  
  // 记录集合的集合和对应的整数的映射关系
  map<Set, int> e59_IDCache;
  
  // 存放所有已经出现的集合（的集合）。元素的下标就是集合（的集合）所映射到的整数。
  // SetCache和IDCache相互交换kv
  vector<Set> SetCache;
  
  // 题目中的栈
  stack<int> e55_s;
  
  // 对应给定的Set，如没有id则创建，否则从cache中返回
  int get_id(const Set &x) {
      if (e59_IDCache.count(x)) {
          return e59_IDCache[x];
      }
      SetCache.push_back(x);
      return e59_IDCache[x] = (int) SetCache.size() - 1;
  }
  ```
* queue的使用案例参见`e5-6`。对于队列queue，我们重点关注`push`、`pop`和`front`三个操作。
* 优先队列的使用案例参见`e5-7`。优先队列使用`push`和`pop`入队和出队，但使用`top`取队首元素。
  + 默认情况下优先队列中「越小的元素优先级越低」，下面给出了一个案例：
    ```C++
    void test_pq1() {
        priority_queue<int> pq;
        // 入队顺序为2 3 1
        pq.push(2);
        pq.push(3);
        pq.push(1);
    
        // 新元素入队时会自动根据其优先级调整自身占位
  
        // 出队顺序为3 2 1
        while (!pq.empty()) {
            int val = pq.top();
            cout << val << endl;
            pq.pop();
        }
    }
    ```
  + 下面的案例中，我们自定义了一个「个位数越大的整数优先级越低」的优先队列：
    ```C++
    // 需要自己实现cmp仿函数。当a优先级低于b的时候，返回true
    struct cmp {
        bool operator()(const int a, const int b) {
            return a % 10 > b % 10;
        }
    };
  
    void test_pq2() {
        priority_queue<int, vector<int>, cmp> pq;
        // 入队顺序为33 12 11
        pq.push(33);
        pq.push(12);
        pq.push(11);
  
        // 出队顺序为11 12 33
        while (!pq.empty()) {
            int val = pq.top();
            cout << val << endl;
            pq.pop();
        }
    }
    ```
  + 下面的案例中，我们直接使用STL自带的仿函数创建一个「越小优先级越大」的优先队列：
    ```C++
    void test_pq3() {
        priority_queue<int, vector<int>, greater<int> > pq;
        // 入队顺序为2 3 1
        pq.push(2);
        pq.push(3);
        pq.push(1);
  
        // 出队顺序为1 2 3
        while (!pq.empty()) {
            int val = pq.top();
            cout << val << endl;
            pq.pop();
        }
    }
    ```
* `unsigned`和`int`进行比较时，极容易犯的一个错误：
  ```C++
  string input;
  
  cin >> n;
  while (cin >> input) {
      s.insert(input);
      // 下面的错误极易犯！input.length()返回的是unsigned long类型，如果不转换为int类型，则-10000会被转换为unsigned和前者进行比较。
      // 因为符号（首位为1）是一个很大的unsigned数字，因此这个if不成立，从而导致max_len无法更新。
      if ((int) input.length() > max_len) {
          max_len = (int) input.length();
      }
  }
  ```
* string头文件提供的截取子串的方法：
  ```C++
  // abc@alibaba.com
  void parse_addr(const string &s, string &user, string &mta) {
      int k = (int) s.find('@');
      user = s.substr(0, k);
      mta = s.substr(k + 1);
  }
  ```
* 积极「基于结构体和类」的思想涉及程序。只需要为这些自定义数据结构重载一些方法，就可以将其放入用容器，从而利用容器和STL算法简化操作。
  具体案例参见`e5-12`、`p5-6`。

### TODO

* 完成第4章剩下的8道习题。
