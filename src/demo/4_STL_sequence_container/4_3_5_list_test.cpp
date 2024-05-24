// file: list-test.cpp

#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int i;
    list<int> ilist;
    // 节点默认初始化为0个
    cout << "size=" << ilist.size() << endl;

    for (int j = 0; j < 5; j++) {
        ilist.push_back(j);
    }
    cout << "size=" << ilist.size() << endl;

    list<int>::iterator ite;
    for (ite = ilist.begin(); ite != ilist.end(); ++ite) {   // 0 1 2 3 4
        cout << *ite << ' ';
    }
    cout << endl;

    ite = find(ilist.begin(), ilist.end(), 3);
    if (ite != ilist.end()) {
        // 在3的后面插入99
        ilist.insert(ite, 99);
    }
    //size = 6
    cout << "size=" << ilist.size() << endl;
    cout << *ite << endl;  // 3

    // 0 1 2 99 3 4
    for (ite = ilist.begin(); ite != ilist.end(); ++ite) {
        cout << *ite << ' ';
    }
    cout << endl;

    ite = find(ilist.begin(), ilist.end(), 1);
    if (ite != ilist.end()) {
        // 2 , erase之后迭代器会指向下一个位置的数据
        cout << *(ilist.erase(ite)) << endl;
    }
    //0 2 99 3 4
    for (ite = ilist.begin(); ite != ilist.end(); ++ite) {
        cout << *ite << ' ';
    }
    cout << endl;

    int iv[5] = { 5,6,7,8,9 };
    list<int> ilist2(iv, iv+5);
    //目前，ilist的内容为 0 2 99 3 4
    ite = find(ilist.begin(), ilist.end(), 99);
    ilist.splice(ite, ilist2);

    for (ite = ilist2.begin(); ite != ilist2.end(); ++ite) {
        cout<<"===============" << *ite << ' ';
    }
    ilist.reverse();
    ilist.sort();


}