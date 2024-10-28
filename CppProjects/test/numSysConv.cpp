#include <iostream>
#include <string>
#include <cmath>
#include "../incl/header/base.hpp"

using namespace std;

int main(){

    int convType;
    int inputDec;
    string inputBin;

    cout << "Select conversion type:\nDecimal to Binary (input 1)\nBinary to Decimal (input 2)\nBinary to Hexadecimal (input 3)\n";
    cin >> convType;

    switch(convType){
        case 1:
            cout << "Input your Decimal number: ";
            cin >> inputDec;
            cout << "The resulting Binary number is: " << toBinary(inputDec);
        break;

        case 2:
            cout << "Input your Decimal number: ";
            cin >> inputBin;
            cout << "The resulting Binary number is: " << toDecimal(inputBin);
        break;

        case 3:
            cout << "Input your Decimal number: ";
            cin >> inputBin;
            cout << "The resulting Binary number is: " << toHex(inputBin);
        break;
    };
};