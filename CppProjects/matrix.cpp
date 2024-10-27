#include <cstdio>
#include <cstdlib>


class Matrix{


	private:


		int* data_ptr;
		size_t horizontalLen;
		size_t  verticalLen;


		void restructure(){

			this->data_ptr = (int*) calloc(this->horizontalLen * this->verticalLen, sizeof(int));

		};


	public:


		Matrix(){

			this->data_ptr = (int*) calloc(0, sizeof(int));
			this->horizontalLen = 0;
			this->verticalLen = 0;
		
		};


		void releaseMatrix(){

			free(this->data_ptr);
		
		};


		void setWidth(unsigned int len){

			this->releaseMatrix();
			this->horizontalLen = len;

			this->restructure();
		
		};


		void setHeight(unsigned int len){

			this->verticalLen = len;
			
			this->releaseMatrix();
			this->restructure();
		
		};


		void refill(){

			int temp = 0;
				
			for(unsigned int i = 0; i < this->verticalLen; i++){

				for(unsigned int j = 0; j < this->horizontalLen; j++){

					this->data_ptr[(i * this->horizontalLen) + j] = temp;
					temp++;
					if(temp >= 2000000000){temp = 0;};

				};
		
			};
		
		};


		void printMatrix(bool verticalState = false){

			if(!verticalState){

				for(size_t i = 0; i < this->verticalLen; i++){

					for(size_t j = 0; j < this->horizontalLen; j++){

						printf("%d\t", data_ptr[(i * horizontalLen) + j]);
		
					};
		
					printf("\n");
		
				};
		
			};

			if(verticalState){

				for(size_t i = 0; i < this->verticalLen; i++){

					for(size_t j = 0; j < this->horizontalLen; j++){

						printf("%d\t", data_ptr[(j * verticalLen) + i]);

					};
		
					printf("\n");
		
				};
		
			};
		
		};


		void empty(){

			this->releaseMatrix();
			this->restructure();
		
		};


		int set(int input, size_t x, size_t y){

			if(x < this->horizontalLen && y < this->verticalLen){

				this->data_ptr[y * this->horizontalLen + x] = input;
				return 0;

			}else{return -1;};
		
		};


		int setSerial(int* input, size_t len, size_t beginX = 0, size_t beginY = 0){

			if(len > this->horizontalLen * this->verticalLen){

				for(unsigned long int i = 0; i < this->horizontalLen * this->verticalLen; i++){

					this->data_ptr[(beginY * this->verticalLen + beginX) + i] = input[i];
					if((beginY * this->verticalLen + beginX) + i + 1 >= this->verticalLen * this->horizontalLen){return 1;};

				};

				return 1;

			}
			else if(len <= this->horizontalLen * this->verticalLen){

				for(unsigned long int i = 0; i < len; i++){

					this->data_ptr[(beginY * this->verticalLen + beginX) + i] = input[i];
					if((beginY * this->verticalLen + beginX) + i + 1 >= this->verticalLen * this->horizontalLen){return 1;};

				};

				return 0;

			}else if(beginX >= this->horizontalLen || beginY >= this->verticalLen){
				return -1;
			}else{return -1;};

		};


		int get(size_t x, size_t y){
			
			if(x < this->horizontalLen && y < this->verticalLen){

				return this->data_ptr[y * this->horizontalLen + x];

			}else{return -1;};

		};

};