#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "../incl/header/arrayUtils.hpp"
#include "../incl/header/sort.hpp"

using namespace std;

int x = 100;

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
