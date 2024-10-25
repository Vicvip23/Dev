#include <cstdio>
#include <cstdlib>
#include "matrix.cpp"

int main(){

Matrix testMtrx;


unsigned int width;
unsigned int height;
int input;
float input1;
unsigned int input2;
unsigned int input3;
float* temp;

printf("%s ", "input height:");
scanf("%u", &width);
printf("%s ", "input width:");
scanf("%u", &height);

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
			scanf("%u", &input2);
			printf("%s ", "input cell y coordinate:");
			scanf("%u", &input3);
			printf("value: %d\n", testMtrx.get(input2, input3));
			
			break;

		case 3:
			printf("%s ", "input cell x coordinate:");
			scanf("%u", &input2);
			printf("%s ", "input cell y coordinate:");
			scanf("%u", &input3);
			printf("%s ", "input new cell value:");
			scanf("%f", &input1);
			
			if(testMtrx.set(input1, input2, input3) != -1){
			
				printf("inserted data successfully\n");
			
			}
			else{printf("failed to insert data\n");};
			
			break;

		case 4:
			printf("%s ", "input amount of values to insert:");
			scanf("%u", &input2);
			temp = (float*) calloc(input2, (sizeof(float)));
			
			for(int i = 0; i < input2; i++){

				printf("%s %d:\n", "enter value", i);
				scanf("%f", (temp + i));

			};

			if(testMtrx.setSerial(temp, input2, 2, 19) == 1){

				printf("data forcefully patrially truncated\n");

			}else{printf("data successfully inserted\n");};

			free(temp);

			break;
		case 5:
			printf("%s ", "input new width:");
			scanf("%u", &input2);
			printf("%s ", "input new height:");
			scanf("%u", &input3);
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