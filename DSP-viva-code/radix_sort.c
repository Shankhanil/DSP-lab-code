#include<stdio.h>
#include<stdlib.h>

int d;
int count=0;
int a[100];
int round1[100];
int c1;
// dll node
struct node
{
	int n;
	struct node *prev, *next;
	
};
// head pointer
struct node *head=NULL;

// insert fn
void insert(int p,int d)
{
	
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->n=p;
	
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp=head;	
	if(NULL == head)
	{
		new->prev=NULL;
		new->next=NULL;
		head=new;	
	}
	else
	{
		// inserting in appropriate position in LL
		int c=((temp->n)%10);
			if(c>d)
			{
				temp->next=temp->next;
				new->prev=temp->prev;
				new->next=temp;
				temp->prev=new;
				
				
				head=new;
				return;
				
			}
			else{
				while(c<=d && temp->next!=NULL)
				{
					temp=temp->next;
					
						c=((temp->n)%10);
					
					
				}
				if(c>d){
					new->prev=temp->prev;
					new->next=temp;
					temp->prev->next=new;
					temp->prev=new;
				}
				else{
					new->prev=temp;
					new->next=temp->next;
					temp->next=new;
				}			
			}
	
	}
}

void sort()
{
	while(count<=5)
	{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp=head;
	int n1,n2,key;
	
	
	struct node* p1=temp->next;//i
	
	struct node*p2=NULL;
	while(p1!=NULL)
	{
		p2=p1->prev;//j
		key=p1->n;
		int v=((p1->n)/10);
		int d=((p2->n)/10);//for else loop
		if(count==2)
		{
				 
				 n1=(v%10);
				
				n2=(d%10);
				
		}
		else
		{
		while(c1>2)
		{
			
			
			
				n1=(v/10);
			
				n2=(d/10);
				c1--;
			
			v=n1;
			d=n2;
		}
		}
		
		int key1=n1;
		
		
		while(p2!=NULL && n2>key1)
		{	c1=count;
			
			p2->next->n=p2->n;
			
			p2=p2->prev;
			
			//c1=count;
			if(p2!=NULL)
			{
				
			if(count==2)
			{
				
				int d=((p2->n)/10);
				n2=(d%10);
				
				
			}
			
			else
			{
				if(p2!=NULL)
				{
					int d=((p2->n)/10);
					while(c1>2){
			
					
						n2=(d/10);
						d=n2;
						c1--;
					}
					
				}
			}
			}
			
		}
		c1=count;
		if(p2==NULL)
			head->n=key;
			
		else
			p2->next->n=key;	
		
		
		p1=p1->next;
	}
	
	temp=head;
	//i=1;
	while(temp!=NULL)
	{
		
		temp=temp->next;
	}
	count++;
	c1=count;
	}
}		

int main(void)
{
	int n,i,k,j,flag=1;
	int c=0;
	int f=0;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n<=0)
	{
		printf("INVALID INPUT\n");
		return 0;
	}
	
	for(i=1;i<=n-1;i++)
	{
		
			if(a[i]<a[i+1])
				c++;
			if(a[i]<0||a[i+1]<0)
				flag=0;
		
	}
	for(i=1;i<=n-1;i++)
	{
		
			if(a[i]>a[i+1])
				f++;
			
		
	}
	if(flag==0)
	{
		printf("Invalid Input\n");
		return 0;
	}
	else if(c==n-1||f==n-1)
	{
		if(c==n-1){
		for(i=1;i<=n;i++)
		{
			printf("%d ",a[i]);
		}
		}
		else
		{
			for(i=n;i>=1;i--)
		{
			printf("%d ",a[i]);
		}
		}
		return 0;
	}
	else
	{
	count=1;
	
	for(i=1;i<=n;i++)
	{
		insert(a[i],(a[i]%10));
	}
	
	struct node* temp1=(struct node*)malloc(sizeof(struct node));
	temp1=head;
	
	temp1=NULL;
	count++;
	c1=count;
	sort();
	temp1=head;
	while(temp1!=NULL)
	{
				
		//round1[i]=temp1->n;
		printf("%d ",temp1->n);
		temp1=temp1->next;
		//i++;
		
	}
	
	}
	return 0;
	
	
}
