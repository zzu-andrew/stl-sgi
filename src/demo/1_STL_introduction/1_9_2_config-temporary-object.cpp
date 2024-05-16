// file: 1config-temporary-object.cpp
// 本例测试仿函式用于 for_each()的情形
// vc6[o] cb4[o] gcc[o]

// 匿名对象使用

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class print {
public:
    void operator() (const T& elem) {
        cout << elem << ' ';
    }
};

template <>
class print<int> {
public:
    void operator() (const int& elem) {
        cout << elem << " int ";
    }
};

int main() {
    int ia[6] = {0, 1, 2, 3, 4, 5};
    vector<int> iv(ia, ia + 6);

    // print<int>() 是一个匿名对象
    for_each(iv.begin(), iv.end(), print<int>());
}