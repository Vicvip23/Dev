#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int* sumArrays(int*, int*, int);
void displayArray(int*, int);

int main(){

    int input;

    printf("%s \n", "input desired array length:");
    scanf("%i", &input);

    int* arrayOne_ptr = calloc(input, sizeof(int));
    int* arrayTwo_ptr = calloc(input, sizeof(int));

    for(int i = 0; i < input; i++){
        printf("%s %i %s \n", "input element", i, "in array one:");
	scanf("%i", arrayOne_ptr + i);
        printf("%s %i %s \n", "input element", i, "in array two:");
	scanf("%i", arrayTwo_ptr + i);
    };

    int* sum_ptr = sumArrays(arrayOne_ptr, arrayTwo_ptr, input);
    displayArray(sum_ptr, input);
    free(arrayOne_ptr);
    free(arrayTwo_ptr);
    free(sum_ptr);
}

int* sumArrays(int* arr_one, int* arr_two, int len){

    int* sum_ptr = calloc(len, sizeof(int)); 

    for(int i = 0; i < len; i++){
	sum_ptr[i] = arr_one[i] + arr_two[i];
    };

    return sum_ptr;

}

void displayArray(int* arr, int len){

    for(int i = 0; i < len; i++){
        printf("%i ", arr[i]);
    };
}
