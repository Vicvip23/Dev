#include <iostream>
#include <string>
#include <cmath>
#include "../incl/header/baseConversion.hpp"

int main(){

    int convType;
    int inputDec;
    std::string inputBin;

    std::cout << "Select conversion type:\nDecimal to Binary (input 1)\nBinary to Decimal (input 2)\nBinary to Hexadecimal (input 3)\n";
    std::cin >> convType;

    switch(convType){
        case 1:
            std::cout << "Input your Decimal number: ";
            std::cin >> inputDec;
            std::cout << "The resulting Binary number is: " << baseConversion::toBinary(inputDec);
        break;

        case 2:
            std::cout << "Input your Decimal number: ";
            std::cin >> inputBin;
            std::cout << "The resulting Binary number is: " << baseConversion::toDecimal(inputBin);
        break;

        case 3:
            std::cout << "Input your Decimal number: ";
            std::cin >> inputBin;
            std::cout << "The resulting Binary number is: " << baseConversion::toHex(inputBin);
        break;
    };
};