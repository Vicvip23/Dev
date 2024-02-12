#include <SearchAndSort.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>

void swapInt(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* arr, int len){
    int temp;
    for(int i = 0; i < len; i++){
        for(int j = 1; j < len + 1; j++){
            if(*(arr + (j - 1)) > *(arr + j)){
                swapInt(*(arr + (j - 1)),*(arr + j))
            };
        };
    };
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

int linearSearch(int* arr, int len, int key){

    for (int i = 0; i < len; i++){ 
        if (*(arr + i) == key){ 
            return i;
        };
    };

    return -1; 
}

int sentinelSearch(int* arr, int len, int key){

    int last = *(arr + len - 1);
    *(arr + len - 1) = key;
    int i = 0;

    while (*(arr + i) != key){
        i++;
    };

    *(arr + len - 1) = last;
 
    if ((i < n - 1) || (*(arr + len - 1) == key)){
        return key;
    };
    else{return -1;};
}

int binarySearch(int* arr, int first, int last, int key){

    while (first <= last) {
        int mid = first + (last - first) / 2;
 
        if (*(arr + mid) == key){
            return mid;
        };
        if (*(arr + mid) < key){
            first = mid + 1;
        };
        else{
            last = mid - 1;
        };
    };

    return -1;
}