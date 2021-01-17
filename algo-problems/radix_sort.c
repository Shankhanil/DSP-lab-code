#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN -999999
#define MAX  999999

#define LIMIT 100
typedef struct node{
	int data;
	struct node *next, *prev;
} Node;

typedef struct dll{
	Node *head, *tail;
	int length;
} dll;


Node *newNode(int data){
	Node *node;
	node = (Node*)malloc(sizeof(Node));
	
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

dll* init(dll *L){
	L = (dll*) malloc(sizeof(dll));
	
	L->head = newNode(MIN);
	L->tail = newNode(MAX);
	L->length = 0;
	L->head->next = L->tail;
	L->tail->prev = L->head;
//	printf("%u", L->head);
	return L;
}

bool isPresent(dll *L, Node* n){
	Node* temp;
	temp = L->head;
	
	while (temp != L->tail){
		if (temp == n) return true;
		temp = temp->next;
	}
	return false;
}

Node* search(dll *L, int data){
	Node* temp;
	temp = L->head;
	
	while (temp != L->tail){
		if (temp->data == data) return temp;
		temp = temp->next;
	}
	return NULL;
}

Node* insert( dll *L, Node* n, int data ){
	Node *newN = newNode(data);
	if (!isPresent(L, n)) return NULL;
	else if( L->length < LIMIT){
		Node *Nnext;
		Nnext = n->next;
		
		newN->next = Nnext;
		newN->prev = n;
		
		Nnext->prev = newN;
		n->next = newN;
		L->length++;
		return newN;
	}
	else{
		return NULL;
	}
}

void traverse(dll *L){
	Node *temp = L->head->next;
	printf("[HEAD]->");
	while(temp != L->tail){
		printf("%d ->", temp->data);
		temp = temp->next;
	}
	printf("[TAIL]\n");
}

Node *getMax(dll *L){
	Node *temp;
	temp = L->head->next;
	Node* max = newNode(MIN);
	while(temp != L->tail){
		if (temp->data > max->data) max = temp;
		temp = temp->next;
	}
	return max;
}

main(){
	dll *L1, *L2;
	L2 = init(L2);
	L1 = init(L1);

	Node *n, *n2;
	
	n = insert(L1, L1->head, 2);
	n = insert(L1, n, 3);
	n = insert(L1, n, 5);

	n2 = insert(L2, L2->head, -4);
	n2 = insert(L2, n2, -8);
	n2 = insert(L2, n2, -2);

	traverse(L1);
	traverse(L2);

	return 0;
}
