#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void fillWithRand(int* arr, int len){
    srand(time(NULL));
    for(int i = 0; i < len; i++){
      *(arr + i) = (rand() % 100 + 1);  
    };
}

void displayArray(int* arr, int len){
    for(int i = 0; i < len; i++){
        cout << *(arr + i) << " ";
    };
    cout << endl;
}

void bubbleSort(int* arr, int len){
    int temp;
    for(int i = 0; i < len; i++){
        for(int j = 1; j < len + 1; j++){
            if(*(arr + (j - 1)) > *(arr + j)){
                temp = *(arr + j);
                *(arr + j) = *(arr + j - 1);
                *(arr + j - 1) = temp;
            };
        };
    };
}

int main()
{
    int len = 10;
    int arr[10];
    int* arr_ptr = &arr[0];

    fillWithRand(arr_ptr, len);
    displayArray(arr_ptr, len);
    bubbleSort(arr_ptr, len);
    displayArray(arr_ptr, len);
    
    return 0;
}
