#include <stdio.h>
#include <stdlib.h>

typedef struct TreeSt* Tree;

struct TreeSt {
	int value;
	Tree left;
	Tree right;
};

Tree InsertNode(int key, Tree root) {
	if (root == NULL) {
		root = (Tree)malloc(sizeof(struct TreeSt));

		if (root == NULL) {
			printf("Out of space!!!\n");
		}
		else {
			root->value = key;
			root->left = root->right = NULL;
			printf("insert %d\n",key);
		}
	}

	else if (key < root->value) {
		root->left = InsertNode(key, root->left);
	}

	else if (key > root->value) {
		root->right = InsertNode(key, root->right);
	}

	return root;
}

Tree FindMax(Tree root) {
	if (root != NULL) {
		while (root->right != NULL) {
			root = root->right;
		}
	}

	return root;
}

Tree DeleteNode(int key, Tree root) {
	Tree TmpCell;

	if (key < root->value) {
		root->left = DeleteNode(key, root->left);
	}

	else if (key > root->value) {
		root->right = DeleteNode(key, root->right);
	}

	else if (root->left && root->right) {
		TmpCell = FindMax(root->left);
		root->value = TmpCell->value;
		root->left = DeleteNode(root->value, root->left);
		
	}

	else {
		TmpCell = root;

		if (root->left == NULL) {
			root = root->right;
		}

		else if (root->right == NULL) {
			root = root->left;
		}

		free(TmpCell);
	}

	return root;
}

Tree FindNode(int key, Tree root) {
	if (root == NULL) {
		return NULL;
	}

	if (key < root->value) {
		return FindNode(key, root->left);
	}

	else if (key > root->value) {
		return FindNode(key, root->right);
	}

	else {
		return root;
	}
}

void PrintInorder(Tree root) { //inorder 순서가 left -> root -> right이므로 
	if (root != NULL) {
		PrintInorder(root->left);
		printf("%d ", root->value);
		PrintInorder(root->right);
	}
	else {
		return;
	}
}

void PrintPreorder(Tree root) { //preorder 순서가 root -> left -> right이므로 
	if (root != NULL) {
		printf("%d ", root->value);
		PrintPreorder(root->left);
		PrintPreorder(root->right);
	}
	else {
		return;
	}
}

void PrintPostorder(Tree root) { //postorder 순서가 left -> right -> root이므로 
	if (root != NULL) {
		PrintPostorder(root->left);
		PrintPostorder(root->right);
		printf("%d ", root->value);
	}
	else {
		return;
	}
}

void Free(Tree root) { //모두 free하기 위해서 다음과 같이 재귀?하여 모두 free
	if (root != NULL) {
		Free(root->left);
		Free(root->right);
		free(root);
	}
	else {
		return;
	}
}


int main(int argc, char *argv[]) {

	int num = 0, count = 1;
	char ch;
	Tree root = NULL;

	FILE *file = fopen(argv[1], "rt");


	while (!feof(file)) {

		fscanf(file, "%c", &ch);

		if (ch == 'i') {
			fscanf(file, "%d", &num);

			if (FindNode(num, root) != NULL) {
				printf("Insertion Error : There is already %d in the tree.\n", num);
			}
			else {
				root = InsertNode(num, root);
			}
		}

		else if (ch == 'd') {
			fscanf(file, "%d", &num);

			if (FindNode(num, root) == NULL) {
				printf("Deletion Error : %d is not in the tree.\n", num);
			}
			else {
				root = DeleteNode(num, root);
				printf("Delete %d\n",num);
			}
		}

		else if (ch == 'f') {
			fscanf(file, "%d", &num);

			if (FindNode(num, root) == NULL) {
				printf("%d is not in the tree.\n", num);
			}
			else {
				printf("%d is in the tree.\n", num);
			}
		}

		else if (ch == 'p') {
			fscanf(file, "%c", &ch);

			if (ch == 'i') {
				PrintInorder(root);
			}

			else if (ch == 'r') {
				PrintPreorder(root);
			}

			else if (ch == 'o') {
				PrintPostorder(root);
			}

			printf("\n");
		}

		while ((ch = fgetc(file)) != '\n') {
			if (ch == EOF)
				break;
		}
	}

	fclose(file);

	Free(root);

	return 0;
}
