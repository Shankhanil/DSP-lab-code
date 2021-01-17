#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node *root;

Node* newNode(int data)
{
	Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}
int maxDepth( Node* node)
{
	if( node == NULL)
		return 0;
	else
	{
		int leftDepth = maxDepth(node->left);
		int rightDepth = maxDepth(node->right);
		
		if(leftDepth > rightDepth)
			return(leftDepth+1);
		else return (rightDepth+1);
	}
}

Node* insert(Node* node, int data) 
{ 
    if (node == NULL) 
        return newNode(data); 
  
    if (data < node->data) 
        node->left = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data); 
  
    return node; 
}

int main()
{
	int array[MAX], N;
	int i;
	
	scanf("%d", &N);
	scanf("%d", (array));
	if (N <= 1){
		printf("%d", N);
		return;
	}
	root = insert(root, *(array));
	for(i = 0; i<N-1; i++){
		scanf("%d", (array+i));
		insert(root, *(array+i));
	}
	printf("%d", maxDepth(root));
    return 0;
}
