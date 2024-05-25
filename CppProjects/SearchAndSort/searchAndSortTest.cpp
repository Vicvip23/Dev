#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

void swapInt(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cocktailSort(int* arr, int len) {
    bool swapped = true;
    int start = 0;
    int end = len - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; i++) {
            if (*(arr + i) > *(arr + i + 1)) {
                swapInt((arr + i), (arr + i + 1));
                swapped = true;
            };
        };
        if (!swapped) {
            break;
        };
        end--;
        swapped = false;
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                swapInt((arr + i), (arr + i + 1));
                swapped = true;
            };
        };
        start++;
    };
}

void insertionSort(int* arr, int len)
{
    int temp, j;
    for (int i = 1; i < len; i++) {
        temp = *(arr + i);
        j = i - 1;
 
        while (j >= 0 && *(arr + j) > temp) {
            *(arr + j + 1) = *(arr + j);
            j--;
        };
        *(arr + j + 1) = temp;
    };
}

void displayArray(int* arr, int len){
    for(int i = 0; i < len; i++){
        cout << *(arr + i) << " ";
    };
    cout << endl;
}
void fillWithRand(int* arr, int len){

    srand(time(NULL));
    for(int i = 0; i < len; i++){
      *(arr + i) = (rand() % 100 + 1); 
    };
}

int sentinelSearch(int* arr, int len, int key){

    int last = *(arr + len - 1);
    *(arr + len - 1) = key;
    int i = 0;

    while (*(arr + i) != key){
        i++;
    };

    *(arr + len - 1) = last;
 
    if ((i < len - 1) || (*(arr + len - 1) == key)){
        return key;
    }
    else{return -1;};
}

int main(){
    const int size = 5;
    const int key_1 = 5;
    const int key_2 = 33;
    int table[10] = {0,1,2,3,4,5,6,7,8,9};
    int unsortedTable[10];
    int* unsortedTable_ptr = &unsortedTable[0];
    int* table_ptr = &table[0];
    

    fillWithRand(unsortedTable_ptr, 10);
    cocktailSort(unsortedTable_ptr, 10);
    displayArray(unsortedTable_ptr, 10);
    cout << "\n";

    fillWithRand(unsortedTable_ptr, 10);
    insertionSort(unsortedTable_ptr, 10);
    displayArray(unsortedTable_ptr, 10);
    cout << "\n";

    cout << sentinelSearch(table_ptr, 10, key_1) << endl;
    cout << sentinelSearch(table_ptr, 10, key_2) << endl;
    displayArray(table_ptr, 10);
}