//
// Created by wangyz38535 on 2024/5/21.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <memory>

#include <vector>

using namespace std;



struct Sds {
    int32_t length;
    char buff[];
};


Sds GetBuffer(Sds * lpSds)
{
    Sds ret = *lpSds;
    return ret;
}

int main(int argc, char **argv) {
    std::allocator<char> alloc;


    Sds *lpSds = (Sds*)alloc.allocate(sizeof(Sds) + 124);
    lpSds->length = 124;

    alloc.


    auto sds = GetBuffer(lpSds);

    printf("sds lpBuff = %p, o lp = %p\n", sds.buff, lpSds->buff);
    alloc.deallocate()


    return 0;
}