#include <cstdio>
#include <cstdlib>


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

		int set(int input, int x, int y){

			if(x < this->horizontalLen && y < this->verticalLen){

				this->data_ptr[y * this->horizontalLen + x] = input;
				return 0;

			}else{return -1;};
		
		};

		int setSerial(int* input, int len, int beginX = 0, int beginY = 0){

			if(len > this->horizontalLen * this->verticalLen){

				for(int i = 0; i < this->horizontalLen * this->verticalLen; i++){

					this->data_ptr[(beginY * this->verticalLen + beginX) + i] = input[i];
					if((beginY * this->verticalLen + beginX) + i + 1 >= this->verticalLen * this->horizontalLen){return 1;};

				};

				return 1;

			}
			else if(len < this->horizontalLen * this->verticalLen){

				for(int i = 0; i < len; i++){

					this->data_ptr[(beginY * this->verticalLen + beginX) + i] = input[i];
					if((beginY * this->verticalLen + beginX) + i + 1 >= this->verticalLen * this->horizontalLen){return 1;};

				};

				return 0;

			}else if(beginX >= this->horizontalLen || beginY >= this->verticalLen){
				return -1;
			}else{return -1;};

		};

		int get(int x, int y){
			
			if(x < this->horizontalLen && y < this->verticalLen){

				return this->data_ptr[y * this->horizontalLen + x];

			}else{return -1;};

		};

};