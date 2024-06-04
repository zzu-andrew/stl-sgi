//
// Created by wangyz38535 on 2024/5/21.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <memory>
#include <numeric>

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


    std::vector<int> v = {1, 2, 3,4,5};

    // 打印原始序列
    for (int i : v)
        std::cout << i << ' ';
    std::cout << '\n';

    do {
        // 打印当前排列
        for (int i : v)
            std::cout << i << ' ';
        std::cout << '\n';
    } while (std::next_permutation(v.begin(), v.end()));

    return 0;

    return 0;
}