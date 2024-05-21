//
// Created by wangyz38535 on 2024/5/21.
//

#include <iostream>


template<class T>
struct MyIter {
    typedef T value_type;  // 内嵌型别声明(netsted type)
    T *ptr; //
    explicit MyIter(T *p = 0) : ptr(p) {}

    T &operator*() const { return *ptr; }
    // ...
};

template<class I>
typename I::value_type   // 这里是函数的返回值
func(I ite) {
    return *ite;
}


int main(int argc, char **argv) {

    MyIter<int> ite(new int(8));
    std::cout << func(ite) << std::endl;


    return 0;
}