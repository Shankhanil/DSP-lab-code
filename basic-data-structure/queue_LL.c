#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


/*
***************** VARIABLE DOCUMENTATION******************
struct Node: a C structure describing a linked-list node. 
int data: data contained in a linked-list node. 
Node *next: a pointer to the next node in the linked-list
----------------------------------------------------------
struct linkedList(typedef-ed as Queue): a C structure 
					describing a queue as a linked-list
Node *front: pointer to the front of the queue
Node *rear: pointer to the rear of the queue
Queue *q: Instance of the Queue structure
**********************************************************
***************** FUNCTION DOCUMENTATION******************
Node *newNode(int data): returns a new linked-list node
void init(int n): Initializes an empty queue of maximum capacity n
_Bool enqueue(int value): enqueues a data(=value) into the queue. 
						If enqueue is successful, returns true, else
						returns false.
int dequeue(): dequeues the front-most element from the queue. 
				If the queue is empty, returns -1.
void traverseQueue(): prints all the elements in the queue.
**********************************************************
*/

typedef struct Node{
	int data;
	struct Node* next;
}Node;

typedef struct linkedList{
	Node* front;
	Node* rear;
} Queue;

Queue* q;

Node* newNode(int data){
	Node* node = (Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	
	return node;
}

void init() {
  q = malloc(sizeof(Queue));
  q->front = NULL;
  q->rear = NULL;
}

void traverse() {
  Node *temp = q->front; 

  while(temp != NULL) { 
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

void enqueue(Node *n) {

	if (q->rear == NULL) { 
        q->front = q->rear = n; 
        return; 
    } 
  
    q->rear->next = n; 
    q->rear = n;
  
}

int dequeue() {
    if (q->front == NULL) 
        return -1; 		
    Node* temp = q->front; 
    q->front = q->front->next; 
    
    if (q->front == NULL) 
        q->rear = NULL; 
  
    free(temp);
	return temp->data;
}


int main() {
	init();
	int c, v;
	
	printf("1-> enqueue, 2-> dequeue, 3-> display, 4->exit\n");
	while(true){
		printf("Enter your choice:");
		scanf("%d", &c);
		switch(c){
			case 1: 
				printf("Enter value to be enqueueed:");
				scanf("%d", &v);
				enqueue(newNode(v));
				break;
			case 2:
				v = dequeue();
				printf("%d", v);
				break;
			case 3:
				traverse();
				break;
			case 4:
				return 0;
			default: printf("Invalid choice, try again");
		}
	}
	return 0;
}
