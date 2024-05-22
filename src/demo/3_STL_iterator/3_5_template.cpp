//
// Created by wangyz38535 on 2024/5/22.
//

#include <iostream>

template<typename T>
class TraitsTest
{
public:
    /// The pointer type
    typedef T* pointer;
    /// The type pointed to
    typedef T  element_type;
    /// Type used to represent the difference between two pointers
    typedef ptrdiff_t difference_type;

    template<typename D>
    using rebind = D*;
};

class Data {
public:
    // 如果一个模板类中有内部模版，也就是类型内部模版-内部模版
    // 首先实例化 TraitsTest模板，并在这个作用域中继续实例化内部模板
    using type = typename TraitsTest<float>::template rebind<int>;


private:
    TraitsTest<Data> traits;
    type name;
};


int main(int argc, char* argv[]) {




    return 0;
}
