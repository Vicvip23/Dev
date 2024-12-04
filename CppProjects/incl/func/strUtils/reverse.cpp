#include <string>

std::string stringReverse(std::string arg){

    char temp;
    
    for(int i = 0; i < arg.length(); i++){

        temp = arg[i];
        arg[i] = arg[arg.length() - i - 1];
        arg[arg.length() - i - 1] = temp;

        if(i == (arg.length() - i - 1)){
            break;
        }
    }
    return arg;
}