#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


/*
***************** VARIABLE DOCUMENTATION******************
struct Node: a C structure describing a linked-list node. 
int data: data contained in a linked-list node. 
Node *next: a pointer to the next node in the linked-list
----------------------------------------------------------
struct linkedList(typedef-ed as Stack): a C structure 
					describing a stack as a linked-list
Node *head: pointer to the head of the linked-list
Node *tail: pointer to the tail of the linked-list (also 
			indicating the top element of the stack)
Stack *s: Instance of the Stack structure
**********************************************************

***************** FUNCTIOn DOCUMENTATION******************
Node *newNode(int data): returns a new linked-list node
void init(): Initializes an empty stack
void push(int value): pushes a data(=value) into the stack. 
int pop(): pops and returns the topmost element from the stack. 
			If the stack is empty, returns -1.
void traverseStack(): prints all the elements in the stack.
**********************************************************
*/


typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct linkedList{
	struct Node* head;
	struct Node* tail;
} Stack;

Stack* s;

Node* newNode(int data){
	Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	
	return node;
}

void init() {
  s = malloc(sizeof(Stack));
  s->head = NULL;
  s->tail = NULL;
}

void traverseStack() {
  Node *temp = s->head; 

  while(temp != NULL) { 
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

void push(Node *n) {
  if(s->tail == NULL) { 
    s->head = n;
    s->tail = n;
  }
  else {
    s->tail->next = n;
    s->tail = n;
  }
}

int pop() {
  if(s->tail == NULL) {
    printf("Stack Underflow\n");
	return -1;
  }
  else {
    int x = s->tail->data;
    if(s->tail == s->head) {
      free(s->tail);
      s->tail = NULL;
      s->head = NULL;
    }
    else {
      Node *temp = s->head;
      while(temp->next != s->tail) 
        temp = temp->next;
      temp->next = NULL;
      free(s->tail);
      s->tail = temp;
    }
    return x;
  }
}


int main() {
	init();
	int c, v;
	
	printf("1-> push, 2-> pop, 3-> display, 4->exit\n");
	while(true){
		printf("Enter your choice:");
		scanf("%d", &c);
		switch(c){
			case 1: 
				printf("Enter value to be pushed:");
				scanf("%d", &v);
				push(newNode(v));
				break;
			case 2:
				v = pop();
				printf("%d", v);
				break;
			case 3:
				traverseStack();
				break;
			case 4:
				return 0;
			default: printf("Invalid choice, try again");
		}
	}
	return 0;
}
