#include <iostream>
#include <string>
#include <cmath>
#include <string>
#include <map>

using namespace std;

const map<string, string> binToHex = {
    {"0000", "0"},
    {"0001", "1"},
    {"0010", "2"},
    {"0011", "3"},
    {"0100", "4"},
    {"0101", "5"},
    {"0110", "6"},
    {"0111", "7"},
    {"1000", "8"},
    {"1001", "9"},
    {"1010", "A"},
    {"1011", "B"},
    {"1100", "C"},
    {"1101", "D"},
    {"1110", "E"},
    {"1111", "F"}
};

string toHex(string bin){

    string hex = "";

    while(bin.length() % 4 != 0){
        bin.insert(0, 1, '0');
    };

    for(int i = bin.length(); i >= 4; i-=4){
        auto it = binToHex.find(bin.substr(i - 4, 4));
        hex = it->second + hex;
        bin.erase(i - 4);
    };

    return hex;

};

string toBinary(int n){

    string result = "";
    while(n >= 1){

        if(n % 2 == 1){
            result = '1' + result;
        }
        else{result = '0' + result;};
          
        n /= 2;
        
    };

    return result;

};

int toDecimal(string n){

    int result = 0;
    int power = 0;

    for(int i = n.length() - 1; i >= 0; i--){

        if(n[i] == '1'){
            result += pow(2, power);
        };
          
        power++;

    };
     
    return result;

};

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