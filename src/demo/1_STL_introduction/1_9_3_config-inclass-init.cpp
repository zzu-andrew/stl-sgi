// file: 1config-inclass-init.cpp
// test in-class initialization of static const integral members
// ref. C++ Primer 3/e, p.643
// vc6[x] cb4[o] gcc[o]

// 静态整数常量在class内部直接初始化

#include <iostream>
using namespace std;

template <typename T>
class TestClass {
public:
    // 静态常量可以类内初始化
    // 静态成员变量必须类内声明，类外初始化
    static const int _datai = 5;
    static const long _datal = 3L;
    static const char _datac = 'c';
};

class TestName {
public:
    static const int x;
};
// 静态常量即能在类中 进行初始化也能在类外进行初始化
const int TestName::x = 12;


// 静态变量不能再类中进行初始化，只能放到类外进行初始化
//class TestName1 {
//public:
//    static int x = 12;
//};
// 静态常量即能在类中 进行初始化也能在类外进行初始化
//int TestName1::x = 12;

int main() {
    cout << TestClass<int>::_datai << endl;
    cout << TestClass<int>::_datal << endl;
    cout << TestClass<int>::_datac << endl;
}