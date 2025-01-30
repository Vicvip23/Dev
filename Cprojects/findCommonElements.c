#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void compareArrays(char*, char*, int);

int main(){
    srand(time(NULL));
    char* arrOne = calloc(10, sizeof(char));
    char* arrTwo = calloc(10, sizeof(char));
    for(int i = 0; i < 10; i++){
        arrOne[i] = (rand() % 66 + 25);
        arrTwo[i] = (rand() % 66 + 25);
    };
    compareArrays(arrOne, arrTwo, 10);
    for(int i = 0; i < 10; i++){
        printf("%c ", arrOne[i]);
    };
    printf("\n");
    for(int i = 0; i < 10; i++){
        printf("%c ", arrTwo[i]);
    };
    printf("\n");
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
                printf("%s %c\n", "common:", (char)arrOne[i]);
	    };
	};
    };
}
