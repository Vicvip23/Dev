#include "../func/search/searchMax.cpp"
#include "../func/search/searchMin.cpp"
#include "../func/search/linearSearch.cpp"
#include "../func/search/binarySearch.cpp"
#include "../func/search/sentinelSearch.cpp"

int* searchMax(int* arr, int len);
int* searchMin(int* arr, int len);
int* linearSearch(int* arr, int len, int key);
int* binarySearch(int* arr, int first, int last, int key);
int* sentinelSearch(int* arr, int len, int key);