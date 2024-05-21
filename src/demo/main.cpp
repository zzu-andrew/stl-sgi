//
// Created by wangyz38535 on 2024/5/21.
//

#include <iostream>

template <class T>
struct MyIter {
    typedef T value_type;  // 内嵌型别声明(netsted type)
    T* ptr; //
    explicit MyIter(T* p = 0) : ptr (p) {}
    T& operator*() const { return *ptr;}
    // ...
};

template <class I>
typename I::value_type   // 这里是函数的返回值
func (I ite)
{
    return ite;
}


// 使用原生指针类型，或者模板类中没有特意特化T*的类型，当函数按照指针进行调用时上述函数是无法推导出返回value_type是什么的


int main(int argc, char **argv) {




    return 0;
}