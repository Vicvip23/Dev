#include <cstdio>
#include <cstdlib>


class Matrix{


	private:


		float* data_ptr;
		unsigned int horizontalLen;
		unsigned int verticalLen;


		void restructure(){

			this->data_ptr = (float*) calloc(this->horizontalLen * this->verticalLen, sizeof(float));

		};


		void releaseMatrix(){

			free(this->data_ptr);
		
		};


	public:


		Matrix(){

			this->data_ptr = (float*) calloc(0, sizeof(float));
			this->horizontalLen = 0;
			this->verticalLen = 0;
		
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

			float temp = 0;
				
			for(unsigned int i = 0; i < this->verticalLen; i++){

				for(unsigned int j = 0; j < this->horizontalLen; j++){

					this->data_ptr[(i * verticalLen) + j] = temp;
					//printf("%f || %p\n", temp, &this->data_ptr[(i * verticalLen) + j]);
					temp+=0.01;
					if(temp >= 100000){temp = 0;};

				};
		
			};
		
		};


		void printMatrix(bool verticalState = false){

			if(!verticalState){

				for(unsigned int i = 0; i < this->verticalLen; i++){

					for(unsigned int j = 0; j < this->horizontalLen; j++){

						printf("%f\t", data_ptr[i * horizontalLen + j]);
		
					};
		
					printf("\n");
		
				};
		
			};

			if(verticalState){

				for(unsigned int i = 0; i < this->verticalLen; i++){

					for(unsigned int j = 0; j < this->horizontalLen; j++){

						printf("%f\t", data_ptr[(j * verticalLen) + i]);

					};
		
					printf("\n");
		
				};
		
			};
		
		};


		void empty(){

			this->releaseMatrix();
			this->restructure();
		
		};


		int set(float input, unsigned int x, unsigned int y){

			if(x < this->horizontalLen && y < this->verticalLen){

				this->data_ptr[y * this->horizontalLen + x] = input;
				return 0;

			}else{return -1;};
		
		};


		int setSerial(float* input, unsigned long int len, unsigned int beginX = 0, unsigned int beginY = 0){

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


		int get(unsigned int x, unsigned int y){
			
			if(x < this->horizontalLen && y < this->verticalLen){

				return this->data_ptr[y * this->horizontalLen + x];

			}else{return -1;};

		};

};