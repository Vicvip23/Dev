#include <cstdio>
#include <chrono>
#include <cstring>
#include "../incl/header/sort.hpp"
#include "../incl/header/search.hpp"
#include "../incl/header/arrayUtils.hpp"


int main(){

    unsigned int length;
    unsigned int range;
    long int duration2;
    char ifDisplay;
    bool print;


    printf("%s \n", "input desired array size (recommended value is 8000):");
    scanf("%u", &length);

    printf("\n%s \n", "input desired random value range, has to be larger or equal to array size (0 to specified - 1), otherwise, the range will auto-correct to array size:");
    scanf("%u", &range);
    if(range < length){
        range = length;
    };

    printf("\n%s \n", "do you want to display the arrays (y/n)? (may lead to console clutter):");
    scanf(" %c", &ifDisplay);
    if(strcmp(&ifDisplay, "y") == 0){
        print = true;
    }else{print = false;};

    int* test = new int[length];

    printf("\n%s %u\n", "array size is:", length);
    printf("%s %u\n\n", "random range is:", range);



    auto start = std::chrono::high_resolution_clock::now();
    arrayUtils::fillWithUnique(test, length, range);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    duration2 = duration.count();

    if(print){
    start = std::chrono::high_resolution_clock::now();
    arrayUtils::displayArray(test, length);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    printf("\n%s %ld %s\n", "displaying the array took:", duration.count(), "milliseconds");
    };

    printf("%s %ld %s\n\n", "filling the array with unique random numbers took:", duration2, "milliseconds");



    start = std::chrono::high_resolution_clock::now();
    sort::insertionSort(test, length);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    duration2 = duration.count();
    
    if(print){
    start = std::chrono::high_resolution_clock::now();
    arrayUtils::displayArray(test, length);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    printf("\n%s %ld %s\n", "displaying the array took:", duration.count(), "milliseconds");
    };

    printf("%s %ld %s\n", "sorting the array using insertion sort took:", duration2, "milliseconds");



    start = std::chrono::high_resolution_clock::now();
    int* linearSearchResult = search::linearSearch(test, length, *(test + length - 2));
    for(int i = 0; i < 9999; i++){
        search::linearSearch(test, length, *(test + length - 2));
    };
    end = std::chrono::high_resolution_clock::now();
    auto microDuration = std::chrono::duration_cast<std::chrono::microseconds>(end-start) / 10000;

    printf("\n%s %ld %s\n", "searching the array for second to last value using linear search (tried 10000 times) took on average:", microDuration.count(), "microseconds");
    printf("%s %d\n", "index of searched value is:", *linearSearchResult);



    start = std::chrono::high_resolution_clock::now();
    int* binarySearchResult = search::binarySearch(test, 0, length, *(test + length - 2));
    for(int i = 0; i < 9999; i++){
        search::binarySearch(test, 0, length, *(test + length - 2));
    };
    end = std::chrono::high_resolution_clock::now();
    auto nanoDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start) / 10000;

    printf("\n%s %ld %s\n", "searching the array for second to last value using binary search (tried 10000 times) took on average:", nanoDuration.count(), "nanoseconds");
    printf("%s %d\n", "index of searched value is:", *binarySearchResult);

    delete[] test;

}
