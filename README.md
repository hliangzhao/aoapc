## AOAPC

论文看多了，觉得打代码十分手生，遂做做算法题。所有题解均不严格遵守输入输出规范，旨在算法设计、套路总结和错误处理。
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

* 常数pi的申明：`const double pi = acos(-1.0)`。注意引用`cmath`头文件。
* 验证平方数的方法：
  ```C++
  #include <cmath>
  int mapper = floor(sqrt(s) + 0.5);
  if (mapper * mapper == s) {
      printf("%d\n", s);
  }
  ```
* 当问题规模很大时，为了保证数字运算不溢出，可以使用`long long`存储数据：
  ```C++
  int n;
  scanf("%d", &n);
  long long n2 = n; 
  ```
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
  #include <cstdio>
  
  #define LOCAL
  #ifdef LOCAL
      // 将stdin和stdout重定向为文件
      freopen("../ch02/e2-5-data.in", "r", stdin);
      freopen("../ch02/e2-5-data.out", "w", stdout);
  #endif
  ```
  使用重定向可以在本地对代码进行测试。提交时，只需要注释掉`#define LOCAL`即可。
* 使用文本流 —— 从文本流中读取数据、将数据写入文本流。
  ```C++
  #include <cstdio>
  
  FILE *fin, *fout;
  fin = fopen("../ch02/e2-5-data.in", "rb");
  fout = fopen("../ch02/e2-5-data.out", "wb");
  while (fscanf(fin, "%d", &x) == 1) {
      // do sth...
  }
  
  // close stream
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
* 比较大的数组应当申明在函数外（在堆而非栈上，防止栈溢出）：
  ```C++
  #define SIZE 1000000 + 5
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
* 熟练运用「逻辑运算符是短路运算」的特点。
  例如，想检查一个数组的某个位置上的元素是否为需要的数字，首先需要判断这个位置是否合法，然后判断上面存放的数字。
  如果不合法，则数组元素引用不会发生。
  ```C++
  // 如果i不在[0,n)之间，则arr[i]这个元素不会被检查
  if (!(i < 0 || i >= n) && arr[i] == 1) {
      // do sth.
  }
  ```
  具体可以参见`c3-3`。
* 使用`scanf`直接将文本读入字符数组中。`scanf`遇到空白字符（空格、Tab等）就会停下来：
  ```C++
  char s[20];
  scanf("%s", s);
  ```
  使用`fscanf`可以从文本流中读取。上面已经有了一个例子。
* 使用`sprintf`直接将变量的字面量作为字符写入字符数组中：
  ```C++
  char buf[99];
  // 当五个int变量的值分别为12、13、5、17、90时，
  // buf为"12xyz1351790"
  sprintf(buf, "%dxyz%d%d%d%d", abc, de, x, y, z);
  ```
* 使用`strlen`返回字符结束标记`\0`之前的字符个数。
* 使用`strchr`检查某一个字符是否在字符串内：
  ```C++
  #include <cstring>
  
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
  #include <cstdlib>
  
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
* 使用`cin`和`cout`进行IO比`scanf`和`printf`更加方便，但是要慢一些。需要观察题目情况合理进行选择。
  使用`scanf`进行读取时，如果输入有多行，则需要注意把换行符也读进来，否则会造成后续读取错误。
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
  // 从数组[a[0], ..., a[n-1]]中按照index增加的顺序找到元素b
  int pos = lower_bound(a, a+n, b) - a;
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
  map<Set, int> IDCache;
  
  // 存放所有已经出现的集合（的集合）。元素的下标就是集合（的集合）所映射到的整数。
  // SetCache和IDCache相互交换kv
  vector<Set> SetCache;
  
  // 题目中的栈
  stack<int> s;
  
  // 对应给定的Set，如没有id则创建，否则从cache中返回
  int get_id(const Set &x) {
      if (e59_IDCache.count(x)) {
          return IDCache[x];
      }
      SetCache.push_back(x);
      return IDCache[x] = (int) SetCache.size() - 1;
  }
  ```
