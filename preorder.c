
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

  
int postIndex = 0; 
  
int search(int *in, int data,int n) 
{ 
    int i = 0; 
    for (i = 0; i < n; i++) 
        if (in[i] == data) 
            return i; 
    return i; 
} 
  
void fillPreorder(int *in, int *post, int inStrt,int inEnd, int n) 
{ 
    if (inStrt > inEnd) 
        return; 
  
    int val = post[postIndex]; 
    int inIndex = search(in, val, n); 
    postIndex--; 
  
    // traverse right tree 
    fillPreorder(in, post, inIndex + 1, inEnd, n); 
  
    // traverse left tree 
    fillPreorder(in, post, inStrt, inIndex - 1, n); 
	
	push(stack, val);
} 
 
void printPreorder(int *in, int *post, int n) 
{ 
    int len = n; 
    postIndex = len - 1; 
    // stack<int> s ; 
    fillPreorder(in, post, 0, len - 1,n); 
    while (!isEmpty(stack)) 
    { 
        // cout << s.top() << " "; 
		printf("%d ", stack->stackArray[stack->top]);
        // s.pop(); 
		pop(stack);
    } 
} 
  
// Driver code 
int main() 
{ 
   	int *in; // = { 4, 2, 5, 1, 6, 3, 7 }; 
	int *post; //  = {  4, 5, 2, 6, 7, 3, 1 }; 
	int n;
	// int n = sizeof(in) / sizeof(in[0]); 
	
	scanf("%d", &n);
	in = (int*) calloc(n, sizeof(int));
	post = (int*) calloc(n, sizeof(int));
	init(n);
	for(int i=0; i<n; i+){
		scanf("%d", (in + i ));
	}
	for(int i=0; i<n; i+){
		scanf("%d", (post + i ));
	}
	
    printPreorder(in, post,n); 
} 
  
