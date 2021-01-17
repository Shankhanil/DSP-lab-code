_Bool Delete(int data){
	// search for a node with the value
    current = search(data);
	
	// if node not found, then return false
    if (current == NULL) return false;
	
	// if node is the head, update the head 
    if (current == head) {
        head = head->next;
        return true;
    }
	
	// else, delete it old fashioned way
    Node *nodeBefore = head, *nodeAfter = current->next;
    while (nodeBefore->next != current && nodeBefore->next != NULL){
        nodeBefore = nodeBefore->next;
    }
    nodeBefore->next = nodeAfter;
    return true;
}
