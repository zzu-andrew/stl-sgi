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





class Data {
public:
    Data () {
        std::cout << "test" << std::endl;
    }

    ~Data() {
        std::cout << "~test" << std::endl;

    }

    std::set<int32_t>   sets;
};




struct NamePair {
   bool operator <(const NamePair& other) const
   {
        return index < other.index;
   }

   int index;
   int xor1;
};




int main(int argc, char **argv) {


    std::set<int32_t> data1,data2,data3;
    data1.insert(1);
    data2.insert(1);
    data3.insert(1);

    auto sets = data1 + data2 + data3;





    return 0;
}