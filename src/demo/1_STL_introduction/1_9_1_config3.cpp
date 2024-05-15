// file: 1config3.cpp
// 测试在 class template中 拥有 static data members.
// test __STL_STATIC_TEMPLATE_MEMBER_BUG, defined in <stl_config.h>
// ref. C++ Primer 3/e, p.839
// vc6[o] cb4[x] gcc[o]
// cb4 does not support static data member initialization.

// 如果编译器无法处理static member of template classes(模板类静态成员)就定义。
// 即对于模板类中，模板类型不同时的静态变量不同。

#include <iostream>
using namespace std;

template <typename T>
class TestClass {
public:  // 这里使用public纯粹是为了方便测试
    static int _data;
};

// 需要加上template<>，否则编译出错，进行内存配置
// 为 static data members 进行定义（配置内存），并设初始 值
// 特例化
template<> int TestClass<int>::_data = 1;  // 为int类型实例化TestClass时，_data初始化为1
template<> int TestClass<char>::_data = 2;   // 为char类型实例化TestClass时，_data初始化为2

// 以下注释来自gcc编译运行结果
/*
1
2
1 1
2 2
3 3
4 4
*/
int main() {

    cout << TestClass<int>::_data << endl;  // 1
    cout << TestClass<char>::_data << endl;  // 2

    TestClass<int> obji1, obji2;
    TestClass<char> objc1, objc2;
    cout << obji1._data << " " << obji2._data << endl;  // 1
    cout << objc1._data << " " << objc2._data << endl; // 2

    TestClass<int>::_data = 3;
    TestClass<char>::_data = 4;

    cout << obji1._data << " " << obji2._data << endl;   // 3
    cout << objc1._data << " " << objc2._data << endl;   // 4
}