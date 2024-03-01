#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string toBinary(int n){

     string result = '';
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
          }
          
          power++;

     }
     
     return result;

}

int main(){
     int x = 20;
     string binary = toBinary(x);
     cout << binary;
     cout << toDecimal(binary);
}