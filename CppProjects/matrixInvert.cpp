#include <cstdio>
#include <cstdlib>
#include <ctime>

class Matrix{

	private:

		int** horizontal_ptr;
		int horizontalLen;
		int verticalLen;
		bool verticalState;
		
		void restructure(){

			for(int i = 0; i < this->horizontalLen; i++){

				int* check = (int*) calloc(this->verticalLen, sizeof(int*));

				this->horizontal_ptr[i] = check;
			};
		};

		void releaseMatrix(){

			for(int i = 0; i < this->horizontalLen; i++){
				free(this->horizontal_ptr + i);
			};

		};

	public:

		Matrix(){

			this->horizontal_ptr = (int**) calloc(0, sizeof(int));
			this->verticalState = false;
		};

		int setHorizontalLen(int len){

			this->releaseMatrix();
			this->horizontalLen = len;
			int** check = (int**) realloc(this->horizontal_ptr, this->horizontalLen * sizeof(int));
			
			if(check == NULL){
				free(check);
				return -1; 
			};
			
			this->horizontal_ptr = check;

			this->restructure();

			return 0;
		};

		void setVerticalLen(int len){

			this->verticalLen = len;
			
			this->releaseMatrix();
			this->restructure();

		};

		void refill(){

			int temp = 0;
			if(!this->verticalState){
				
				for(int i = 0; i < this->horizontalLen; i++){

					for(int j = 0; j < this->verticalLen; j++){

						//this->horizontal_ptr[i][j] = (int*) malloc(sizeof(int));
						this->horizontal_ptr[i][j] = temp;
						temp++;
					};
				};
			}
			else if(this->verticalState){

				for(int i = 0; i < this->horizontalLen; i++){

					for(int j = 0; j < this->verticalLen; j++){

						//this->horizontal_ptr[j][i] = (int*) malloc(sizeof(int));
						this->horizontal_ptr[j][i] = temp;
						temp++;
					};
				};
			};
		};

		void vertical(bool state){
			this->verticalState = state;
		};

		void printMatrix(){
			for(int i = 0; i < this->horizontalLen; i++){
				for(int j = 0; j < this->verticalLen; j++){
					printf("%d ", horizontal_ptr[i][j]);
				};
				printf("\n");
			};
		};
};

int main(){
Matrix testMtrx;
testMtrx.setHorizontalLen(20);
testMtrx.setVerticalLen(15);
testMtrx.refill();
testMtrx.printMatrix();
}
