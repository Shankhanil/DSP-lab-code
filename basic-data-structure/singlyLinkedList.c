/*
***********************PROGRAM DESCRIPTION*******************
C program to implement a singly linked list. NOTE: The insert 
function can insert only at the head. 
*************************************************************

***********************STRUCTURE DESCRIPTION*****************
struct Node: A structure describing a node of a singly linked list
int data: integer variable representing the node data
struct Node* next: pointer to next node in the linked list
Node *head, *current: 
*************************************************************

***********************FUNCTION DESCRIPTION******************
void init(): initializes a stack by allocating memory for Stack* 
			stack and setting top and maxsize
void push(), pop(): Stack push and pop function.
void showDiskMovement(): Displays a sweet message saying which disk is displaced
void showDiskMovementBetweenRods(): moves a disk from one rod to another
void towerOfHanoi(): simulates the tower of hanoi
*************************************************************
*/



#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
   int data;
   struct Node *next;
}Node;

Node *head = NULL;
Node *current = NULL;

void printList() {

   Node *ptr = head;

   printf("\n[head] =>");
   while(ptr != NULL) {        
      printf(" %d =>",ptr->data);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}

void insert(int data) {
	// initializing new node
	Node *newNode = (Node*) malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = head;
	
	// and set head as the new node. 
	head = newNode;
}

Node* search(int data){
	// initializing current pointer as head
    current = head;
	// and searching for the node whose value == data
    while (current->next != NULL){
		// if found, return the node address
        if (current->data == data) return current;
        current = current->next;
    }
	// if not found, return NULL
    return NULL;
}


_Bool Delete(int data){
	// search for a node with the value
    current = search(data);
	
	// if node not found, then return false
    if (current == NULL) return false;
	
	// if node is the head, update the head 
    if (current == head) {
        head = head->next;
        return true;
    }
	
	// else, delete it old fashioned way
    Node *nodeBefore = head, *nodeAfter = current->next;
    while (nodeBefore->next != current && nodeBefore->next != NULL){
        nodeBefore = nodeBefore->next;
    }
    nodeBefore->next = nodeAfter;
    return true;
}

void reverse()
{
	// initialize the nodeBefore and nodeAfter node with null
    Node* nodeBefore = NULL;
    Node* current = head;
    Node* nodeAfter = NULL;
	
    while (current != NULL) {
        // Store nodeAfter
        nodeAfter = current->next;
 
        // Reverse current node's pointer
        current->next = nodeBefore;
 
        // Move pointers one position ahead.
        nodeBefore = current;
        current = nodeAfter;
    }
    head = nodeBefore;
}


int main() {
	printf("press 1 for Insert, 2 for delete, 3 for display, \n4 for reverse LL and 5 for exit\n");
	int v, c;
	while(true){
	    printf("Enter your choice:");
        scanf("%d", &c);
        switch(c){
            case 1: 
                printf("Enter value to be inserted:");
                scanf("%d", &v);
                insert(v);
                printList();
                break;
            case 2:
                printf("Enter value to be deleted:");
                scanf("%d", &v);
                if ( !Delete(v) ) printf("Value %d not found in list", v);
                printList();
                break;
			case 3:
				printList();
				break;
			case 4: 
				reverse();
				printList();
				break;
            case 5:
                return 0;
            default: printf("Invalid choice, try again");
        }
	}
	reverse();
	printList();
   return 0;
}
