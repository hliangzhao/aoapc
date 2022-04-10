//
// Created by hliangzhao on 2022/4/10.
//

/* Revenge of Fibonacci */

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

// TODO: 本代码仍然无法通过所有测试用例，而且较慢。当结果大于1w时，就输出-1了。估计原因是：大整数仍然溢出了。
//  上网找找AC的代码

struct p515_BigInteger {
    static const int BASE = 100000000;
    static const int WIDTH = 8;

    // 位数越低，存放位置越靠前
    vector<int> s;

    p515_BigInteger &operator=(long long num) {
        s.clear();
        do {
            s.push_back((int) num % BASE);
            num /= BASE;
        } while (num > 0);
        return *this;
    }

    p515_BigInteger &operator=(const string &str) {
        s.clear();
        int x, len = ((int) str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++) {
            int end = (int) str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            // 可以使用sstream或sscanf
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }

    explicit p515_BigInteger(long long num = 0) {
        *this = num;
    }

    p515_BigInteger operator+(const p515_BigInteger &b) const {
        p515_BigInteger c;
        c.s.clear();
        for (int i = 0, g = 0;; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if (i < s.size()) {
                x += s[i];
            }
            if (i < b.s.size()) {
                x += b.s[i];
            }
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }

    p515_BigInteger operator+=(const p515_BigInteger &b) {
        *this = *this + b;
        return *this;
    }

    bool operator<(const p515_BigInteger &b) const {
        if (s.size() != b.s.size()) {
            return s.size() < b.s.size();
        }
        for (int i = (int) s.size() - 1; i <= 0; i--) {
            if (s[i] != b.s[i]) {
                return s[i] < b.s[i];
            }
        }
        // 到这里意味着相等
        return false;
    }

    bool operator>(const p515_BigInteger &b) const {
        return b < *this;
    }

    bool operator<=(const p515_BigInteger &b) const {
        return !(b < *this);
    }

    bool operator>=(const p515_BigInteger &b) const {
        return !(*this < b);
    }

    bool operator!=(const p515_BigInteger &b) const {
        return b < *this || *this < b;
    }

    bool operator==(const p515_BigInteger &b) const {
        return !(b < *this || *this < b);
    }
};

ostream &operator<<(ostream &out, const p515_BigInteger &x) {
    out << x.s.back();
    for (int i = (int) x.s.size() - 2; i >= 0; i--) {
        char buf[20];
        sprintf(buf, "%08d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++) {
            out << buf[j];
        }
    }
    return out;
}

istream &operator>>(istream &in, p515_BigInteger &x) {
    string s;
    if (!(in >> s)) {
        return in;
    }
    x = s;
    return in;
}

vector<p515_BigInteger> p515_2_v;

int main() {
    freopen("../ch05/p5-15-data.in", "r", stdin);

    p515_BigInteger a, b, tmp, res;
    a = 1;
    b = 1;
    p515_2_v.emplace_back(a);
    p515_2_v.emplace_back(b);
    unsigned long long i = 2;
    while (i < 10000) {
        stringstream ss;
        ss << a + b;
        ss >> res;
        p515_2_v.push_back(res);

        tmp = b;
        b = a;
        a += tmp;
        i++;
    }

    int T, kase = 1;
    scanf("%d\n", &T);
    string line;
    while (T--) {
        cout << "Case #" << kase++ << ": ";
        int found = 0;
        cin >> line;
        for (i = 0; i < p515_2_v.size(); i++) {
            // TODO：判断p515_2_v[i]是否以line开头
            stringstream ss;
            string val;
            ss << p515_2_v[i];
            ss >> val;
            // TODO：掌握rfind的用法！
            if (val.rfind(line, 0) != string::npos) {
                found = 1;
                cout << i << endl;
                break;
            }
        }
        if (!found) {
            cout << "-1" << endl;
        }
    }
    return 0;
}