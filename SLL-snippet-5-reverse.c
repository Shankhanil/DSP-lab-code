void reverse()
{
	// initialize the nodeBefore and nodeAfter node with null
    Node* nodeBefore = NULL;
    Node* current = head;
    Node* nodeAfter = NULL;
	
    while (current != NULL) {
        // Store nodeAfter
        nodeAfter = current->next;
 
        // Reverse current node's pointer
        current->next = nodeBefore;
 
        // Move pointers one position ahead.
        nodeBefore = current;
        current = nodeAfter;
    }
    head = nodeBefore;
}
