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

void inorder(Node *node){
	if (node->left) inorder(node->left);
	if (node) printf("%d ", node->data);
	if (node->right) inorder(node->right);
}

void preorder(Node *node){
	if(node) printf("%d ", node->data);
	if (node->left) preorder(node->left);
	if (node->right) preorder(node->right);
}
void postorder(Node *node){
	if (node->left) postorder(node->left);
	if (node->right) postorder(node->right);
	if(node) printf("%d ", node->data);
}

int main()
{
	int array[MAX], N;
	int i;
	
	scanf("%d", &N);
	if (N >= 1){
		scanf("%d", (array));	
		root = insert(root, *(array));
	}
	for(i = 0; i<N-1; i++){
		scanf("%d", (array+i));
		insert(root, *(array+i));
	}
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
    return 0;
}
