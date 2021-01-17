/*
***********************PROGRAM DESCRIPTION*******************
C program to convert a infix expression to postfix expression
*************************************************************


***********************STRUCTURE DESCRIPTION*****************
struct Stack: A structure describing a stack
int top: integer variable representing the top of the stack
unsigned maxSize: unsigned int variable representing the max
					capacity of the stack
int *stackArray: integer array representing the stack as an array
Stack* stack: a stack
*************************************************************

***********************VARIABLE DESCRIPTION******************
char exp[]: character array(string) representing a postfix expression
*************************************************************

***********************FUNCTION DESCRIPTION******************
void init(): initializes a stack by allocating memory for Stack* 
			stack and setting top and maxsize
void push(), pop(): Stack push and pop function.
void evaluatePostfix(): Function to evaluate postfix expression
*************************************************************

***********************PRECEDENCE OF OPERATORS***************
Recognized operators: parenthesis, ^, *, /, +, -
The precedence decreses while going down
					()
					^
					*, /
					+, -
*************************************************************
*/


// C program to evaluate value of a postfix expression 
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
#define MAX 1000
// Stack definition
typedef struct 
{ 
	int top; 
	unsigned maxSize; 
	int* stackArray; 
} Stack; 

Stack *stack;

// ********************STACK FUNCTIONS**********************
void init( unsigned maxSize ) 
{ 
	stack = (Stack*) malloc(sizeof(Stack*)); 

	if (!stack) 
		return; 

	stack->top = -1; 
	stack->maxSize = maxSize; 

	stack->stackArray = (int*) calloc(stack->maxSize, sizeof(int)); 

} 

int pop() 
{ 
	if (stack->top != -1) 
		return stack->stackArray[stack->top--] ; 
	return -1; 
} 

void push( int op) 
{ 
	if (stack->top == stack->maxSize - 1) {  } 
	stack->stackArray[++stack->top] = op; 
} 



// The main function that returns value of a given postfix expression 
int evaluatePostfix(char* exp) 
{ 
	// Create a stack of capacity equal to expression size 
	init(strlen(exp)); 
	int i;
	char *num = (char*)calloc(2, sizeof(char));
	num[0] = '\0';

	// See if stack was created successfully 
	if (!stack) return -1; 

	// Scan all characters one by one 
	for (i = 0; exp[i]; ++i) 
	{ 
		// If the scanned character is an operand (number here), 
		// push it to the stack. 
		if (isdigit(exp[i])) {
		    num[strlen(num)] = exp[i];
		}
		else if (exp[i] == ' '){
		    if (strlen(num) >=1 ) push( atoi(num));
            num[0] = '\0';
            num[1] = '\0';
		}
		// If the scanned character is an operator, pop two 
		// elements from stack apply the operator 
		else
		{
			int val1 = pop(); 
			int val2 = pop();
			switch (exp[i]) 
			{ 
			case '+': push( val2 + val1); break; 
			case '-': push( val2 - val1); break; 
			case '*': push( val2 * val1); break; 
			case '/': push( val2/val1); break; 
			case '^': push( (int)pow(val2,val1)); break; 
			} 
		} 
	} 
	return pop(); 
} 

// Driver program to test above functions 
int main() 
{ 
	char exp[MAX];
	printf("postfix exp:");
	gets(exp);
//	strcpy(exp, :)exp = "10 20 -";
	printf ("postfix evaluation: %d", evaluatePostfix(exp)); 
	return 0; 
} 
