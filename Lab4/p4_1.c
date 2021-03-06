#include <stdio.h>
#include <stdlib.h>


typedef struct CircularQueue{
	int *key;
	int first;
	int rear;
	int qsize;
	int max_queue_size;
}CircularQueue;

CircularQueue* MakeEmpty(int max){
	CircularQueue* newQueue = (CircularQueue*)malloc(sizeof(CircularQueue));
	newQueue->key = (int*)malloc(sizeof(int)*max);
	newQueue->qsize = 0;
	newQueue->first = 0;
	newQueue->rear = -1;
	newQueue->max_queue_size = max;
	return newQueue;
}


int IsEmpty(CircularQueue* Q){
	if (Q->qsize == 0) return 1;
	else return 0;
}

int IsFull(CircularQueue* Q){
	if (Q->qsize == Q->max_queue_size) return 1;
	else return 0;
}

void Enqueue(CircularQueue* Q, int X){
	Q->rear = NextPosition(Q->rear, Q);
	Q->key[Q->rear] = X;
	Q->qsize++;
	printf("Enqueue success.\n");
}
int NextPosition(int position, CircularQueue* Q){
	if (position == (Q->max_queue_size)-1) return 0;
	else return position + 1;
}
int main(int argc, char *argv[]){

	char ch;
	int num;
	CircularQueue* Q;

	FILE *file = fopen(argv[1], "rt");

	if (argc < 2){
		printf("write input file.\n");
		return 0;
	}

	while ((ch = fgetc(file)) != EOF){

		if (ch == 'n'){
			fscanf(file, "%d", &num);

			Q = MakeEmpty(num);

		}

		else if (ch == 'e'){
			fscanf(file, "%d", &num);

			if (IsFull(Q)){
				printf("Enqueue failed : Queue is full!\n");
			}
			else{
				Enqueue(Q, num);
			}
		}

	}

	fclose(file);
	

	return 0;
}
