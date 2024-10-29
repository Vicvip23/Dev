#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../incl/header/arrayUtils.hpp"
#include "../incl/header/sort.hpp"
#include "../incl/header/search.hpp"
 

int main(){
    const int size = 10;
    const int key_1 = 5;
    const int key_2 = 33;
    int table[size] = {0,1,2,3,4,5,6,7,8,9};
    int unsortedTable[size];
    int* unsortedTable_ptr = unsortedTable;
    int* table_ptr = table;
    
    fillWithRand(unsortedTable_ptr, size);
    bubbleSort(unsortedTable_ptr, size);
    displayArray(unsortedTable_ptr, size);
    std::cout << "\n";

    fillWithRand(unsortedTable_ptr, size);
    cocktailSort(unsortedTable_ptr, size);
    displayArray(unsortedTable_ptr, size);
    std::cout << "\n";

    fillWithRand(unsortedTable_ptr, size);
    insertionSort(unsortedTable_ptr, size);
    displayArray(unsortedTable_ptr, size);
    std::cout << "\n";

    std::cout << *linearSearch(table_ptr, size, key_1) << std::endl;
    std::cout << *linearSearch(table_ptr, size, key_2) << std::endl;
    displayArray(table_ptr, size);

    std::cout << *sentinelSearch(table_ptr, size, key_1) << std::endl;
    std::cout << *sentinelSearch(table_ptr, size, key_2) << std::endl;
    displayArray(table_ptr, size);

    std::cout << *binarySearch(table_ptr, 0, size, key_1) << std::endl;
    std::cout << *binarySearch(table_ptr, 0, size, key_2) << std::endl;
    displayArray(table_ptr, size);
}