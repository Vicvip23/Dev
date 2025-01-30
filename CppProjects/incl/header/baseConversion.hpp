#include "../func/base/toBinary.cpp"
#include "../func/base/toDecimal.cpp"
#include "../func/base/toHex.cpp"
#include <string>

namespace baseConversion {
    int toDecimal(std::string n);
    std::string toBinary(int n);
    std::string toHex(std::string bin);
}