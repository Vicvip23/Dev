#include <cstdio>
#include <cstdlib>
#include <ctime>

class Matrix{

	private:

		int* horizontal_ptr;
		int horizontalLen;
		int verticalLen;
		bool verticalState;
		
		void restructure(){

				this->horizontal_ptr = (int*) calloc(this->horizontalLen * this->verticalLen, sizeof(int));
		};

		void releaseMatrix(){

			free(this->horizontal_ptr);
		};

	public:

		Matrix(){

			this->horizontal_ptr = (int*) calloc(0, sizeof(int));
			this->horizontalLen = 0;
			this->verticalLen = 0;
			this->verticalState = false;
		};

		void setHorizontalLen(int len){

			this->releaseMatrix();
			this->horizontalLen = len;

			this->restructure();
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

						this->horizontal_ptr[i * verticalLen + j] = temp;
						temp++;
					};
				};
			}
			else if(this->verticalState){

				for(int i = 0; i < this->horizontalLen; i++){

					for(int j = 0; j < this->verticalLen; j++){

						this->horizontal_ptr[j * verticalLen + i] = temp;
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
					printf("%d\t", horizontal_ptr[i * verticalLen + j]);
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
testMtrx.setHorizontalLen(15);
testMtrx.setVerticalLen(30);
testMtrx.vertical(true);
testMtrx.refill();
testMtrx.printMatrix();
}
