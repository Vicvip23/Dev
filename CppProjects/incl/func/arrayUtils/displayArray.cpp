#include <cstdio>

void displayArray(int* arr, int len){
    for(int i = 0; i < len; i++){
        printf("%d ", *(arr + i));
    };
    printf("\n");
}