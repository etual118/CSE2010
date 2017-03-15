#include <stdio.h>
#include <string.h>

int main(){
	char array[31];
	printf("enter your name:\n");
	while (1){
		gets(array);
		if (strlen(array) > 30){

			printf("the length of the user name should be up to 30 characters.\n");
			continue;
		}
		else
			break;


	}
	

	printf("your name is %s", array);
	
	return 0;



}
