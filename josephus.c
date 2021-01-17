/*
***********************PROGRAM DESCRIPTION*******************
C program to simulate Josephus problem with a circular linked list
*************************************************************

***********************STRUCTURE DESCRIPTION*****************
struct Node: A structure describing a node of a singly linked list
int data: integer variable representing the node data
struct Node* next: pointer to next node in the linked list
Node *head, *current: 
*************************************************************

***********************FUNCTION DESCRIPTION******************
void createCLL(): Generates a circular linked list with N nodes
void displayCLL(): Prints the CLL
void josephus(): Function to simulate the working of josephus problem
*************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node
{
    int data;
    struct Node *next;
}Node;
 
Node *head;


// **********************JOSEPHUS FUNCTION****************
int josephus(int k)
{
    Node *p, *q;
    int i;
 
    q = p = head;
    while (p->next != p)
    {
		// skipping k prisoners
        for (i = 0; i < k - 1; i++)
        {
            q = p;
            p = p->next;
        }
		// killing prisoner at node p
        q->next = p->next;
        printf("%d has been killed.\n", p->data);
        free(p);
        p = q->next;
    }
	// setting the head at p
    head = p;
	
    return (p->data);
}
 
// *******************CLL AUXILIARY FUNCTIONS****************
void createCLL ()
{
	// create the execution ground
    Node *temp, *rear;
    int N, ch;
	// ask for total number of prisoners
    printf("Enter number of prisoners: ");
    scanf("%d", &N);
	
    while(N >= 1)
    {
		// allocate memory blocks for N prisoners
        temp = (Node *)malloc(sizeof(Node));
        temp->data = N;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
        N--;
    }
    rear->next = head;
}
 
void displayCLL()
{
    Node *temp;
 
    temp = head;
    printf("%d   ", temp->data);
    temp = temp->next;
    while (head != temp)
    {
        printf("%d   ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// *********************DRIVER CODE********************
int main()
{
    Node *head = NULL;
    int survive, skip;
 
    createCLL();
    printf("The persons in circular list are:\n");
    displayCLL();
    printf("Enter the number of persons to be skipped: ");
    scanf("%d", &skip);
    survive = josephus(skip);
    printf("The person to survive is : %d\n", survive);
    free(head);
 
    return 0;
}
 