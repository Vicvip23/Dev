#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>

using namespace std;

int fillWithUnique(int* array, int length, int range, bool includeMax = false){

    srand(time(NULL));
    vector<int> values;

    if(length > range){
        return -1;
    };

    for(int i = 0; i < range; i++){

        if(includeMax){
            values.push_back(i + 1);
        } else {
            values.push_back(i);
        };

    };

    for(int i = 0; i < length; i++){
        
        int *index = new int;
        *index = rand() % values.size();
        *(array + i) = values[*index];
        values.erase(values.begin() + *index);
        delete index;

    };

    return 0;

}

void insertionSort(int* arr, int len){

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

int linearSearch(int* arr, int len, int key){

    for (int i = 0; i < len; i++){

        if (*(arr + i) == key){ 
            return i;
        };

    };

    return -1;

}

int binarySearch(int* arr, int first, int last, int key){

    while (first <= last) {

        int mid = first + (last - first) / 2;
 
        if (*(arr + mid) == key){
            return mid;
        };

        if (*(arr + mid) < key){
            first = mid + 1;
        } else{
            last = mid - 1;
        };

    };

    return -1;
}

void displayArray(int* arr, int len){

    for(int i = 0; i < len; i++){

        printf("%d ", *(arr + i));

    };

    printf("\n");
}

int main(){

    int test[8000];
    const int length = sizeof(test)/sizeof(test[0]);



    auto start = chrono::high_resolution_clock::now();

    fillWithUnique(&test[0], length, 8000);
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::microseconds>(end-start);
    
    displayArray(&test[0], length);
    printf("%s %lld %s\n", "filling the array with unique random numbers took:", duration.count(), "microseconds");



    start = chrono::high_resolution_clock::now();

    insertionSort(&test[0], length);

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<std::chrono::microseconds>(end-start);

    displayArray(&test[0], length);
    printf("%s %lld %s\n", "sorting the array using insertion sort took:", duration.count(), "microseconds");



    start = chrono::high_resolution_clock::now();

    int linearSearchResult = linearSearch(&test[0], length, test[7998]);

    for(int i = 0; i < 199; i++){
        linearSearch(&test[0], length, test[7998]);
    };

    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<std::chrono::microseconds>(end-start) / 200;

    printf("%s %lld %s\n", "searching the array for 7999th value using linear search took on average:", duration.count(), "microseconds");
    printf("%s %d\n", "index of searched value is:", linearSearchResult);



    start = chrono::high_resolution_clock::now();

    int binarySearchResult = binarySearch(&test[0], 0, length, test[7998]);

    for(int i = 0; i < 999; i++){
        binarySearch(&test[0], 0, length, test[7998]);
    };

    end = chrono::high_resolution_clock::now();
    auto nanoDuration = chrono::duration_cast<std::chrono::nanoseconds>(end-start) / 1000;

    printf("%s %lld %s\n", "searching the array for 7999th value using binary search took on average:", nanoDuration.count(), "nanoseconds");
    printf("%s %d\n", "index of searched value is:", binarySearchResult);

}