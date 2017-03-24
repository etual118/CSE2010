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
int IsLast(Position P, List L) {
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
Position FindPrevious(ElementType X, List L){
	Position P;

	P = L;
	while(P -> Next != NULL && P -> Next -> Element != X){
		P = P -> Next;
	}

	return P;
}

void Delete(ElementType X, List L){
	Position P, TmpCell;

	P = FindPrevious(X, L);
	if(!IsLast(P, L)){
		TmpCell = P -> Next;
		P -> Next = TmpCell -> Next;
		free(TmpCell);
	}
}

Position Find(ElementType X, List L){
	Position P;

	P = L -> Next;
	while(P != NULL && P -> Element != X){
		P = P -> Next;
	}

	return P;
}

void DeleteList(List L){
	MakeEmpty(L);
	free(L);
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
			if(b==-1) 
				Insert(a, L, L);
			else{
				if (Find(a, L) != NULL) printf("Insertion(%d) Failed : element %d is already in the list\n", a, a);
				else if(Find(b, L) == NULL) printf("Insertion(%d) Failed : element %d is not in the list\n", a, b);
				
				else Insert(a, L, Find(b, L));
			}	
				
			break;
		case'p':
			PrintList(L);
			break;
		case'd':
			fscanf(file,"%d",&a);
			if(Find(a, L) == NULL) printf("Deletion failed : element %d is not in the list\n", a);
			else Delete(a, L);	
			break;
		case'f':
			fscanf(file, "%d", &a);

			if(Find(a, L) == NULL) printf("Could not find %d in the list\n", a);
			else if((L -> Next -> Element) == a)  printf("Key of the previous node of %d is header.\n", a);
			else printf("Key of the previous node of %d is %d.\n", a, FindPrevious(a, L) -> Element);
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
