int* searchMax(int* arr, int len){

    int max = *arr;
    int* max_ptr = arr;

    for(int i = 0; i < len; i++){

        if(max < *(arr + i)){
            max_ptr = (arr + i);
            max = *(arr + i);
        };

    };

    return max_ptr;

}