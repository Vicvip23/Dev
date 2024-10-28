#include <string>

std::string toBinary(int n){

    std::string result = "";
    while(n >= 1){

        if(n % 2 == 1){
            result = '1' + result;
        }
        else{result = '0' + result;};
          
        n /= 2;
        
    };

    return result;

};
