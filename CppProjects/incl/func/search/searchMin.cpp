int* searchMin(int* arr, int len){

    int min = *arr;
    int* min_ptr = arr;

    for(int i = 0; i < len; i++){

        if(min > *(arr + i)){
            min_ptr = (arr + i);
            min = *(arr + i);
        };

    };

    return min_ptr;

}