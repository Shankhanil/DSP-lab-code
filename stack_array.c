#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
***************** VARIABLE DOCUMENTATION******************
struct Stack: a C structure describing a stack
int *stack: the stack implemented as an int pointer(array)
int top: variable indicating the top element of the stack
int maxSize: variable indicating the capacity of the stack
Stack s: instance of the Stack structure
**********************************************************

***************** FUNCTIOn DOCUMENTATION******************
void init(int n): Initializes an empty stack of maximum capacity n
_Bool push(int value): pushes a data(=value) into the stack. 
						If push is successful, returns true, else
						returns false.
int pop(): pops the topmost element from the stack. If the stack is 
			empty, returns -1.
void traverseStack(): prints all the elements in the stack.
**********************************************************
*/

typedef struct Stack{
    int *stack;
    int top, maxSize;
} Stack;

Stack s;

void init(int n){
    s.stack = calloc(n, sizeof(int));
    s.top = -1;
    s.maxSize = n;
}

_Bool push(int value){
    if (s.top == s.maxSize-1){
        return false;
    }
    s.stack[++s.top] = value;
    return true;
}

int pop(){
    if (s.top == -1) return -1;
    return s.stack[s.top--];
}

void traverseStack(){
    if (s.top == -1) printf("Empty Stack");
    else{
        int i = 0;
        do{
           printf("%d ", s.stack[i]); 
           i++;
        } while(i<=s.top);
    }
    printf("\n");
}

int main(void) {
    
    int N, i=0, c, v;
    printf("Enter the max size of the stack:");
    scanf("%d", &N);
    
	init(N);
	printf("1-> push, 2-> pop, 3-> display, 4->exit\n");
	while(true){
	    printf("Enter your choice:");
        scanf("%d", &c);
        switch(c){
            case 1: 
                printf("Enter value to be pushed:");
                scanf("%d", &v);
                push(v);
                break;
            case 2:
                v = pop();
                if (v == -1) printf("Stack underflow\n");
                else printf("%d", v);
                break;
            case 3:
                traverseStack();
                break;
            case 4:
                return 0;
            default: printf("Invalid choice, try again");
        }
	}
	return 0;
}

