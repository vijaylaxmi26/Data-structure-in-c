#include<stdio.h>
#include <stdlib.h> 
struct Node
{
  int data; 
  struct Node *next;
};

void print(struct Node* head)
{
	struct Node* temp;
	temp=head;
	while(temp!=0)
	{
		printf("%d ",temp->data);
		temp=temp->next;
		
	}
	 
}
 
struct Node* middle(struct Node* start,struct Node* last) 
{ 
    if (start == NULL) 
        return NULL; 
  
    struct Node* s = start; 
    struct Node* f = start -> next; 
  
    while (f != last) 
    { 
        f = f-> next; 
        if (f!= last) 
        { 
            s = s-> next; 
            f = f-> next; 
        } 
    } 
  
    return s; 
} 

int binarySearch(struct Node *head, int value) 
{ 
    struct Node* start = head; 
    struct Node* last = NULL; 
  
    do
    { 
        struct Node* mid = middle(start, last); 

        if (mid == NULL) 
            return NULL; 
  
        if (mid->data == value) 
            return 1; 
  
        else if (mid->data<value) 
            start = mid->next; 
   
        else
            last = mid; 
  
    } while (last == NULL || 
             last != start); 
  
    return -1; 
} 


int main()
{
	struct Node *head,*new_node,*temp;
	int choice=1,count=0;
	head=0;
	while(choice)
	{
		new_node= (struct Node*) malloc(sizeof(struct Node));
	    printf("Enter the number data\n");
	    scanf("%d",&new_node->data);
	    new_node->next=0;
	  
	    if(head==0)
	    {
	    	head=temp=new_node;
	    }
	    else
	    {
		 temp->next= new_node;
		 temp=new_node;
	    }
	    
	    printf("Do you want to continue(1) and exit(0)\n");
	    scanf("%d",&choice);
	    count++;
	}
	
	printf("Element of link-list\n");
	printf("\n------------\n");
	print(head);
	printf("\ncount of number:%d\n",count);
	
	int item;
	printf("\nEnter the data u want:");
	scanf("%d",&item);
    int n = binarySearch(head,item);
	
	if(n==-1)
	{
		printf("\nElement is not found.");
	}
	else
	{
		printf("Element is found");
	}
   return 0;	 
   
}

