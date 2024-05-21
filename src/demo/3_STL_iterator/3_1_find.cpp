#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;



// 迭代器是㆒种行为类似指针的对象，对operator*和operator->进行重载
// 迭代器其实是一种智能指针
int main() {
    const int arraySize = 7;
    int ia[arraySize] = {0, 1, 2, 3, 4, 5, 6};

    vector<int> ivect(ia, ia + arraySize);
    list<int> ilist(ia, ia + arraySize);
    deque<int> ideque(ia, ia + arraySize);

    // 使用迭代器时需要注意，迭代器有两种类型，一种是流型，一种是红黑树类型
    auto it1 = find(ivect.begin(), ivect.end(), 4);
    if (it1 == ivect.end())
        cout << "4 not found." << endl;
    else
        cout << "4 found. " << *it1 << endl;

    auto it2 = find(ilist.begin(), ilist.end(), 6);
    if (it2 == ilist.end())
        cout << "6 not found." << endl;
    else
        cout << "6 found. " << *it2 << endl;

    auto it3 = find(ideque.begin(), ideque.end(), 8);
    if (it3 == ideque.end())
        cout << "8 not found." << endl;
    else
        cout << "8 found. " << *it3 << endl;

}