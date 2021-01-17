#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

#define MAX 1000

typedef struct Node
{ 
	char data; 
	struct Node* next;
} Node; 

typedef struct linkedList{
	struct Node* head;
	struct Node* top;
}Stack;

//make a new node
Node* newNode(int data){
	Node* node1 = (struct Node*)malloc(sizeof(struct Node));
	node1->data = data;
	node1->next = NULL;
	
	return node1;
}


Stack* newStack() {
  Stack *s = malloc(sizeof(Stack));
  s->head = NULL;
  s->top = NULL;

  return s;
}


int isEmpty(Stack *s) {
  if(s->top == NULL)
    return 1;
  return 0;
} 
char peek(Stack* s)
{ 
	return s->top->data; 
} 
char pop(Stack *s) {
  if(isEmpty(s)) {
   return '\0';
  }
  else {
    int x = s->top->data;
    if(s->top == s->head) {
      free(s->top);
      s->top = NULL;
      s->head = NULL;
    }
    else {
      Node *temp = s->head;
      while(temp->next != s->top)
        temp = temp->next;
      temp->next = NULL;
      free(s->top);
      s->top = temp;
    }
    return x;
  }
} 


void push(Stack *s, char c) {
   Node *n = newNode(c);
   
  if(isEmpty(s)) { //empty
    s->head = n;
    s->top = n;
  }
  else {
    s->top->next = n;
    s->top = n;
  }
} 


_Bool isDigitOrSpace(char ch) 
{ 
	return 
		(ch >= '0' && ch<= '9') || 
		(ch == ' ') || 
		(ch>='a' && ch<='z') || 
		(ch>='A' && ch<='Z');
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
			return 2;
		case '%':
			return 3; 		
//	case '^': 
//		return 3; 
	} 
	return -1; 
} 


void infixToPostfix(char* exp) 
{ 
	int i = 0, k = -1; 
	char *postfix;
	Stack *s = newStack();
	postfix = (char*)calloc(strlen(exp), sizeof(char));
	
	int len = strlen(exp);
//	init(strlen(exp)); 
	if(!s) 
		return ; 

	for (; i<len; ++i) 
	{ 
//		printf("%c %d", exp[i], isDigitOrSpace(exp[i]));

		if ( isDigitOrSpace(exp[i]) ){ 
			postfix[++k] = exp[i];
			if (!isDigitOrSpace(exp[i+1]) )
			    postfix[++k] = ' ';
		}
		
		else if (exp[i] == '(')  push(s, exp[i]); 
		
		else if (exp[i] == ')') 
		{ 
			while (!isEmpty(s) && peek(s) != '(')  postfix[++k] = pop(s); 
			
			if (!isEmpty(s) && peek(s) != '(')  return; 
			else pop(s); 
			
		} 
		else 
		{ 
			while ( !isEmpty(s) && precedence(exp[i]) <= precedence(peek(s)) ) 
				postfix[++k] = pop(s);
			push(s, exp[i]); 
		} 

	} 

	while (!isEmpty(s)) 
		postfix[++k] = pop(s); 
	
	postfix[++k] = '\0';
	printf("%s", postfix);
} 
int main() 
{ 
//	char exp[] = "10+12*(3^8-4)^(0+1*10)-3";
	char exp[MAX], expected[MAX] ;
 	gets(exp);
	infixToPostfix(exp); 
	printf("\n%s", expected);
	return 0; 
} 
