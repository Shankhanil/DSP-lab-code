#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <stdbool.h>
#include<math.h>

#define MAX 500


typedef struct node 
{ 
	int data; 
	char symbol;
	bool isValue;
	struct node *left, *right; 
} Node ;


bool isOperand(char s)
{
	if(s == '+' || s == '-' || 
	   s == '*' || s == '/' || 
//	   s == '(' || 
	   s == '^' //||
//	   s == ')' 
	)
	   return true;
	else
		return false;
}

int precedence(char ch) 
{ 
	switch (ch) 
	{ 
	// + and - have lowest precedence (=1)
	case '+': 
	case '-': 
		return 1; 
		
	// * and / have precedence =2
	case '*': 
	case '/': 
		return 2; 
	
	// ^ have heighest precedence = 3
	case '^': 
		return 3; 
	} 
	// all other op are unrecognized 
	// and have invalid precedence (=-1)
	return -1; 
} 

bool isValidChar(char s)
{
	if (isOperand(s) || (s>='0' && s<='9')) return true;
		return false;
}

Node *newNode(int value, bool isValue){
	Node* n = (Node *) malloc( sizeof(Node) );
	
	n->isValue = isValue;
	
	if(isValue){
		n->data = value;
	}
	else{
		n->data = (char)value;
//		printf("OPERAND STORED AS  %d %c", n->data, n->data);
	}
	n->left = NULL;
	n->right = NULL;
//	return n;
}

bool isDigit(char ch) 
{ 
	return (ch >= '0' && ch<= '9') ;
}

Node *buildEvalTree(char *exp){
	
	
	Node *nodeStack[MAX], *n, *n1, *n2;
	char charStack[MAX];
	
	char *digits;
	digits = (char*) malloc(MAX*sizeof(char));
	
	int nSTop = -1, cSTop = -1;
	int i, k;
	int operand;
//	while( exp[i])
	for (i = 0; i < strlen(exp); i++) 
	{
		printf("Current character %c\n", exp[i]);
		
		 if (exp[i] == '('){
		 	cSTop++;
		 	charStack[cSTop] = '(';
		 	printf("character stack top %c\n", charStack[cSTop]);
		 }
		 else if ( isDigit(exp[i]) ){
		 	digits[0] = '\0';
		 	k = 0;
		 	do{
		 		digits[k] = exp[i];
				k++;
				i++;
			} while ( isDigit(exp[i]) );
			
			digits[k] = '\0';
			operand = atoi(digits);
			
			n = newNode(operand, true);
			nodeStack[++nSTop] = n;
//			printf("PUSHED %d into STACK. STACK TOP %d STACK SIZE %d\n", operand, n->data, nSTop+1);
			i--;
		 }
		 
		 else if ( isOperand(exp[i]) ){
//		 	printf("AN OPERAND\nNODE STACK top %d CHAR STACK TOP %c\n", nodeStack[nSTop]->data, charStack[cSTop]);
		 	while ( 
				cSTop != -1 && charStack[cSTop] != '('
//				&& ((exp[i] != '^' && precedence(charStack[cSTop]) >= precedence(exp[i])) 
//					|| (exp[i] == '^'
						&& precedence(charStack[cSTop]) >= precedence(exp[i])) //)) 
			{
//				printf("ENTERED WHILE LOOP");
				n = newNode((char)charStack[cSTop--], false);
//				charStack[cSTop--] = '\0';
				
//				printf("stack top %d", nodeStack[nSTop]->data);
				n1 = newNode(nodeStack[nSTop--]->data, true);
//				nodeStack[nSTop--] = NULL;
				
//				printf("stack top %d", nodeStack[nSTop]->data);
				n2 = newNode(nodeStack[nSTop--]->data, true);
//				nodeStack[nSTop--] = NULL;
				
				n->left = n1;
				n->right = n2;
				
//				printf("SUBTREE MADE-NOT PUSHED\n stack top %d", nodeStack[nSTop]->data);
				nodeStack[++nSTop] = n;
//				printf("SUBTREE MADE-PUSHEDstack top %d", nodeStack[nSTop]->data);
			}
		 	charStack[++cSTop] = exp[i];
		 	printf("character stack top %c\n", charStack[cSTop]);
		 }
		 
		 
		 else if ( exp[i] == ')'){
//		 	printf("\n\ncSTop %d charStack[cSTop] %c\n", cSTop, charStack[cSTop]);
		 	
		 	while (cSTop > -1 && charStack[cSTop] != '('){
		 	    
				printf("\n\ncSTop %d charStack[cSTop] %c\n", cSTop, charStack[cSTop]);	
//		 		printf("Stack top %c\n", charStack[cSTop]);
		 		
		 		n = newNode(charStack[cSTop--], false);
				charStack[cSTop--] = '\0';
				
				n1 = newNode(nodeStack[nSTop]->data, true);
				nodeStack[nSTop--] = NULL;
				
				n2 = newNode(nodeStack[nSTop]->data, true);
				nodeStack[nSTop--] = NULL;
				
				n->left = n1;
				n->right = n2;
				
				nodeStack[++nSTop] = n;
//				printf("TREE ROOT : %c, TREE LEFT SUBTREE %d TREE RIGHT SUBTREE %d\n", 
//									nodeStack[nSTop]->data, 
//									nodeStack[nSTop]->left->data, 
//									nodeStack[nSTop]->right->data);
//				free(n);
			 }
		 }
//		 i++;
	}
	
	return nodeStack[nSTop];
}

void preorder(Node* root)
{
	
	if (root ) 
	{  
	    if( root->isValue == true)
		{   
			printf("%d ",root->data); 
		}
	    else
		{
			printf(" %c ",root->data); 
		}
		preorder(root->left);	
		preorder(root->right);
    
	} 
	
}


int main(){
	Node *n, *n2;
	char *s = "(88+9+(90-5))";
	printf("Expression is %s\n", s);
	n = buildEvalTree(s);
//	n = NULL;
	preorder(n);
//	printf("\n%u %d %u", n->left, n->data, n->right);
//	getch();
	return 0;
}
