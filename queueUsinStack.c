/*
*************QUEUE USING STACKS*******************
We build a queue using two stacks. While enqueue, 
we push onto stack 1 and while dequeue, we pusing onto stack 2 
and again popping out views the usage of two stacks as one queue
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int data;
	struct stack* next;
} stack;

typedef struct {
	stack* stack1;
	stack* stack2;
}queue;

queue* q;

// initialize the queue
void initQueue(){
	q=(queue*)malloc(sizeof(queue));
	q->stack1=NULL;
	q->stack2=NULL;
}

//to push any item into the stack//
void push(stack** top_ref, int new_data);

//to pop the item from the stack
int pop(stack** top_ref);

// ***************using two stacks to implement one queue****************

//to enqueue an element into the queue, using first stack push function
void enQueue(queue* q, int x){
	push(&q->stack1,x);
}

//pushing all the elements from stack 1 to stack 2
// finally popping one element from stack 2
int deQueue(queue* q){
	int x;
	
	if(q->stack1==NULL && q->stack2==NULL){
		printf("Queue underflow");
		return -1;
	}
	else if(q->stack2==NULL){
		while(q->stack1!=NULL){
			x=pop(&q->stack1);
			push(&q->stack2,x);
		}
	}
	
	x=pop(&q->stack2);
	return x;
}

//pushing in the stack
void push(stack** top_ref, int new_data){
	stack* new_node=(stack*)malloc(sizeof(stack));
	if(new_node==NULL){
		printf("\nStack Overflow!\n");
		getchar();
		exit(0);
	}
	new_node->data=new_data;
	
	new_node->next=(*top_ref);
	
	(*top_ref) = new_node;
}

//pop from the stack
int pop(stack** top_ref){
	int res;
	stack* top;
	
	if(*top_ref==NULL){
		printf("Stack Underflow\n");
		return -1;
	}
	else{
		top=*top_ref;
		res=top->data;
		*top_ref=top->next;
		free(top);
		return res;
	}
}


//------------start of main-----------------//
int main(){
	
	enQueue(q,100);
	enQueue(q,150);
	enQueue(q,200);
	
	printf("%d  ", deQueue(q));
	printf("%d  ", deQueue(q));
	printf("%d  ", deQueue(q));

	printf("1-> enqueue, 2-> dequeue, 3-> display, 4->exit\n");
	while(true){
	    printf("Enter your choice:");
        scanf("%d", &c);
        switch(c){
            case 1: 
                printf("Enter value to be enqueueed:");
                scanf("%d", &v);
                enQueue(q,v);
                break;
            case 2:
                v = deQueue(q);
                if (v == -1) printf("Queue underflow\n");
                else printf("%d\n", v);
                break;
            case 4:
                return 0;
            default: printf("Invalid choice, try again");
        }
	}
	return 0;
}





