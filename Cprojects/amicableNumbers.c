#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define functions

int sumArray(int*, int);
int* findProperDivisors(int);


// Driver code

int main()
{
    int inputOne;
    int inputTwo;
    
    // Ask user for input
    printf("Input integer 1:\n");
    scanf("%d", &inputOne);
    printf("Input integer 2:\n");
    scanf("%d", &inputTwo);
    
    int* inputOneDivisors_ptr = findProperDivisors(inputOne);
    int* inputTwoDivisors_ptr = findProperDivisors(inputTwo);
    
    int sumOne = sumArray((inputOneDivisors_ptr + 1), inputOneDivisors_ptr[0]);
    int sumTwo = sumArray((inputTwoDivisors_ptr + 1), inputTwoDivisors_ptr[0]);
    
    // Check if numbers are amicable
    if(sumOne == inputTwo && sumTwo == inputOne){
        printf("%d and %d are amicable numbers.\n", inputOne, inputTwo);
    }
    else{
        printf("%d and %d are not amicable numbers.\n", inputOne, inputTwo);
    };

    return 0;
}


// Function that sums up all the elements of an array

int sumArray(int* arr, int len){
    
    int sum = 0;
    
    for(int i = 0; i < len; i++){
        sum += arr[i];
    };
    
    return sum;
    
};


// Function that returns all proper divisors of given number. Returns an array of the divisors. Element 0 is array length-1

int* findProperDivisors(int val){
    

    
    int divAmount = 0; // Amount of proper divisors
    int* divisors_ptr = calloc(0, sizeof(int)); // Ptr to array of proper divisors
    
    // Iterate through all possible proper divisors
    for(int i = (val / 2) + 1; i > 0; i--){
        
        // Check if number is divisor
        if(val % i == 0){
            
            divAmount++; // Increment amount of divisors
            int* check = realloc(divisors_ptr, sizeof(int) * divAmount + 1); // Alloc space for next divisor
            
            // Check for realloc fail
            if(!check){
                free(divisors_ptr);
                return NULL;
            };
            
            // Save divisor to array
            divisors_ptr = check;
            divisors_ptr[divAmount] = i; 
        };
        
    };
    
    divisors_ptr[0] = divAmount; // Save divisor amount to element 0 of array
    return divisors_ptr;
    
}

