#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct node
{
    void *data;
    struct node *next;
    struct node *prev;
} node;


node *head1 = NULL;
node *tail1 = NULL;
node *head2 = NULL;
node *tail2 = NULL;


int maxDataSize = -1;
int N;


void *allocateData(int number)
{
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = number;
    return ((void *)ptr);
}


void isInvalid()
{
    printf("INVALID INPUT");
    return;
}


void swapDLL()
{
    node *t;
	
    t = head1;
    head1 = head2;
    head2 = t;
	
    t = tail1;
    tail1 = tail2;
    tail2 = t;
}


void insert(int data)
{
    node *newN1 = (node *)malloc(sizeof(node));
    newN1->data = allocateData(data);
    newN1->next = NULL;
    newN1->prev = NULL;
	
    node *newN2 = (node *)malloc(sizeof(node));
    newN2->data = NULL;
    newN2->next = NULL;
    newN2->prev = NULL;

    
    if (NULL == newN1)
    {
        printf("\nMemory overflow!");
        exit(0);
    }
	
    if (NULL == head1)
    {
        head1 = newN1;
        tail1 = newN1;
		
        head2 = newN2;
        tail2 = newN2;
    }
    else
    {
        tail1->next = newN1;
        newN1->prev = tail1;
        tail1 = tail1->next;

        tail2->next = newN2;
        newN2->prev = tail2;
        tail2 = tail2->next;
    }
}


void insertAtIndex(node *head, void *data, int index)
{
	int i;

    if (index > N)
        isInvalid();

    for (i = 0; i < index; i++)
        head = head->next;
    head->data = data;
}


void traverse()
{
    if (NULL == head1)
        return;

    node *t = head1;
    while (t)
    {
        printf("%d ", *(int *)t->data);
        t = t->next;
    }
}


void freqCount(int *count, int exp)
{
    node *t = head1;
    while (t)
    {
        count[((*(int *)t->data) / exp) % 10]++;
        t = t->next;
    }
}


void buildSortedList(int *count, int exp)
{
    int index = N - 1;
    node *t = tail1;

    while (t)
    {
        int updatedIndex = ((*(int *)t->data) / exp) % 10;
        count[updatedIndex]--;
        insertAtIndex(head2, t->data, count[updatedIndex]);

        t = t->prev;
        index--;
    }
}


void countSort(int exp)
{
	int i;
    int *count = (int *)calloc(MAX, sizeof(int));
    freqCount(count, exp);
	
    for (i = 1; i < MAX; i++)
        count[i] = count[i] + count[i - 1];

    buildSortedList(count, exp);
    swapDLL();
}

void radixSort()
{
	int exp;
    for (exp = 1; (maxDataSize / exp) > 0; exp = (exp * MAX))
        countSort(exp);
}

void input(){
	int input, i;
    scanf("%d", &N);

    if (N > 0)
    {
        for (i = 0; i < N; i++)
        {
            scanf("%d", &input);
            if (input >= 0)
            {
                insert(input);

                if (maxDataSize < input)
                    maxDataSize = input;
            }
            else
                isInvalid();
        }
    }
    else
        isInvalid();
}

int main()
{
    
	input();
    radixSort();
    traverse();

    printf("\n");
    return 0;
}
