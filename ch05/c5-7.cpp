//
// Created by hliangzhao on 2022/4/6.
//

// TODO: 随机数与STL测试

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// TODO: 头文件cstdlib中的rand()函数可以生成[0,RAND_MAX]内均匀分布的随机整数，其中RAND_MAX至少为32767。
//  如果想要生成[0,n]之间的随机整数，可以通过(int) rand() / RAND_MAX * n得到。
//  注意，这种方法在n很大的时候会有精度问题。


// TODO: 下面两个函数重载
void fill_random_int(vector<int> &v, int cnt) {
    v.clear();
    for (int i = 0; i < cnt; i++) {
        v.push_back(rand());
    }
}

// TODO: 这个函数和上一个相比，是不被推荐的，这是因为这个函数在栈上分配了内存空间给v。
//  当函数退出时，需要在堆上再次分配内存空间并将v的内容一一拷贝进去。这会带来开销。
//  更好的处理方式是传递引用。
vector<int> fill_random_int(int cnt) {
    vector<int> v;
    for (int i = 0; i < cnt; i++) {
        v.push_back(rand());
    }
    return v;
}

// TODO: 注意这里的参数是vector<int> &v，传递的使用引用，因此v会被内部的sort函数所改变。
//  如果不希望v被改变，则去掉&，这样v会被在栈上复制一遍然后进行sort，v本身不会被改变。
void test_sort(vector<int> &v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++) {
        assert(v[i] <= v[i + 1]);           // TODO：当谓词为false的时候会强行终止程序
    }
}

int main() {
    // TODO: 通过srand方法初始化随机数种子。此时种子被设置为time(NULL)。
    //  如果srand函数不被调用，则意味着隐式地调用了srand(1)。此时总是会得到相同的随机数。
    srand(time(nullptr));

    // 当不调用srand时，每次运行本程序，都将得到：
    // 16807
    // 282475249
    // 1622650073
    // 984943658
    // 1144108930
    // 470211272
    // 101027544
    // 1457850878
    // 1458777923
    // 2007237709
    // 这是因为默认的种子1已经被写入编译后的binary中了。
    for (int i = 0; i < 10; i++) {
        // TODO：如果在每次调用rand之前都调用一次srand，则输出的内容是完全相同的！
        //  想要在程序内多次调用rand得到不同随机数，只需要在程序开始处调用一次srand即可。
//        srand(time(nullptr));
        cout << rand() / (double) RAND_MAX << endl;
    }

    vector<int> v;
    fill_random_int(v, 1000000);
    test_sort(v);

    return 0;
}

// TODO: 总结：
//  (1) vector set map都很快，vector的速度接近数组；
//  (2) set map的速度远超过「用一个vector保存全部元素然后按顺序依次查找给定元素」的速度；
//  (3) set map的每次插入、查找和删除的时间开销和元素个数的对数呈线形关系 O(log(n))。
