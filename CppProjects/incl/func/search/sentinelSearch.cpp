namespace search {
int* sentinelSearch(int* arr, int len, int key){

    int last = *(arr + len - 1);
    *(arr + len - 1) = key;
    int i = 0;

    while (*(arr + i) != key){
        i++;
    };

    *(arr + len - 1) = last;
 
    if ((i < len - 1) || (*(arr + len - 1) == key)){
        return (arr + len - 1);
    }
    else{return nullptr;};
}
}