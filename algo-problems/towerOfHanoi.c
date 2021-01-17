/*
***********************PROGRAM DESCRIPTION*******************
C program to simulate the tower of Hanoi
*************************************************************


***********************STRUCTURE DESCRIPTION*****************
struct Stack: A structure describing a stack
int top: integer variable representing the top of the stack
unsigned maxSize: unsigned int variable representing the max
					capacity of the stack
int *stackArray: integer stackArray representing the stack as an stackArray
Stack* stack: a stack
*************************************************************

***********************VARIABLE DESCRIPTION******************
Stack *src: A stack implementing the source rod in the tower of hanoi
Stack *aux: A stack implementing the auxiliary rod
Stack *dest: A sstack implementing the destination rod
unsigned diskCount: Total number of disks in the tower
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
#include <math.h> 
#include <stdlib.h> 
#include <limits.h>




// Stack definition
typedef struct 
{ 
	int top; 
	unsigned maxSize; //maxSize of the stack
	int* stackArray; 
} Stack; 

Stack *stack;
Stack *src;
Stack *aux;
Stack *dest;


// ***********************STACK AUXILIARY FUNCTIONS******************

Stack* init( unsigned maxSize ) 
{ 
	// memory allocation for stack
	stack = (Stack*) malloc(sizeof(Stack*)); 

	//initializing stack variables
	stack->top = -1; 
	stack->maxSize = maxSize; 
	// memory allocation for stack stackArray
	stack->stackArray = (int*) calloc(stack->maxSize, sizeof(int)); 
	return stack; 
} 

int isEmpty(Stack *stack) 
{ 
	return (stack->top == -1); 
} 
int isFull(Stack *stack) 
{
	return (stack->top == stack->maxSize-1);
}


void push( Stack *stack, int item) 
{ 	
	if (isFull(stack)) // if stack overflows, stack push fails
		return;
	stack->stackArray[++stack->top] = item;  // else push to stack
}

int pop( Stack *stack) 
{ 
	//if stack is empty, then it is undeflow cond
	if (isEmpty(stack)) 
		return INT_MIN; 
	return stack->stackArray [stack->top--];
}


// ************************TOWER OF HANOI HELPER FUNCTIONS******************
void showDiskMovement(char sourceRod, char destRod, int disk ){
	printf("\nMove the disk %d from rod %c to rod  % c\n", disk, sourceRod, destRod);
}


void showDiskMovementBetweenRods(Stack *src, Stack *dest, char s, char d)
{
	int disk1 = pop(src);
	int disk2 = pop(dest);
	
	//when rod 1 is empty
	if(disk1 == INT_MIN)
	{
		push(src, disk2);
		showDiskMovement(d,s, disk2);
	}
	//when rod 2 is empty
	else if(disk2 == INT_MIN)
	{
		push(dest, disk1);
		showDiskMovement(s,d, disk1);
	}
	//when top disk of Rod1 > top disk of Rod2
	else if (disk1 > disk2)
	{
		push(src, disk1);
		push(src, disk2);
		showDiskMovement(d, s, disk2);
	}
	//when top disk of Rod1 < top disk of Rod2
	else
	{
		push(dest, disk2);
		push(dest, disk1);
		showDiskMovement(s, d, disk1);
	}
}

void towerOfHanoi(int diskCount, Stack *src, Stack *aux, Stack *dest )
{
	int i, totalMoveCount;
	char s = 'S', d ='D', a ='A';
	
	// if no of disk is even, then interchange destination rod to auxilari rod
	if(diskCount %2 == 0)
	{
		char temp = d;
		d = a;
		a = temp;
	}
	//total move required = pow(2,n)-1, n = no of disk
	totalMoveCount = pow(2, diskCount)-1; 
	
	//larger disk will be pushed first
	for (i = diskCount; i>=1; i--)
		push(src,i);
	for (i = 1; i<=totalMoveCount; i++)
	{
		if (i%3 == 1) 
			//top disk movement will be between source and destination rod, in both direction
			showDiskMovementBetweenRods(src, dest, s, d);
		else if(i % 3 == 2) 
			//top disk movement will be between source and auxiliary rod, in both direction
			showDiskMovementBetweenRods(src, aux, s, a);
		else if(i % 3 == 0) 
			//top disk movement will be between destination and auxiliary rod, in both direction
			showDiskMovementBetweenRods(aux, dest, a, d);
	}
}

// *******************************DRIVER CODE***********************
int main()
{
	// printf("-----Tower of Hanoi---");
	printf("Enter number of disks at the tower of hanoi:");
	//input number of disk
	unsigned diskCount ;
	scanf("%d", &diskCount);
	
	Stack *src, *dest, *aux;
	// Create three stacks of size 'diskCount' to hold the disks
	src = init(diskCount);
	aux = init(diskCount);
	dest = init(diskCount);
	
	towerOfHanoi(diskCount, src, aux, dest);
	return 0;
	
}
