//
// Created by wangyz38535 on 2024/5/21.
//

#include <iostream>


template<typename T>
class C{
public:
    C() {
        std::cout << "C" << std::endl;
    }
};    // 这个泛化版本允许接收T为任何型别

/*******************************/
template<typename T>
class C<T*> {
public:
    C() {
        std::cout << "T*" << std::endl;
    }
}; // 这个特化版本仅适用于T为原生指针的情况，
// T为原生指针，也是对T为任何型别的一个更进一步的条件限制


struct Name {

};


int main(int argc, char **argv) {

    C<Name*> c;



    return 0;
}