#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
***************** VARIABLE DOCUMENTATION******************
struct Queue: a C structure describing a queue
int *queue: the queue implemented as an int pointer(array)
int front, rear: variable indicating the front and rear element of the queue
int maxSize: variable indicating the capacity of the queue
int size: variable indicating current size of the queue
Queue q: instance of the Queue structure
**********************************************************

***************** FUNCTIOn DOCUMENTATION******************
void init(int n): Initializes an empty queue of maximum capacity n
_Bool enqueue(int value): enqueues a data(=value) into the queue. 
						If enqueue is successful, returns true, else
						returns false.
int dequeue(): dequeues the front-most element from the queue. 
				If the queue is empty, returns -1.
void traverseQueue(): prints all the elements in the queue.
**********************************************************
*/


typedef struct Queue{
    int *queue;
    int front, rear, maxSize, size;
} Queue;

Queue q;

void init(int n){
    q.queue = calloc(n, sizeof(int));
    q.maxSize = n;
    q.front = 0;
	q.size = 0; 
	q.rear = q.maxSize-1;
}

_Bool enqueue(int value){
    if (q.size == q.maxSize) 
        return false; 
    q.rear = (q.rear + 1)% q.maxSize; 
    q.queue[q.rear] = value; 
    q.size = q.size + 1; 
	return true;
}

int dequeue(){
    if (q.size == 0) return -1;
	int v = q.queue[q.front];
	q.front = (q.front + 1) % q.maxSize; 
    q.size = q.size - 1; 
    return v;
}

void traverseQueue(){
    int i=q.front;
    while (i<=q.rear){
        printf("%d ", q.queue[i]);
        i++;
    }
    printf("\n");
}

int main(void) {
    int N, c, v;
    
	printf("Enter the max size of the queue:");
    scanf("%d", &N);
	init(N);
	
	printf("1-> enqueue, 2-> dequeue, 3-> display, 4->exit\n");
	while(true){
	    printf("Enter your choice:");
        scanf("%d", &c);
        switch(c){
            case 1: 
                printf("Enter value to be enqueueed:");
                scanf("%d", &v);
                enqueue(v);
                break;
            case 2:
                v = dequeue();
                if (v == -1) printf("Queue underflow\n");
                else printf("%d\n", v);
                break;
            case 3:
                traverseQueue();
                break;
            case 4:
                return 0;
            default: printf("Invalid choice, try again");
        }
	}
	return 0;
}

