//
// Created by hliangzhao on 2022/4/9.
//

/* Borrowers */

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

const int max_author_num = 100;

int main() {
    freopen("../ch05/p5-8-data.in", "r", stdin);
    map<string, set<string>> lib;     // TODO: map（lib）在内部会自动按照key（作者）顺序排序
    map<string, string> title2author;
    string line;
    while (getline(cin, line) && line != "END") {
        string title, author;
        int k = (int) line.find("by");
        title = line.substr(0, k - 1);
        author = line.substr(k + 3);
        lib[author].insert(title);
        title2author[title] = author;
    }

    set<string> to_be_shelved;
    while (getline(cin, line) && line != "END") {
        if (line == "SHELVE") {
            // 依次取出to_be_shelved中的book，将它们放置在合适的位置上
            for (auto &title: to_be_shelved) {
                for (auto &it: lib) {
                    if (it.first == title2author[title]) {
                        it.second.insert(title);
                        break;
                    }
                }
            }
        } else {
            string act, title, author;
            // TODO: 注意，如果标题不包含双引号，则如下拆分方式不奏效。这里简单写一下，不影响整体思路
            int k = (int) line.find_first_of('\"');
            act = line.substr(0, k - 1);
            title = line.substr(k);
            if (act == "BORROW") {
                // 从lib中删除本书
                author = title2author[title];
                lib[author].erase(title);
            } else {
                // RETURN
                to_be_shelved.insert(title);
            }
        }
    }

    // 将所有图书按照顺序存入一个vector
    vector<string> all_books;
    for (auto &it: lib) {
        for (auto &book: it.second) {
            all_books.push_back(book);
        }
    }

    // 将to_be_shelved中的book按照先作者、后标题的方式排序
    set<string> tmp[max_author_num], authors;
    for (auto &it: lib) {
        authors.insert(it.first);
    }
    int idx = 0;
    for (auto &author: authors) {
        for (auto &title: to_be_shelved) {
            if (author == title2author[title]) {
                tmp[idx].insert(title);
            }
        }
        idx++;
    }

    for (int j = 0; j < idx; j++) {
        for (auto &title: tmp[j]) {
            for (int i = 0; i < all_books.size(); i++) {
                if (title == all_books[i]) {
                    if (i - 1 < 0) {
                        cout << "Put " << title << " first" << endl;
                    } else {
                        cout << "Put " << title << " after " << all_books[i - 1] << endl;
                    }
                }
            }
        }
    }
    cout << "END" << endl;

    return 0;
}
