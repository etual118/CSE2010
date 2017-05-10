#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;

typedef struct AVLNode{
	ElementType Element;
	AVLTree Left;
	AVLTree Right;
	int Height;
}AVLNode;

Position SingleRotateWithLeft(Position node);
Position SingleRotateWithRight(Position node);
Position DoubleRotateWithLeft(Position node);
Position DoubleRotateWithRight(Position node);
AVLTree Insert(ElementType X, AVLTree T);
void printInorder(AVLTree T);
int getHeight(Position node);

int main(int argc, char** argv) {
	int num; 
	AVLTree T = NULL;
	FILE *file = fopen(argv[1], "rt");
	while (!feof(file)) {
		fscanf(file, "%d", &num);
		T = Insert(num, T);
		printInorder(T);
		printf("\n");
	}
	fclose(file);
	return 0;
}


int getHeight(Position node) {
	if (node == NULL) {
		return -1;
	}
	else {
		return node->Height;
	}
}

int Max(int A, int B) {
	if (A >= B) {
		return A;
	}
	else {
		return B;
	}
}

Position SingleRotateWithLeft(Position node) {
	Position root;

	root = node->Left;
	node->Left = root->Right;
	root->Right = node;

	node->Height = Max(getHeight(node->Left), getHeight(node->Right)) + 1;
	root->Height = Max(getHeight(root->Left), node->Height) + 1;

	return root;
}

Position SingleRotateWithRight(Position node) {
	Position root;

	root = node->Right;
	node->Right = root->Left;
	root->Left = node;

	node->Height = Max(getHeight(node->Left), getHeight(node->Right)) + 1;
	root->Height = Max(node->Height, getHeight(root->Right)) + 1;

	return root;
}

Position DoubleRotateWithLeft(Position node) {
	node->Left = SingleRotateWithRight(node->Left);
	return SingleRotateWithLeft(node);
}

Position DoubleRotateWithRight(Position node) {
	node->Right = SingleRotateWithLeft(node->Right);
	return SingleRotateWithRight(node);
}

AVLTree Insert(ElementType X, AVLTree T) {
	if (T == NULL) {
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		if (T == NULL) {
			printf("Out of space!!!\n");
		}
		else {
			T->Element = X;
			T->Height = 0;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element) {
		T->Left = Insert(X, T->Left);
		if (getHeight(T->Left) - getHeight(T->Right) == 2) {
			if (X < T->Left->Element) {
				T = SingleRotateWithLeft(T);
			}
			else {
				T = DoubleRotateWithLeft(T);
			}
		}
	}
	else if (X > T->Element) {
		T->Right = Insert(X, T->Right);
		if (getHeight(T->Right) - getHeight(T->Left) == 2) {
			if (X > T->Right->Element) {
				T = SingleRotateWithRight(T);
			}
			else {
				T = DoubleRotateWithRight(T);
			}
		}
	}

	T->Height = Max(getHeight(T->Left), getHeight(T->Right)) + 1;
	return T;
}

void printInorder(AVLTree T) {
	if (T != NULL) {
		printInorder(T->Left);
		printf("%d(%d) ", T->Element, T->Height);
		printInorder(T->Right);
	}
	else {
		return;
	}
}

