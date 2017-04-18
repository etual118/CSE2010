#include <stdio.h>
#include <stdlib.h>

struct HeapStructure {
	int Capacity;
	int Size;
	int *Elements;
};

typedef struct HeapStructure* HeapStruct;

HeapStruct CreateHeap(int heapsize) {
	HeapStruct H;

	H = (HeapStruct)malloc(sizeof(struct HeapStructure));
	if (H == NULL) {
		printf("Out of space!");
	}

	H->Elements = (int*)malloc(sizeof(int)* heapsize);
	if (H->Elements == NULL) {
		printf("Out of space!");
	}

	H->Capacity = heapsize;
	H->Size = 0;

	return H;
}

void Insert(HeapStruct H, int X) {
	int i;
	for (i = 1; i<H->Size + 1; i++) {
		if (X == H->Elements[i]) {
			printf("Insertion Error : There is already %d in the tree\n", X);
			return;
		}
	}
	if (H->Size == H->Capacity) {
		printf("Priority queue is full\n");
		return;
	}

	else if (H->Size >= 0 && H->Size < H->Capacity) {
		H->Elements[++H->Size] = X;
		printf("insert %d\n", X);
	}

	for (i = H->Size; H->Elements[i / 2] < X; i /= 2) {
	  	if(i/2 == 0){
			H->Elements[i] = X;
			return;
		}	
		H->Elements[i] = H->Elements[i / 2];
	}
	H->Elements[i] = X;
}

int DeleteMax(HeapStruct H) {
	int i, Child;
	int MaxElement, LastElement;

	if (H->Size == 0) {
		printf("Delete : Max Heap is empty\n");
		return 0;
	}

	MaxElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];

	for (i = 1; i * 2 <= H->Size; i = Child) {
		Child = i * 2;

		if (Child != H->Size && H->Elements[Child + 1] > H->Elements[Child]) {
			Child++;
		}

		if (LastElement < H->Elements[Child]) {
			H->Elements[i] = H->Elements[Child];
		}
		else {
			break;
		}
	}
	H->Elements[i] = LastElement;
	return MaxElement;
}


void PrintHeap(HeapStruct H){
	int i;

	if (H->Size == 0){
		printf("Print : Max Heap is empty\n");
		return;
	}

	for (i = 1; i <= H->Size; i++){
		printf("%d ", H->Elements[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]){
	int num = 0, count = 1;
	char ch;
	HeapStruct H = NULL;

	FILE *file = fopen(argv[1], "rt");


	while (!feof(file)){

		fscanf(file, "%c", &ch);

		if (ch == 'n'){
			fscanf(file, "%d", &num);

			H = CreateHeap(num);
		}

		else if (ch == 'i'){
			fscanf(file, "%d", &num);

			Insert(H, num);
		}

		
	}

	fclose(file);
	free(H->Elements);
	free(H);

	return 0;
}
