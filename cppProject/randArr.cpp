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

int main()
{
    int len = 10;
    int arr[10];
    int* arr_ptr = &arr[0];
    fillWithRand(arr_ptr, len);
    
    for(int i = 0; i < len; i++){
        cout << arr[i] << endl;
    };
    
    return 0;
}
