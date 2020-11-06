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
		printf("%d->",temp->data);
		temp=temp->next;
		
	}
	 
}

struct Node* revrse(struct Node* head)
{
	struct Node *currentNode,*nextNode,*prevNode;
	prevNode=0;
	currentNode=head;
	nextNode=head;
	while(nextNode!=0)
	{
		nextNode=nextNode->next;
	    currentNode->next=prevNode;
	    prevNode=currentNode;
	    currentNode=nextNode;
	}

  
  return prevNode;	
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
    
    head=revrse(head);
    
    print(head);
	
 
	
	    
   return 0;	 
   
}

