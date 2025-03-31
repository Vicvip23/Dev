namespace search {
int* binarySearch(int* arr, int first, int last, int key){

    while (first <= last) {

        int mid = first + (last - first) / 2;
 
        if (arr[mid] == key){
            return (arr + mid);
        };

        if (*(arr + mid) < key){
            first = mid + 1;
        } else{
            last = mid - 1;
        };

    };

    return nullptr;
}
}