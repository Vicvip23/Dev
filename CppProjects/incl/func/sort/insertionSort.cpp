namespace sort {
void insertionSort(int* arr, int len){

    int temp, j;

    for (int i = 1; i < len; i++) {

        temp = *(arr + i);
        j = i - 1;
 
        while (j >= 0 && *(arr + j) > temp) {

            *(arr + j + 1) = *(arr + j);
            j--;

        };

        *(arr + j + 1) = temp;

    };

}
}