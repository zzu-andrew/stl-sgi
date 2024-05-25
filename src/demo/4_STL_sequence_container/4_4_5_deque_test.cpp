// filename: 4deque-test.cpp

#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

class alloc {
};

int main() {


    deque<int>   testDeque;

    for (int kI = 0; kI < 100000; ++kI) {
        testDeque.push_back(kI);
    }

    std::cout << *testDeque.begin() << " " << std::endl;




    deque<int, allocator<int>> ideq(20, 9);
    cout << "size=" << ideq.size() << endl;

    for (int i = 0; i < ideq.size(); ++i)
        cout << ideq[i] << ' ';
    cout << endl;

    for (int i = 0; i < 3; ++i)
        ideq.push_back(i);

    for (int i = 0; i < ideq.size(); ++i)
        cout << ideq[i] << ' ';
    cout << endl;
    cout << "size=" << ideq.size() << endl;

    ideq.push_back(3);
    for (int i = 0; i < ideq.size(); ++i)
        cout << ideq[i] << ' ';
    cout << endl;
    cout << "size=" << ideq.size() << endl;

    ideq.push_front(99);
    for (int i = 0; i < ideq.size(); ++i)
        cout << ideq[i] << ' ';
    cout << endl;
    cout << "size=" << ideq.size() << endl;

    ideq.push_front(98);
    ideq.push_front(97);
    for (int i = 0; i < ideq.size(); ++i)
        cout << ideq[i] << ' ';
    cout << endl;
    cout << "size=" << ideq.size() << endl;

    deque<int, allocator<int>>::iterator itr;
    itr = find(ideq.begin(), ideq.end(), 99);
    cout << *itr << endl;
    cout << *(itr._M_cur) << endl;
}