* stack可以用于简单表达式的解析。具体案例参见`e6-3`。
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
      // 下面的错误极易犯！input.length()返回的是unsigned long类型，
      // 如果不转换为int类型，则-10000会被转换为unsigned和前者进行比较。
      // 因为符号（首位为1）是一个很大的unsigned数字，因此这个if不成立，从而导致max_len无法更新。
      if ((int) input.length() > max_len) {
          max_len = (int) input.length();
      }
  }
  ```
* 使用string头文件提供的截取子串的方法`substr`：
  ```C++
  // abc@alibaba.com
  void parse_addr(const string &s, string &user, string &mta) {
      int k = (int) s.find('@');
      user = s.substr(0, k);
      mta = s.substr(k + 1);
  }
  ```
* 学会「基于结构体和类」的思想设计程序。只需要为这些自定义数据结构重载一些方法，就可以将其放入用容器，从而利用容器和STL算法简化操作。
  具体案例参见`e5-12`、`p5-6`。
* 使用string的`rfind()`方法判断一个字符串是否以某个字符串开头：
  ```C++
  if (str1.rfind(str2, 0) != string::npos) {
      // 此时str1以str2开头
      // do sth.
  }
  ```
* 双端队列deque的使用案例参见`e6-1`。双端队列允许从队首或队尾插入元素。

#### 数据结构基础

* 当数组内的元素不能按照顺序方式读取的时候，可以引入一个新的数据`next`。`next[i]`记录第`i`个元素的下一个元素的index。这就是链表。
  链表不一定需要借助结构体和指针来实现。只凭借数组也可。具体案例参见`e6-4`。
* 双向链表可以借助两个额外的数组来实现，分别用`left[i]`和`right[i]`表示编号为`i`的元素的左节点和右节点。 
  则让两个节点互相连接的操作可以抽象为如下函数：
  ```C++
  void link(int L, int R) {
      right[L] = R;
      left[R] = L;
  }
  ```
  有些题目可以通过模拟操作的方式来实现，但实际上，有的时候并不需要真的去模拟每一个操作。
  如果一个操作很耗时，可以通过加标记的方式处理，而不需要真的执行这个操作。但是与此同时，其他所有操作都要考虑这个标记带来的影响。
  具体案例参见`e6-5`。
* 给定一棵包含`2^d`个节点的完全二叉树，如果把节点从上到下、从左到右依次编号为1、2、3...，则节点k的左右子节点的编号分别为`2 * k`和`2 * k + 1`。
* 二叉树的定义：
  + 一个标准的二叉树可以用「结构体 + 指针」的方式实现：
    ```C++
    // 节点结构体
    struct Node {
        bool have_value;
        int val;
        Node *left, *right;
    
        Node() : have_value(false), val(0), left(nullptr), right(nullptr) {}
    };
    
    // 通过new运算符申明新的内存空间。内部自动调用（对应的）构造函数，返回新分配的变量的地址
    Node *new_node() {
        return new Node();
    }
    
    // 全局的根节点
    Node *root;
    
    // 通过delete运算符释放u所代表的变量占用的空间。内部自动调用析构函数。
    void remove_tree(Node *u) {
        if (u == nullptr) return;
        remove_tree(u->left);
        remove_tree(u->right);
        delete u;
    }
    ```
  + 用数组也可以实现二叉树。需要三个数组，分别用于记录每个元素的左右子节点的编号以及该元素存放的数值（结构体）。
    ```C++
    // 节点结构体
    // 用cnt表示当前已存在的节点编号的最大值
    // 用left和right数组分别表示每个节点的左孩子和右孩子的编号（注意区分节点的编号和节点中存放的数值）
    // 用values数组记录每一个节点中存放的数值
    // 用have_value数组记录每一个节点是否已经被赋值
    int cnt;
    const int max_node_num = 256;
    int left[max_node_num], right[max_node_num];
    int values[max_node_num];
    bool have_value[max_node_num];

    // 根节点的编号为1
    const int root = 1;

    // 只需要重置计数器和根节点的左右子树即可清空整棵树
    void new_tree() {
        left[root] = right[root] = 0;
        have_value[root] = false;
        cnt = root;
    }

    // 创建一个节点，只需要初始化其左右子树即可。返回的是当前节点的编号
    int new_node() {
        int u = ++cnt;
        left[u] = right[u] = 0;
        have_value[u] = false;
        return u;
    }
    ```
  + 还可以使用「静态结构体数组 + 内存池技术」的方式存储节点和树。
    ```C++
    struct Node { 
        bool have_value;
        int val;
        Node *left, *right;

        Node() : have_value(false), val(0), left(nullptr), right(nullptr) {}
    };

    // 静态申请的结构体数组
    const int maxn = 256;
    Node nodes[maxn];

    // 空闲数组列表
    queue<Node *> free_nodes;
    // 初始化内存池
    void set_hex2bin() {
        for (auto &node : nodes) {
            free_nodes.push(&node);
        }
    }
    
    // 创建一个新的node，本质上就是从内存池中申请一个node空间占用
    Node *new_node() {
        Node *u = free_nodes.front();
        u->left = u->right = nullptr;
        u->have_value = false;
        free_nodes.pop();
        return u;
    }
    
    // 释放一个node，本质上就是将其放回空闲内存池中
    void delete_node(Node *u) {
        free_nodes.push(u);
    }
    
    // 全局的根节点
    Node *root;
    ```
* 可以用队列queue实现二叉树的层序遍历（宽度优先遍历BFS）：
  ```C++
  // 使用queue实现BFS [结构体 + 指针]
  bool dfs(vector<int> &ans) {    // 参数为引用类型
      queue<Node *> q;
      ans.clear();
      q.push(root);
      while (!q.empty()) {
          Node *u = q.front();
          q.pop();
          // 创建树的时候途径的节点都被构造出来了，但是如果一个节点没有数值意味着对应的输入存在问题
          if (!u->have_value) return false;
          ans.push_back(u->val);
          // 依次将左右子树插入队列尾部
          if (u->left != nullptr) q.push(u->left);
          if (u->right != nullptr) q.push(u->right);
      }
      return true;
  }
  
  // 使用queue实现BFS [数组]
  bool dfs(vector<int> &ans) {
      queue<int> q;
      ans.clear();
      q.push(root);
      while (!q.empty()) {
          int u = q.front();
          q.pop();
          // 创建树的时候途径的节点都被构造出来了，但是如果一个节点没有数值意味着对应的输入存在问题
          if (!have_value[u]) return false;
          ans.push_back(u);
          if (left[u] != 0) q.push(left[u]);
          if (right[u] != 0) q.push(right[u]);
      }
      return true;
  }
  ```
* 对于二叉树T，其深度优先遍历DFS有：
  + 先序遍历PreOrder：T的根节点，PreOder(T的左子树)，PreOder(T的右子树)
  + 中序遍历InOrder：InOrder(T的左子树)，T的根节点，InOrder(T的右子树)
  + 后序遍历PostOrder：PostOrder(T的左子树)，PostOrder(T的右子树)，T的根节点
* 对于树而言，递归和基于DFS的操作常常紧密结合。深入理解递归是进阶的重要前提。
* 图也有DFS和BFS。和树一样，前者可以通过递归来实现，后者可以借助队列来实现。
  求二维数组连通块（`e6-12`）是一个十分经典的问题，借助DFS来实现。本题题解要做到倒背如流。

### TODO

* 完成第4章剩下的8道习题。 
* 完成第5章剩下的6道习题。
* 整理自`e6-13`开始的内容。

### 当前进度

正在做第六章的例题部分。
