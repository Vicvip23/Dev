#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int sumArray(int*, int);
int* findProperDivisors(int);
//void forEach(void*, int, void*);

int main()
{
    int inputOne;
    int inputTwo;
    
    printf("Input integer 1:\n");
    scanf("%d", &inputOne);
    printf("Input integer 2:\n");
    scanf("%d", &inputTwo);
    
    int* inputOneDivisors_ptr = findProperDivisors(inputOne);
    int* inputTwoDivisors_ptr = findProperDivisors(inputTwo);
    
    int sumOne = sumArray((inputOneDivisors_ptr + 1), inputOneDivisors_ptr[0]);
    int sumTwo = sumArray((inputTwoDivisors_ptr + 1), inputTwoDivisors_ptr[0]);
    
    if(sumOne == inputTwo && sumTwo == inputOne){
        printf("%d and %d are amicable numbers.\n", inputOne, inputTwo);
    }
    else{
        printf("%d and %d are not amicable numbers.\n", inputOne, inputTwo);
    };

    return 0;
}

int sumArray(int* arr, int len){
    
    int sum = 0;
    
    for(int i = 0; i < len; i++){
        sum += arr[i];
    };
    
    return sum;
    
};

int* findProperDivisors(int val){
    
    int divAmount = 0;
    int* divisors_ptr = calloc(0, sizeof(int));
    
    for(int i = (val / 2) + 1; i > 0; i--){
        
        if(val % i == 0){
            
            divAmount++;
            int* check = realloc(divisors_ptr, sizeof(int) * divAmount + 1);
            
            if(!check){
                free(divisors_ptr);
                return NULL;
            };
            
            divisors_ptr = check;
            divisors_ptr[divAmount] = i; 
            
        };
        
    };
    
    divisors_ptr[0] = divAmount;
    return divisors_ptr;
    
}

//void forEach(void* arr, int len, void* func)
