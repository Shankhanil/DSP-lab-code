#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MIN 0
#define MAX 999999

// dll node
typedef struct node
{
	int data;
	struct node *prev, *next;
	
} Node;

typedef struct DLList{
	Node *head, *tail, *curr;
} DLList;

//*****************DLL FUNCTIONS****************
Node *newNode(int data){
	Node *node;
	node = (Node*)malloc(sizeof(Node));
	
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

DLList* init(DLList *L){
	L = (DLList*) malloc(sizeof(DLList));
	
	L->head = newNode(MIN);
	L->tail = newNode(MAX);
	L->head->next = L->tail;
	L->tail->prev = L->head;
//	printf("%u", L->head);
	return L;
}

bool isPresent(DLList *L, Node* n){
	Node* temp;
	temp = L->head;
	
	while (temp != L->tail){
		if (temp == n) return true;
		temp = temp->next;
	}
	return false;
}

bool isEmpty(DLList *L){
	return (L->head->next == L->tail);
}
/*
Node* search(DLList *L, int data){
	Node* temp;
	temp = L->head;
	
	while (temp != L->tail){
		if (temp->data == data) return temp;
		temp = temp->next;
	}
	return NULL;
}
*/
Node* insert( DLList *L, Node* n, int data ){
	Node *newN = newNode(data);
	if (!isPresent(L, n)) return NULL;
	Node *Nnext;
	Nnext = n->next;
	
	newN->next = Nnext;
	newN->prev = n;
	
	Nnext->prev = newN;
	n->next = newN;
	return newN;
}

void traverse(DLList *L){
	Node *temp = L->head->next;
	printf("[HEAD]->");
	while(temp != L->tail){
		printf("%d ->", temp->data);
		temp = temp->next;
	}
	printf("[TAIL]\n");
}

Node *getMax(DLList *L){
	Node *temp;
	temp = L->head->next;
	Node* max = newNode(MIN);
	while(temp != L->tail){
		if (temp->data > max->data) max = temp;
		temp = temp->next;
	}
	return max;
}
int deleteHead(DLList *L){
	int v = L->head->next->data;
	L->head->next = L->head->next->next;
	
	return v;
}

DLList *copyList(DLList *list){
	DLList *tempL;
	tempL = init(tempL);
	Node *tempNode = list->head->next;
	while(tempNode != list->tail){
		insert(tempL, tempL->head, tempNode->data);
		tempNode = tempNode->next;
	}
	traverse(tempL);
}

//***************RADIX SORT FUNCTIONS****************

int count(DLList *list){  
	int ct = 0;  int ct2 = 0;  int tmp = 0;    
	DLList *temp;
	temp = copyList(list);
	while(!isEmpty(temp)){
		ct = ct2;
		tmp = deleteHead(temp);
		
		if(tmp > 0) ct2 += 1+(int)log10(tmp);
		
		if(ct2 < ct){ 
			ct2 = ct;       
		}    
	}
//	printf("ct2 = %d", ct2);
	return ct2;
}


void radix_sort(DLList *list){  
	DLList *lstRay[10], *tempL;
	tempL = copyList(list);
	int ct = count(tempL);
	int zeros = 0, x; 
	int tmp = 0;  int head = 0;   
	traverse(list);
	for(x = 0; x <=9; x++){ 
		lstRay[x] = init(lstRay[x]);
	}
	
	for(;ct >= 0; ct--)
	{      
		traverse(tempL);
		while(!isEmpty(tempL)) {
			head = deleteHead(tempL);   
			tmp = head / pow(10, zeros); // included the feedback
			tmp = tmp % 10;
			printf("tmp = %d ", tmp);
			insert(lstRay[tmp], lstRay[tmp]->tail->prev, head); 
		}
				
		for(x = 0; x <=9; x++){ 
//			list.append(lstRay[x]);
//			printf("%d   ", x);
//			traverse(lstRay[x]);
//			printf("\n");
		}      
		zeros++;       
	}  
} 

main(){
	DLList *L1, *L2;
	L2 = init(L2);
	L1 = init(L1);

	Node *n, *n2;
	
	n = insert(L1, L1->head, 2);
	n = insert(L1, n, 3);
	n = insert(L1, n, 5);

//	n2 = insert(L2, L2->head, -4);
//	n2 = insert(L2, n2, -8);
//	n2 = insert(L2, n2, -2);

	traverse(L1);
//	traverse(L1);
//	traverse(L2);
//	count(L1);
	radix_sort(L1);
	return 0;
}
