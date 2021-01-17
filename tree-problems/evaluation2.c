#include<stdio.h>
#include<string.h>
#include <stdlib.h>


int precedence(char op)
{
	if(op== '+' || op == '-')
	return 1;
	if(op == '*' || op == '/')
	return 2;
	if(op == '^')
	return 3;
	return 0;
}


int calculate(int a, int b, char op)
{
	switch(op)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
		case '^': return a^b;
	}
}
int isDigit(int data) 
{ 
	return (data >= '0' && data<= '9');
}

int isOperand(char s)
{
	return (s == '+' || s == '-' || 
	   s == '*' || s == '/' || 
	   s == '(' || 
	   s == '^' ||
	   s == ')' );
}

int vStack[50], vTop=-1;
char opStack[50], opTop =-1;


int evaluateExp(char exp[])
{
	int i;
	int len = strlen(exp);
	for(i = 0; i< len; i++)
	{
		if(exp[i] == ' ')
			continue;
			
		else if(exp[i] =='('){
			opTop= opTop+1;
			opStack[opTop] = exp[i];
		}
		else if(isDigit(exp[i]))//current token is a number push it to stack.
		{
			int value = 0;
			while(i< len && isDigit(exp[i]))
			{
				value = (value*10) + (exp[i]-'0');
				i = i + 1;
			}
			vTop = vTop+1;
			vStack[vTop] = value;
			i = i-1;
		}
		//when closing brace is there solve the entire brace
		else if(exp[i] == ')')
		{
			while(opTop != -1 && opStack[opTop] != '(' )
			{
				int value2 = vStack[vTop];
				vTop = vTop-1;
				
				int value1 = vStack[vTop];
				vTop = vTop-1;
				
				char operand = opStack[opTop];
				opTop = opTop-1;
				
				vTop = vTop + 1;
				vStack[vTop] = calculate(value1, value2, operand);
			}
			if(opTop != -1)
				opTop = opTop-1;
		}
		else
		{
			while(opTop != -1 && precedence(opTop) >= precedence(exp[i]))
			{
				int value2 = vStack[vTop];
				vTop = vTop-1;
				
				int value1 = vStack[vTop];
				vTop = vTop-1;
				
				char operand = opStack[opTop];
				opTop = opTop-1;
				
				vTop = vTop+1;
				vStack[vTop] = calculate(value1, value2, operand);
			}
			opTop = opTop+1;
			opStack[opTop] = exp[i];
		}
	}
	while(opTop != -1)
	{
		int value2 = vStack[vTop];
		vTop = vTop-1;
				
		int value1 = vStack[vTop];
		vTop = vTop-1;
				
		char operand = opStack[opTop];
		opTop = opTop-1;
		
		vTop = vTop+1; 		
		vStack[vTop] = calculate(value1, value2, operand);
				
	}
	//Top value of the valstack is the result
	return vStack[vTop];		
}

_Bool isValidChar(char c){
	return isDigit(c) || isOperand(c);
}

int main()
{
	int i;
	
	char exp[100], exp2[100];
	gets(exp);
	int n = strlen(exp);
	
	while(i<n)
	{
   		if(isValidChar(exp[i]))
		{
   			exp2[i+1]=exp[i]; 
		}
		else
		{
	    	printf("Invalid");	
			return 0;		
		} 
		i++; 	
	}
     	
   	exp2[i+1]=')'; 
   	
	
	printf("%d", evaluateExp(exp));
	
	return 0;
}
