#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SearchAndSort.hpp"

using namespace std;

int main(){
    const int size = 5;
    const int key_1 = 5;
    const int key_2 = 33;
    int table[10] = [0,1,2,3,4,5,6,7,8,9];
    int unsortedTable[10];
    int* unsortedTable_ptr = &unsortedTable;
    int* table_ptr = &table;
    
    fillWithRand(unsortedTable_ptr, 10);
    bubbleSort(unsortedTable_ptr, 10);
    displayArray(unsortedTable_ptr, 10);
    cout << "\n";

    fillWithRand(unsortedTable_ptr, 10);
    cocktailSort(unsortedTable_ptr, 10);
    displayArray(unsortedTable_ptr, 10);
    cout << "\n";

    fillWithRand(unsortedTable_ptr, 10);
    insertionSort(unsortedTable_ptr, 10);
    displayArray(unsortedTable_ptr, 10);
    cout << "\n";

    cout << linearSearch(table_ptr, 10, key_1) << endl;
    cout << linearSearch(table_ptr, 10, key_2) << endl;
    cout << displayArray(table_ptr, 10) << endl;

    cout << sentinelSearch(table_ptr, 10, key_1) << endl;
    cout << sentinelSearch(table_ptr, 10, key_2) << endl;
    cout << displayArray(table_ptr, 10) << endl;

    cout << binarySearch(table_ptr, 0, 10, key_1) << endl;
    cout << binarySearch(table_ptr, 0, 10, key_2) << endl;
    cout << displayArray(table_ptr, 10) << endl;
}