namespace sort {
void cocktailSort(int* arr, int len) {
    bool swapped = true;
    int start = 0;
    int end = len - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            };
        };
        if (!swapped) {
            break;
        };
        end--;
        swapped = false;
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            };
        };
        start++;
    };
}
}