#include <stdio.h>


void add(int a, int b){
	int result;
	result = a + b;
	printf("Result : %d \n", result);
}
void minus(int a, int b){
	int result;
	result = a - b;
	printf("Result : %d \n", result);
}
void multi(int a, int b){
	int result;
	result = a * b;
	printf("Result : %d \n", result);
}
void divide(int a, int b){
	double result;
	result = (double) a / b;
	printf("Result : %lf \n", result);
}
int main(){
	
	void (*calc) (int, int);
	int a,b,c;

	while (1){
		puts("========================");
		puts("0. add\n1. sub\n2. mul\n3. div\n4. exi");
		puts("========================");
		printf("Select operation : ");
		scanf("%d", &c);
		if (c == 4)
			break;

		else if (c == 0 || c == 1 || c == 2 || c == 3){
			printf("Input 2 operand : ");
			scanf("%d %d", &a, &b);
			if (c == 0){
				calc = add;
				calc(a, b);
			}
			else if (c == 1){
				calc = minus;
				calc(a, b);
			}
			else if (c == 2){
				calc = multi;
				calc(a, b);

			}
			else if (c == 3) {
				calc = divide;
				calc(a, b);
			}

		}
		else puts("Please enter correct number");
		
			
	}
	return 0;
}


