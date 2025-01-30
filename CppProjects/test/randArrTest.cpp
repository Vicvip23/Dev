#include <cstdio>
#include "../incl/header/arrayUtils.hpp"
#include "../incl/header/search.hpp"

int main(){

    int numbers[10];
    arrayUtils::fillWithRand(&numbers[0], 10);
    printf("%d\n", *search::searchMin(&numbers[0], 10));
    printf("%d\n", *search::searchMax(&numbers[0], 10));
    arrayUtils::displayArray(&numbers[0], 10);

}