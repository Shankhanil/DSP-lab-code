
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

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

void traverse() {
  Node *temp = s->head; 

  while(temp != NULL) { 
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}


int isEmpty(Stack *s) {
  if(s->tail == NULL)
    return 1;
  return 0;
}

void push(Node *n) {
  if(isEmpty(s)) { 
    s->head = n;
    s->tail = n;
  }
  else {
    s->tail->next = n;
    s->tail = n;
  }
}

int pop() {
  if(isEmpty(s)) {
    printf("Stack Underflow\n");
   
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
				traverse();
				break;
			case 4:
				return 0;
			default: printf("Invalid choice, try again");
		}
	}
	return 0;
}
