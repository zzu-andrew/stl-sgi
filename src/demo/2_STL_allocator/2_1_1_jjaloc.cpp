//
// Created by andrew on 2024/5/16.
//

#include "2_1_1_jjalloc.h"
#include <vector>
#include <iostream>
#include <map>
using namespace std;

#define __ALIGN 8

// 函数实现向上取整，取整的进制按照对其字节来
int round_up(int b) {
    // 1. 先 (((b) + __ALIGN - 1)  保证尾部为(1-7)都会进一
    // 2. ~(__ALIGN - 1) 取出7 并安位取反
    // 3. 将1和2按位取与，得出的结果就是向上取整
    return (((b) + __ALIGN - 1) & ~(__ALIGN - 1));
}


int main() {
    int ia[5] = {0, 1, 2, 3, 4};
    int i;

    vector<int, JJ::allocator<int> > iv(ia, ia + 5);
    for (i = 0; i < iv.size(); i++) {
        cout << iv[i] << ' ';
    }
    cout << endl;

    cout << ~(__ALIGN - 1) << endl;
    cout << round_up(3) << endl;
    cout << round_up(15) << endl;

    std::map<int, int> give_me_a_name;

    std::find(give_me_a_name.begin(), give_me_a_name.end(), 12);




    return 0;
}












