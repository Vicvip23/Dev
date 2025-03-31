namespace search {
int* linearSearch(int* arr, int len, int key){

    for (int i = 0; i < len; i++){

        if (arr[i] == key){ 
            return (arr + i);
        };

    };

    return nullptr;

}
}