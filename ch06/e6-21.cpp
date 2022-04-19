//
// Created by hliangzhao on 2022/4/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

// IDCache记录从组件到ID的映射
map<string, int> IDCache;

// ItemCache记录所有已出现的组件
vector<string> ItemCache;

int get_id(const string &item) {
    if (IDCache.count(item)) {
        return IDCache[item];
    }
    ItemCache.push_back(item);
    return IDCache[item] = (int) ItemCache.size() - 1;
}

const int max_c = 80 + 5;
const int max_item_num = 100;
char line[max_c];
// depended_by[x]是组件x所依赖的组件集合
vector<int> depended_by[max_item_num];
// depend_on[x]是依赖于组件x的组件集合
vector<int> depend_on[max_item_num];
// 0: 未安装；1: 显式安装；2: 隐式安装（以依赖的方式被安装）
int status[max_item_num];
// 存放已安装的组件
vector<int> installed;

// 从父节点到子节点递归安装所有组件
void install(int item, bool top_level) {
    if (!status[item]) {
        for (int i : depended_by[item]) {
            install(i, false);
        }
        cout << "   Installing " << ItemCache[item] << endl;
        status[item] = top_level ? 1 : 2;
        installed.push_back(item);
    } else if (top_level) {
        // top_level用于区分这是外部调用还是递归调用
        cout << "   " << ItemCache[item] << " is already installed." << endl;
    }
}

// 如果存在依赖于item的组件，则说明本item被依赖
bool needed(int item) {
    for (int i : depend_on[item]) {
        if (status[i]) return true;
    }
    return false;
}

void uninstall(int item, bool top_level) {
    if (status[item] == 0) {
        cout << "   " << ItemCache[item] << " is not installed." << endl;
    }
        // 能被移除的只有通过隐式方式被安装的、且不被其他组件依赖的组件
    else if ((top_level || status[item] == 2) && !needed(item)) {
        status[item] = 0;
        // 将item移除
        // remove(installed.begin(), installed.end(), item)将item移到vector的末尾，并返回指向item的指针（超尾指针），
        // installed.end()则指向item之后的元素（installed真正的超尾指针），因此外部的erase方法将移除item
        installed.erase(remove(installed.begin(), installed.end(), item), installed.end());
        cout << "   Removing " << ItemCache[item] << endl;
        for (int i : depended_by[item]) {
            // 移除那些item的、不被别的组件需要的依赖
            uninstall(i, false);
        }
    } else if (top_level) {
        // top_level用于区分这是外部调用还是递归调用
        cout << "   " << ItemCache[item] << " is still needed." << endl;
    }
}

void list() {
    for (int i : installed) {
        cout << "   " << ItemCache[i] << endl;
    }
}

int main() {
    freopen("../ch06/e6-21-data.in", "r", stdin);

    while (fgets(line, max_c, stdin)) {
        printf("%s", line);
        string ins, item1, item2_and_after;
        stringstream ss(line);
        ss >> ins;
        if (ins == "END") break;
        else if (ins == "DEPEND") {
            ss >> item1;
            int i1_id = get_id(item1);
            while (ss >> item2_and_after) {
                int i2_id = get_id(item2_and_after);
                depend_on[i2_id].push_back(i1_id);
                depended_by[i1_id].push_back(i2_id);
            }
        } else if (ins == "INSTALL") {
            ss >> item1;
            int i1_id = get_id(item1);
            install(i1_id, true);
        } else if (ins == "REMOVE") {
            ss >> item1;
            int i1_id = get_id(item1);
            uninstall(i1_id, true);
        } else {
            // LIST
            list();
        }
    }
    return 0;
}
