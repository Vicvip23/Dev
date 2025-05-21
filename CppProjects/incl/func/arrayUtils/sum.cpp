namespace arrayUtils {

    int sum(int* arr, int len){
        
        int temp;
        for(int i = 0; i < len; i++){
            temp += arr[i];
        };
        return temp;
    }
}