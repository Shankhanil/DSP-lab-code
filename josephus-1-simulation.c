int josephus(int k)
{
    Node *p, *q;
    int i;
 
    q = p = head;
    while (p->next != p)
    {
		// skipping k prisoners
        for (i = 0; i < k - 1; i++)
        {
            q = p;
            p = p->next;
        }
		// killing prisoner at node p
        q->next = p->next;
        printf("%d has been killed.\n", p->data);
        free(p);
        p = q->next;
    }
	// setting the head at p
    head = p;
	
    return (p->data);
}
