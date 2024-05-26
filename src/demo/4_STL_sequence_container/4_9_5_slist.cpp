// file: 4slist-test.cpp

// g++ (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0
// gcc (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0 也没有这个库文件
// mingw64没有这个库
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int i;




    slist<int> islist;
    cout << "size=" << islist.size() << endl;
    islist.push_front(9);
    islist.push_front(1);
    islist.push_front(2);
    islist.push_front(3);
    islist.push_front(4);

    cout << "size=" << islist.size() << endl;

    slist<int>::iterator ite =islist.begin();
    slist<int>::iterator ite2=islist.end();
    for(; ite != ite2; ++ite)
        cout << *ite << ' ';
    cout << endl;

    ite = find(islist.begin(), islist.end(), 1);
    if (ite!=0)
        islist.insert(ite, 99);
    cout << "size=" << islist.size() << endl;
    cout << *ite << endl;

    ite =islist.begin();
    ite2=islist.end();
    for(; ite != ite2; ++ite)
        cout << *ite << ' '; // size=6
    cout << endl;

    ite = find(islist.begin(), islist.end(), 3);
    if (ite!=0)
        cout << *(islist.erase(ite)) << endl;

    ite =islist.begin();
    ite2=islist.end();
    for(; ite != ite2; ++ite)
        cout << *ite << ' ';
    cout << endl;
}
