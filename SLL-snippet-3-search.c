Node* search(int data){
	// initializing current pointer as head
    current = head;
	// and searching for the node whose value == data
    while (current->next != NULL){
		// if found, return the node address
        if (current->data == data) return current;
        current = current->next;
    }
	// if not found, return NULL
    return NULL;
}