#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

int x = 100;

int fillWithUnique(int* array, int length, int range, bool includeMax = false){

    srand(time(NULL));
    vector<int> values;

    if(length > range){
        return -1;
    };

    for(int i = 0; i < range; i++){

        if(includeMax){
            values.push_back(i + 1);
        } else {
            values.push_back(i);
        };

    };

    for(int i = 0; i < length; i++){
        
        int *index = new int;
        *index = rand() % values.size();
        *(array + i) = values[*index];
        values.erase(values.begin() + *index);
        delete index;

    };

    return 0;

}

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

class Foo{
	public:
	int* arrOne;
	int* arrTwo;
	int* arrThree;

	void sortThree(bool reverse = 1){
		insertionSort(arrThree, x);
		if(reverse){
			std::reverse(arrThree, arrThree + x);
		}
	};
	void sum(){
		for(int i = 0; i < x; i++){
			*(arrThree + i) = *(arrTwo + i) + *(arrOne + i);
		};
	};
};

void displayArray(int* arr, int len){

    for(int i = 0; i < len; i++){

        printf("%d ", *(arr + i));

    };

    printf("\n");
}

int main(){

Foo Bar;

Bar.arrOne = new int[x];
Bar.arrTwo = new int[x];
Bar.arrThree = new int[x];
fillWithUnique(Bar.arrOne, x, 100);
fillWithUnique(Bar.arrTwo, x, 100);
Bar.sum();
Bar.sortThree();
displayArray(Bar.arrThree, x);
}
