// file: 1functor.cpp

#include <iostream>
using namespace std;

namespace sil{
    // 重载了函数调用符()的类或结构体，为仿函数
    template <class T>
    struct plus {
        // const 后置修饰为常函数
        T operator() (const T& x, const T& y) const {
            return x + y;
        }
    };

    template <class T>
    struct minus {
        // const 后置修饰为常函数
        T operator() (const T& x, const T& y) const {
            return x - y;
        }
    };
}

int main() {
    // 生成仿函数对象
    sil::plus<int> plusobj;
    sil::minus<int> minusobj;
    // 仿函数可以像一般函数一样调用
    cout << plusobj(3, 5) << endl;
    cout << minusobj(3, 5) << endl;

    // 使用匿名对象，第一个括号是创建匿名对象，第二个括号死仿函数的操作符
    // 以下直接额产生仿函数的临时对象(第一对小括号)，并调用之（第二对小括号）
    cout << sil::plus<int>()(3, 5) << endl;
    cout << sil::minus<int>()(3, 5) << endl;
}