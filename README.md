## AOAPC

---

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
  