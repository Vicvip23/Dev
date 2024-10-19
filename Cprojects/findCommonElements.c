#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void compareArrays(char*, char*, int);

int main(){
    srand(time(NULL));
    char* arrOne = calloc(100, sizeof(char));
    char* arrTwo = calloc(100, sizeof(char));
    for(int i = 0; i < 100; i++){
        arrOne[i] = (rand() % 66 + 25);
    };
    compareArrays(arrOne, arrTwo, 100);
    free(arrOne);
    free(arrTwo);
}

void compareArrays(char* arrOne, char* arrTwo, int len){
    // printf("test");
    for(int i = 0; i < len; i++){
	// printf("test2");
        for(int j = 0; j < len; j++){
	    // printf("test3");
            if(arrOne[i] == arrTwo[j]){
                printf("%s %c", "common:", (char)arrOne[i]);
	    };
	};
    };
}
