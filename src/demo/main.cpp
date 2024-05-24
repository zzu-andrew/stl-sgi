//
// Created by wangyz38535 on 2024/5/21.
//

#include <iostream>
#include <algorithm>
#include <cstring>


class XorString
{
public:
    char operator()(const char * lpStr) {

        std::cout << "char *" << std::endl;
        auto len = strlen(lpStr);
        int32_t result = 0;
        for (auto i = 0; i < len; i++) {
            result ^= lpStr[i];
        }
        return (char)result;
    }


    char operator()(const std::string& str) {
        std::cout << "&" << std::endl;
        int32_t result = 0;
        for (char i : str) {
            result ^= i;
        }
        return (char )result;
    }

    char operator()(const std::string&& str) {
        std::cout << "&&" << std::endl;
        return operator()(str);
    }

};





int main(int argc, char **argv) {


    XorString    xorString;


    std::cout << (int) xorString("test")<< std::endl;

    std::string name = "test";

    std::cout << (int)xorString(name) << std::endl;
    std::cout << (int)xorString(std::move(name)) << std::endl;


    return 0;
}