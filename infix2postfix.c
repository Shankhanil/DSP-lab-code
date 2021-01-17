#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

#define MAX 1000

typedef struct 
{ 
	int top; 
	unsigned maxSize; 
	int* stackArray; 
} Stack; 

Stack *stack;

void init( unsigned maxSize ) 
{ 
	stack = (Stack*) malloc(sizeof(Stack*)); 

	if (!stack) 
		return; 

	stack->top = -1; 
	stack->maxSize = maxSize; 

	stack->stackArray = (int*) calloc(stack->maxSize, sizeof(int)); 

} 

char pop() 
{ 
	if (stack->top != -1) 
		return stack->stackArray[stack->top--] ; 
	return '$'; 
} 

void push( char op) 
{ 
	if (stack->top == stack->maxSize - 1) {  } 
	stack->stackArray[++stack->top] = op; 
} 


_Bool isDigitOrSpace(char ch) 
{ 
	return (ch >= '0' && ch<= '9') || (ch == ' ') || (ch>='a' && ch<='z');
} 

int precedence(char ch) 
{ 
	switch (ch) 
	{ 
		case '+': 
		case '-': 
			return 1; 
			
		case '*': 
		case '/': 
		case '%':
			return 2; 
		
//	case '^': 
//		return 3; 
	} 
	return -1; 
} 


void infixToPostfix(char* infixExp) 
{ 
	int i, k; 
	char *postfixExp;
	postfixExp = (char*)calloc(strlen(infixExp), sizeof(char));

	init(strlen(infixExp)); 
	if(!stack) 
		return ; 

	for (i = 0, k = -1; infixExp[i]; ++i) 
	{ 

		if (isDigitOrSpace(infixExp[i])){ 
			postfixExp[++k] = infixExp[i];
			if (!isDigitOrSpace(infixExp[i+1]) )
			    postfixExp[++k] = ' ';
		}
		else if (infixExp[i] == '(') 
			push(infixExp[i]); 
		else if (infixExp[i] == ')') 
		{ 
			while (stack->top != -1 && stack->stackArray[stack->top] != '(') 
				postfixExp[++k] = pop(stack); 
			if (stack->top != -1 && stack->stackArray[stack->top] != '(') 
				return; 
			else
				pop(); 
		} 
		else 
		{ 
			while (stack->top != -1 && 
				precedence(infixExp[i]) <= precedence(stack->stackArray[stack->top])) 
				postfixExp[++k] = pop(stack);
			push(infixExp[i]); 
		} 

	} 

	while (stack->top != -1) 
		postfixExp[++k] = pop(stack ); 
	postfixExp[++k] = '\0';
	
	printf("%s", postfixExp);
} 
int main() 
{ 
//	char infixExp[] = "10+12*(3^8-4)^(0+1*10)-3";
	char exp[MAX] ;
	scanf("%[^\n]c", exp); 
//	printf("%d", precedence('%'));
	infixToPostfix(exp); 
	return 0; 
} 
