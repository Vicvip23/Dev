void bubbleSort(int* arr, int len){
    int temp;
    for(int i = 0; i < len; i++){
        for(int j = 1; j < len + 1; j++){
            if(*(arr + (j - 1)) > *(arr + j)){
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            };
        };
    };
}
