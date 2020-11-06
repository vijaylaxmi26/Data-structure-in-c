#include<stdio.h>
#include <stdlib.h> 
struct Node
{
  int data; 
  struct Node *next;
  struct Node *prev;
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

void print_rev(struct Node* head){
	struct Node *temp;
	temp=head;
	while(temp!=0)
	{
		printf("%d->",temp->data);
		temp=temp->prev;
	}
}



struct Node* insert_first(struct Node* head)
{
	    struct Node* new_node;
		new_node= (struct Node*) malloc(sizeof(struct Node));
		
	    printf("Enter the number data\n");
	    scanf("%d",&new_node->data);
	    new_node->next=head;
	    head->prev=new_node;
	    head=new_node;
	    
	return head;
}

struct Node* insert_end(struct Node* head)
{
	    struct Node *new_node,*temp;
	    
		new_node= (struct Node*) malloc(sizeof(struct Node));
		
	    printf("Enter the number data\n");
	    scanf("%d",&new_node->data);
	    new_node->next=0;
	    
	    temp=head;
	    while(temp->next!=0)
	    {
	    	temp=temp->next;
		}
		new_node->prev=temp;
		temp->next=new_node;
		
	return 	new_node;
}

void insert_Position(struct Node* head,int count)
{
	
	    int position,i=1;
	    struct Node* pre;
	    printf("Enter the position:\n");
	    scanf("%d",&position);
	    
	    struct Node *new_node,*temp;
	    
		new_node= (struct Node*) malloc(sizeof(struct Node));
		
	    printf("Enter the number data\n");
	    scanf("%d",&new_node->data);
	    
	    temp=head;
	    if(position>count){
	    	
	    	printf("Entered position is invalid:\n");
		}
		else{
	         while(i<position-1){
	         	temp=temp->next;
	    	    i++;
	      	}
	    }
	      new_node->prev=temp;
	      new_node->next=temp->next;
	      pre=temp->next;
	      temp->next=new_node;
	      pre->prev=new_node;
		 
}

struct Node* del_first(struct Node* head)
{
	    head=head->next;
	    head->prev=0;
			    
	return head;
}

struct Node* del_end(struct Node* head,int count)
{
	struct Node* temp;
	int i=1;
	
	temp = head;
	while(i<count-1)
	{
		temp=temp->next;
		i++;
	}
	
	temp->next=0;

  return temp;
}

void del_position(struct Node* head,int count)
{
	struct Node* temp;
	int i=1,position;
	
	printf("Enter the position:\n");
	scanf("%d",&position);
	
	temp=head;
	if(position>count)
	{
		printf("Position is invalid.\n");
	}
	else
	{
		while(i<position-1)
		{
		    temp=temp->next;	
			i++;
		}
		
		struct Node *next_node,*pre;
		next_node=temp->next;
		
		temp->next=next_node->next;
		pre=next_node->next;
		pre->prev=temp;
	}
	
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
	    new_node->prev=0;
	  
	    if(head==0)
	    {
	    	head=temp=new_node;
	     
	    }
	    else
	    {
		 temp->next= new_node;
		 new_node->prev=temp;
		 temp=new_node;
		 
	    }
	    
	    printf("Do you want to continue(1) and exit(0)\n");
	    scanf("%d",&choice);
	    count++;
	}
	
	struct Node* end;
	end=temp;
	
	printf("Element of link-list\n");
	printf("\n------------\n");
	print(head);
	printf("\nReverse link list\n");
	print_rev(end);
	printf("\ncount of number:%d\n",count);
	int q=1;
	
	
	while(q)
	{
	printf("\n------------\n");
	printf("\nEnter the opreation:\n");
	printf("1.Insertion\n2.Deletion\n\n");
	
	int n,ch;
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("Where you want to Insert.\n\n");
			printf("1.Insert in begining.\n2.Insert in end\n3.Insert at specific position.\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					head = insert_first(head);
					count++;
					break;
					
				case 2:
					end = insert_end(head);
					count++;
					break;
					
				case 3:
					insert_Position(head,count);
					count++;
					break;
					
				default:
					printf("Invalid opration");
					
			}
			
			break;
			
		case 2:
			printf("Where you want to delete.\n\n");
			printf("1.Delete in begining.\n2.Delete in end\n3.Delete at specific position.\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					head = del_first(head);
					count--;
					break;
					
				case 2:
					end=del_end(head,count);
					count--;
					break;
					
				case 3:
					del_position(head,count);
					count--;
					break;
					
				default:
					printf("Invalid opration");
					
			}
	         	break;
		
		default:
			printf("Invalid opration.");
	}
	
	    printf("\n------------\n");
      	printf("Element of link-list\n");
	    printf("\n------------\n");
	    print(head);	    
	    printf("\ncount of number:%d\n",count);
	
		printf("\n\nDo you want to continue(1) and exit(0)\n");
	    scanf("%d",&q);
    }
    
    
    
	
	    
   return 0;	 
   
}

