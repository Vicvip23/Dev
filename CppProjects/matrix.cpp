#include <cstdio>
#include <cstdlib>
#include <ctime>

class Matrix{

	private:

		int* data_ptr;
		int horizontalLen;
		int verticalLen;
		
		void restructure(){

			this->data_ptr = (int*) calloc(this->horizontalLen * this->verticalLen, sizeof(int));

		};

		void releaseMatrix(){

			free(this->data_ptr);
		
		};

	public:

		Matrix(){

			this->data_ptr = (int*) calloc(0, sizeof(int));
			this->horizontalLen = 0;
			this->verticalLen = 0;
		
		};

		void setWidth(int len){

			this->releaseMatrix();
			this->horizontalLen = len;

			this->restructure();
		
		};

		void setHeight(int len){

			this->verticalLen = len;
			
			this->releaseMatrix();
			this->restructure();
		
		};

		void refill(){

			int temp = 0;
				
			for(int i = 0; i < this->horizontalLen; i++){

				for(int j = 0; j < this->verticalLen; j++){

					this->data_ptr[i * verticalLen + j] = temp;
					temp++;

				};
		
			};
		
		};

		void printMatrix(bool verticalState = false){

			if(!verticalState){

				for(int i = 0; i < this->verticalLen; i++){

					for(int j = 0; j < this->horizontalLen; j++){

						printf("%d\t", data_ptr[i * horizontalLen + j]);
		
					};
		
					printf("\n");
		
				};
		
			};

			if(verticalState){

				for(int i = 0; i < this->verticalLen; i++){

					for(int j = 0; j < this->horizontalLen; j++){

						printf("%d\t", data_ptr[(j * verticalLen) + i]);

					};
		
					printf("\n");
		
				};
		
			};
		
		};

		void empty(){

			for(int i = 0; i < this->horizontalLen * this->verticalLen; i++){

				this->data_ptr[i] = 0;

			};
		
		};

		int insertPrecise(int input, int x, int y){

			if(x < this->horizontalLen && y < this->verticalLen){

				this->data_ptr[y * this->horizontalLen + x] = input;
				return 0;

			}else{return -1;};
		
		};

		int insertSerial(int* input, int len){

			if(len > this->horizontalLen * this->verticalLen){

				for(int i = 0; i < this->horizontalLen * this->verticalLen; i++){

					this->data_ptr[i] = input[i];

				};

				return 1;

			}
			else if(len < this->horizontalLen * this->verticalLen){

				for(int i = 0; i < len; i++){

					this->data_ptr[i] = input[i];

				};

				return 0;

			}else{return -1;};

		};

		int access(int x, int y){
			
			if(x < this->horizontalLen && y < this->verticalLen){

				return this->data_ptr[y * this->horizontalLen + x];

			}else{return -1;};

		};

};



int main(){

Matrix testMtrx;


testMtrx.setWidth(20);
testMtrx.setHeight(15);

testMtrx.refill();
testMtrx.printMatrix();


printf("\n");


testMtrx.setWidth(15);
testMtrx.setHeight(30);


testMtrx.refill();
testMtrx.printMatrix(true);


printf("\n");


testMtrx.empty();
testMtrx.printMatrix();


printf("\n");


testMtrx.insertPrecise(21, 14, 29);
testMtrx.printMatrix();


printf("\n");


int arr[] = {10, 11, 12, 13, 14, 15, 16};
testMtrx.insertSerial(arr, 7);
testMtrx.printMatrix();


printf("\n");


testMtrx.setWidth(3);
testMtrx.setHeight(2);
testMtrx.insertSerial(arr, 7);
testMtrx.printMatrix();


printf("\n");


printf("%d\n", testMtrx.access(2, 1));

return 0;

}
