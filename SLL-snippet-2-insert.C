void insert(int data) {
	// initializing new node
	Node *newNode = (Node*) malloc(sizeof(Node));
	
	newNode->data = data;
	newNode->next = head;
	
	// and set head as the new node. 
	head = newNode;
}