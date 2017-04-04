#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct StackRecord *Stack;
typedef int ElementType;
#define MAX (100)
#define EmptyTOS (-1)

struct StackRecord {
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

void MakeEmpty(Stack S) {
	S->TopOfStack = EmptyTOS;
}

Stack CreateStack(int MaxElements) {
	Stack S;

	S = (Stack)malloc(sizeof(struct StackRecord));
	if (S == NULL) {
		printf("Out of space!");
	}

	S->Array = (int*)malloc(sizeof(int)* MaxElements);
	if (S->Array == NULL) {
		printf("Out of space!");
	}
	S->Capacity = MaxElements;
	S->TopOfStack = EmptyTOS;
	MakeEmpty(S);

	return S;
}

int IsFull(Stack S) {
	return S->TopOfStack == MAX;
}

int IsEmpty(Stack S) {
	return S->TopOfStack == EmptyTOS;
}

void Push(ElementType X, Stack S) {
	if (IsFull(S)) {
		printf("Error : Full stack");
	}
	else {
		S->Array[++S->TopOfStack] = X;
	}
}

void Pop(Stack S) {
	if (IsEmpty(S)) {
		printf("Error : Empty stack");
	}
	else {
		S->TopOfStack--;
	}
}

int Top(Stack S) {
	if (IsEmpty(S)) {
		printf("Empty stack");
		return 0;
	}
	else {
		return S->Array[S->TopOfStack];
	}
}

int calc(int X, int Y, char oper) {
	if (oper == '+') return X + Y;
	else if (oper == '-') return X - Y;
	else if (oper == '*') return X * Y;
	else if (oper == '/') return X / Y;
	else if (oper == '%') return X % Y;
	else return 0;

}
int main(int argc, char** argv) {

	char ch;
	int tran, op1, op2;
	int i = 0, push = 0, count = 0;
	int num[MAX];
	FILE *file = fopen(argv[1], "rt");

	if (argc < 2) {
		printf("write input file.\n");
		return 0;
	}

	Stack S = CreateStack(MAX);

	while ((ch = fgetc(file)) != EOF)
		count++;

	if (count > 100) {
		printf("wrong input file.");

		return 0;
	}
	fseek(file, 0, SEEK_SET);
	for (i = 0; i < count; i++) {
		fscanf(file, "%c", &ch);
		;
		if (isdigit(ch) && ch != '0') {
			tran = ch - '0';
			Push(tran, S);
			num[push++] = tran;
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
			op2 = Top(S);
			Pop(S);
			op1 = Top(S);
			Pop(S);

			Push(calc(op1, op2, ch), S);
			num[push++] = calc(op1, op2, ch);
		}
		else if (ch == '#') {
			printf("Pushed numbers : ");
		for (i = 0; i < push; i++) {
			printf("%d ", num[i]);
		}
		printf("\nevaluation result : %d\n", Top(S));
		}
		

	}
	fclose(file);
	free(S);

	return 0;

}
