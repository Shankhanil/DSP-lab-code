void createCLL ()
{
	// create the execution ground
    Node *temp, *rear;
    int N, ch;
	// ask for total number of prisoners
    printf("Enter number of prisoners: ");
    scanf("%d", &N);
	
    while(N >= 1)
    {
		// allocate memory blocks for N prisoners
        temp = (Node *)malloc(sizeof(Node));
        temp->data = N;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
        N--;
    }
    rear->next = head;
}