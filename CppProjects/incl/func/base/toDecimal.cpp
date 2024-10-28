#include <string>
#include <cmath>

int toDecimal(std::string n){

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
