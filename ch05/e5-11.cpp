//
// Created by hliangzhao on 2022/4/7.
//

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

// TODO: 注意这里string头文件提供的截取子串的方法
void parse_addr(const string &s, string &user, string &mta) {
    int k = (int) s.find('@');
    user = s.substr(0, k);
    mta = s.substr(k + 1);
}

int main() {
    freopen("../ch05/e5-11-data.in", "r", stdin);

    int k;
    string s, t;
    set<string> addr;           // addr存放所有的邮箱地址

    // TODO：while条件中的 cin >> s 读入的是"MTA"或者下一行的"*"
    while (cin >> s && s != "*") {
        // TODO: 这个cin读取到的正好就是MTA的名字（如London）和用户个数了
        cin >> s >> k;
        while (k--) {
            cin >> t;
            t += "@" + s;
            addr.insert(t);
        }
    }

    string user1, mta1, user2, mta2;
    // TODO：while条件中的 cin >> s 读入的是发送者的地址或者下一行的"*"
    while (cin >> s && s != "*") {
        parse_addr(s, user1, mta1);

        vector<string> target_mta;
        map<string, vector<string>> dest;
        set<string> visited_addr;
        // TODO：while条件中的 cin >> s 读入的是收件者的地址或者下一行的"*"
        while (cin >> t && t != "*") {
            // TODO：将这个收件者邮箱存入对应的mta里
            parse_addr(t, user2, mta2);
            if (visited_addr.count(t)) continue;
            visited_addr.insert(t);
            if (!dest.count(mta2)) {
                target_mta.push_back(mta2);
                dest[mta2] = vector<string>();
            }
            dest[mta2].push_back(t);
        }
        // TODO：把"*"这一行的回车吃掉！
        getline(cin, t);

        string data;
        while (getline(cin, t) && t[0] != '*') {
            data += "     " + t + "\n";
        }
        // 按照收件者的mta出现的顺序，依次处理每个mta
        for (int i = 0; i < target_mta.size(); i++) {
            string mta2 = target_mta[i];
            // 取出本mta下的目的地址
            vector<string> users = dest[mta2];
            cout << "Connection between " << mta1 << " and " << mta2 << endl;
            cout << "     HELO " << mta1 << endl << "     250" << endl;
            cout << "     MAIL FROM:<" << s << ">" << endl << "     250" << endl;
            bool ok = false;
            for (int j = 0; j < users.size(); j++) {
                cout << "     RCPT TO:<" << users[j] << ">" << endl;
                if (addr.count(users[j])) {
                    ok = true;
                    cout << "     250" << endl;
                } else {
                    cout << "     550" << endl;
                }
            }
            if (ok) {
                // 只有当用户是存在的时候，才会发送data字段
                cout << "     DATA" << endl << "     354" << endl;
                cout << data;
                cout << "     ." << endl << "     250" << endl;
            }
            cout << "     QUIT" << endl << "     221" << endl;
        }
    }
    return 0;
}