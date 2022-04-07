//
// Created by hliangzhao on 2022/4/6.
//

// TODO：大整数类

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// TODO：BigInteger的实现思路为：以1亿作为基底，而非10。整个操作都是将以10进位的模式改为以1亿进位。
struct BigInteger {
    // TODO：被static修饰的BigInteger::BASE的方式使用
    static const int BASE = 100000000;
    static const int WIDTH = 8;

    // 位数越低，存放位置越靠前
    vector<int> s;

    // TODO：重载赋值运算符
    BigInteger &operator=(long long num) {
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);
        return *this;
    }

    // TODO：重载赋值运算符
    BigInteger &operator=(const string &str) {
        s.clear();
        // TODO: 这里len的计算很有意思：(l + (w - 1)) / w
        int x, len = ((int) str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++) {
            int end = (int) str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            // 可以使用sstream或sscanf
            // TODO: 从一个字符串中截取一个子串并从中读取出想要的数据类型的写法！别忘了c_str()的调用
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }

    // TODO：构造函数
    BigInteger(long long num = 0) {
        // TODO: 这里利用了上面对赋值运算符的重载
        *this = num;
    }

    // TODO: 这里函数申明之后为什么会有一个const？是为了表明自身this不会被修改吗？（函数内的实现是将结果存入一个新的实例）
    //  参考https://github.com/hliangzhao/essentialCpp/tree/main/ch04
    BigInteger operator+(const BigInteger &b) const {
        BigInteger c;
        c.s.clear();
        for (int i = 0, g = 0;; i++) {
            // TODO：g是进位的结果，初值为0
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if (i < s.size()) {
                x += s[i];
            }
            if (i < b.s.size()) {
                x += b.s[i];
            }
            c.s.push_back(x % BASE);
            // TODO：进位的结果保存在g中，参与下一个位的运算
            g = x / BASE;
        }
        return c;
    }

    BigInteger operator+=(const BigInteger &b) {
        *this = *this + b;
        return *this;
    }

    // TODO: 下面这个函数正常工作的前提是参与比较的两者都没有前导0！
    bool operator<(const BigInteger &b) const {
        if (s.size() != b.s.size()) {
            return s.size() < b.s.size();
        }
        for (int i = s.size() - 1; i <= 0; i--) {
            if (s[i] != b.s[i]) {
                return s[i] < b.s[i];
            }
        }
        // 到这里意味着相等
        return false;
    }

    // TODO：用"<"派生出其他的比较运算符重载
    bool operator>(const BigInteger &b) const {
        return b < *this;
    }

    bool operator<=(const BigInteger &b) const {
        return !(b < *this);
    }

    bool operator>=(const BigInteger &b) const {
        return !(*this < b);
    }

    bool operator!=(const BigInteger &b) const {
        return b < *this || *this < b;
    }

    bool operator==(const BigInteger &b) const {
        return !(b < *this || *this < b);
    }
};

// TODO: 实现了如下两个方法后，sstream也自动支持BigInteger了（得益于继承机制）。

ostream &operator<<(ostream &out, const BigInteger &x) {
    out << x.s.back();
    for (int i = x.s.size() - 2; i >= 0; i--) {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++) {
            out << buf[j];
        }
    }
    return out;
}

istream &operator>>(istream &in, BigInteger &x) {
    string s;
    if (!(in >> s)) {
        return in;
    }
    x = s;
    return in;
}

int main() {
    BigInteger c1, c2;
    c1 = "123456789234829347239048239048";
    c2 = 1203239403249;
    cout << c1 + c2 << endl;
    return 0;
}