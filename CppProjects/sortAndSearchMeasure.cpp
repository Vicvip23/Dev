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

    printf("%s \n", "input desired array size (recommended value is 8000):");
    unsigned int length;
    scanf("%u", &length);

    printf("\n%s \n", "input desired random value range, has to be larger or equal to array size (0 to specified - 1), otherwise, the range will auto-correct to array size:");
    unsigned int range;
    scanf("%u", &range);
    if(range < length){
        range = length;
    };

    int* test = new int[length];

    printf("\n%s %u\n", "array size is:", length);
    printf("%s %u\n\n", "random range is:", range);



    auto start = chrono::high_resolution_clock::now();
    fillWithUnique(test, length, range);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::milliseconds>(end-start);
    
    start = chrono::high_resolution_clock::now();
    displayArray(test, length);
    end = chrono::high_resolution_clock::now();
    auto displayDuration = chrono::duration_cast<std::chrono::milliseconds>(end-start);
    
    printf("\n%s %ld %s\n", "filling the array with unique random numbers took:", duration.count(), "milliseconds");
    printf("%s %ld %s\n\n", "displaying the array took:", displayDuration.count(), "milliseconds");



    start = chrono::high_resolution_clock::now();
    insertionSort(test, length);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<std::chrono::milliseconds>(end-start);
    
    start = chrono::high_resolution_clock::now();
    displayArray(test, length);
    end = chrono::high_resolution_clock::now();
    displayDuration = chrono::duration_cast<std::chrono::milliseconds>(end-start);
    
    printf("\n%s %ld %s\n", "sorting the array using insertion sort took:", duration.count(), "milliseconds");
    printf("%s %ld %s\n", "displaying the array took:", displayDuration.count(), "milliseconds");\



    start = chrono::high_resolution_clock::now();
    int linearSearchResult = linearSearch(test, length, *(test + length - 2));
    for(int i = 0; i < 9999; i++){
        linearSearch(test, length, *(test + length - 2));
    };
    end = chrono::high_resolution_clock::now();
    auto microDuration = chrono::duration_cast<std::chrono::microseconds>(end-start) / 10000;

    printf("\n%s %ld %s\n", "searching the array for second to last value using linear search (tried 10000 times) took on average:", microDuration.count(), "microseconds");
    printf("%s %d\n", "index of searched value is:", linearSearchResult);



    start = chrono::high_resolution_clock::now();
    int binarySearchResult = binarySearch(test, 0, length, *(test + length - 2));
    for(int i = 0; i < 9999; i++){
        binarySearch(test, 0, length, *(test + length - 2));
    };
    end = chrono::high_resolution_clock::now();
    auto nanoDuration = chrono::duration_cast<std::chrono::nanoseconds>(end-start) / 10000;

    printf("\n%s %ld %s\n", "searching the array for second to last value using binary search (tried 10000 times) took on average:", nanoDuration.count(), "nanoseconds");
    printf("%s %d\n", "index of searched value is:", binarySearchResult);

    delete[] test;

}
