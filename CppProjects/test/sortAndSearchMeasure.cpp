#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "../incl/header/sort.hpp"
#include "../incl/header/search.hpp"
#include "../incl/header/arrayUtils.hpp"

using namespace std;

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
    int *linearSearchResult = linearSearch(test, length, *(test + length - 2));
    for(int i = 0; i < 9999; i++){
        linearSearch(test, length, *(test + length - 2));
    };
    end = chrono::high_resolution_clock::now();
    auto microDuration = chrono::duration_cast<std::chrono::microseconds>(end-start) / 10000;

    printf("\n%s %ld %s\n", "searching the array for second to last value using linear search (tried 10000 times) took on average:", microDuration.count(), "microseconds");
    printf("%s %d\n", "index of searched value is:", *linearSearchResult);



    start = chrono::high_resolution_clock::now();
    int *binarySearchResult = binarySearch(test, 0, length, *(test + length - 2));
    for(int i = 0; i < 9999; i++){
        binarySearch(test, 0, length, *(test + length - 2));
    };
    end = chrono::high_resolution_clock::now();
    auto nanoDuration = chrono::duration_cast<std::chrono::nanoseconds>(end-start) / 10000;

    printf("\n%s %ld %s\n", "searching the array for second to last value using binary search (tried 10000 times) took on average:", nanoDuration.count(), "nanoseconds");
    printf("%s %d\n", "index of searched value is:", *binarySearchResult);

    delete[] test;

}
