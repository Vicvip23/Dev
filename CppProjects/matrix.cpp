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

		int setSerial(int* input, int len){

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

		int get(int x, int y){
			
			if(x < this->horizontalLen && y < this->verticalLen){

				return this->data_ptr[y * this->horizontalLen + x];

			}else{return -1;};

		};

};



int main(){

Matrix testMtrx;


int width;
int height;
int input;
int input1;
int input2;
int input3;
int* temp;

printf("%s ", "input height:");
scanf("%d", &width);
printf("%s ", "input width:");
scanf("%d", &height);

testMtrx.setHeight(height);
testMtrx.setWidth(width);
printf("%s\n", "matrix successfuly created");

while(true){

	printf("%s \n", "choose action:");
	printf("%s\n", "1 - print all");
	printf("%s\n", "2 - get cell");
	printf("%s\n", "3 - set cell");
	printf("%s\n", "4 - serial set");
	printf("\033[0;31m");
	printf("%s\n", "5 - resize");
	printf("%s\n", "6 - empty");
	printf("%s\n", "7 - fill with data");
	printf("\e[1m%s\n", "8 - exit program");
	printf("\033[0m\e[m");
	scanf("%d", &input);

	switch (input){

		case 1:
			testMtrx.printMatrix();
			
			break;

		case 2:
			printf("%s ", "input cell x coordinate:");
			scanf("%d", &input2);
			printf("%s ", "input cell y coordinate:");
			scanf("%d", &input3);
			printf("value: %d\n", testMtrx.get(input2, input3));
			
			break;

		case 3:
			printf("%s ", "input cell x coordinate:");
			scanf("%d", &input2);
			printf("%s ", "input cell y coordinate:");
			scanf("%d", &input3);
			printf("%s ", "input new cell value:");
			scanf("%d", &input1);
			
			if(testMtrx.set(input1, input2, input3) != -1){
			
				printf("inserted data successfully\n");
			
			}
			else{printf("failed to insert data\n");};
			
			break;

		case 4:
			printf("%s ", "input amount of values to insert:");
			scanf("%d", &input1);
			temp = (int*) calloc(input1, (sizeof(int)));
			
			for(int i = 0; i < input1; i++){

				printf("%s %d:\n", "enter value", i);
				scanf("%d", &input2);
				temp[i] = input2;

			};

			if(testMtrx.setSerial(temp, input1) == 1){

				printf("data forcefully patrially truncated\n");

			}else{printf("data successfully inserted\n");};

			free(temp);

			break;
		case 5:
			printf("%s ", "input new width:");
			scanf("%d", &input2);
			printf("%s ", "input new height:");
			scanf("%d", &input3);
			testMtrx.setWidth(input2);
			testMtrx.setHeight(input3);

			break;

		case 6:
			testMtrx.empty();
			printf("successfully emptied matrix\n");
			
			break;

		case 7:
			testMtrx.refill();
			printf("successfully filled with data\n");
			
			break;

		case 8:
			exit(1);
			
			break;
	};

	input = 0;
	input1 = 0;
	input2 = 0;
	input3 = 0;
};

return 0;

}
