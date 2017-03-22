#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
typedef int ElementType;
typedef PtrToNode List;
typedef PtrToNode Position;


struct Node{
	ElementType	Element;
	Position	Next;
};

List MakeEmpty(List H){
	H = (List)malloc(sizeof(List));
	H->Element = 0;
	H->Next = NULL;
	return H;
}
int IsEmpty(List L) {
	return L->Next == NULL;
}
int lsLast(Position P, List L) {
	return P->Next == NULL;
}
void Insert(ElementType X, List L, Position P){
	Position TmpCell;
	TmpCell = (Position)malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		printf("Out of space!");

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
void PrintList(List L){
	Position P;
	P = L->Next;
	
	while (P != NULL){
		printf("key:%d\t", P->Element);
		P = P->Next;
                
	}
	printf("\n");
}

int main(int argc, char* argv[]){
	int a = 0, b = 0, line = 2;
	char input;
	List L, header;
	header = (List)malloc(sizeof(struct Node));
	L = header;
	L->Next = NULL;
	L->Element = -1;
	
	FILE *file = fopen(argv[1], "rt");
	
	while (fscanf(file, "%c", &input) != EOF){
                
		
		switch (input){
		case 'i':
			fscanf(file, "%d %d", &a, &b);
		
			Insert(a, L, L);
			
			break;
		case'p':
			PrintList(L);
			break;
		case'd':
			printf("It is unsupported feature.\n");
			break;
		case'f':
			printf("It is unsupported feature.\n");
			break;
		case'\n':
			break;
		default:
			printf("not defined order.\n");
		}
			
		
		
                           

	}
        fclose(file);
	return 0;


}
