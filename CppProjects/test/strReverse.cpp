#include "../incl/header/strUtils.hpp"
#include <cstdio>

int main(){

    std::string test = "abcdefg";
    printf("%s\n", test.c_str());
    std::string test2 = strUtils::stringReverse(test);
    printf("%s\n", test2.c_str());

    return 0;
}