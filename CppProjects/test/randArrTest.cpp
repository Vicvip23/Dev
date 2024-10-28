#include <cstdio>
#include "../incl/header/arrayUtils.hpp"
#include "../incl/header/search.hpp"

int main(){

    int numbers[10];
    fillWithRand(&numbers[0], 10);
    printf("%d\n", *searchMin(&numbers[0], 10));
    printf("%d\n", *searchMax(&numbers[0], 10));
    displayArray(&numbers[0], 10);

}