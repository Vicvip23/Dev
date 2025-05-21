#include "../func/arrayUtils/fillWithUnique.cpp"
#include "../func/arrayUtils/displayArray.cpp"
#include "../func/arrayUtils/fillWithRand.cpp"
#include "../func/arrayUtils/swapInt.cpp"
#include "../func/arrayUtils/sum.cpp"

namespace arrayUtils {
    int fillWithUnique(int* array, int length, int range, bool includeMax = false);
    int sum(int* array, int length);
    void displayArray(int* array, int length);
    void fillWithRand(int* array, int length, int max);
    void swapInt(int *a, int *b);
}
