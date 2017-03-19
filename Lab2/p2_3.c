#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int n;
	char input[31], **names;
	n = atoi(argv[1]);
	if (n < 3){
		puts("please enter number larger than 2");
	}
	else{
		names = (char**)malloc(n * sizeof(char*));

		printf("enter %d names:\n", n);

		int i = 0;
		for ( i = 0; i < n; i++)
		{
			scanf("%s", input);

			names[i] = (char*)malloc((strlen(input) + 1) * sizeof(char));
			strcpy(names[i], input);
		}

		printf("the names you entered:\n");
		int a = 0;
		for ( a = 0; a < n; a++)
		{
			printf("%s\n", names[a]);
			free(names[a]);
		}
		free(names);
	}
	return 0;
}

