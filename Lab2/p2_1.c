#include <stdio.h>

void swap(int** x, int** y){
	int tmp = **x;
	**x= **y;
	**y = tmp;
}
int main(){
	int A, B;

	int* pA;
	int* pB;
	int** ppA;
	int** ppB;

	printf("enter two integers\n");

	scanf("%d %d", &A, &B);

	ppA = &pA;
	ppB = &pB;

	pA = &A;
	pB = &B;

	printf("you entered\n%d, %d\n", **ppA, **ppB);
	swap(ppA, ppB);
	

	printf("after swapping\n%d, %d\n", **ppA, **ppB);

	return 0;

}
