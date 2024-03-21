#include <iostream>
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

int main(){
    cout << toHex("111111111111111100000000");
};