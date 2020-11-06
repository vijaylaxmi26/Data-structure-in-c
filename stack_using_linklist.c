#include<stdio.h>
#include <stdlib.h> 
struct Node
{
  int data; 
  struct Node *next;
};

struct Node* head=0;

void print()
{
 
	while(head!=0)
	{
		printf("%d->",head->data);
		head=head->next;	
	}
	 
}

void push(int value)
{
	    struct Node* new_node;
		new_node= (struct Node*) malloc(sizeof(struct Node));
		new_node->data=value;
	    if(head==0)
	    {
	    	new_node->next=0;
		}
	    else{
	    	new_node->next=head;
		}

	    head=new_node;
	    
	return;
}

int pop()
{
	     int value;
		 if(head==0)
		 {
		 	printf("stack underflow!!");
		 	return 0;
		}  
		else
		{
			value=head->data;
			head=head->next;
			return value;
		}
  
}

int peek()
{
		 if(head==0)
		 {
		 	printf("stack underflow!!");
		 	return 0;
		 }  
		 else{
		 	return head->data;
		 }	
}
 
 

int main()
{
 
	int count=0,q=1;
	 
	while(q)
	{
    printf("Enter the optration...\n");
    printf("1.push\n2.pop\n3.peek\n\n");
	int n,ch,value;
	scanf("%d",&n);
	switch(n)
	{
		case 1:
		     printf("Enter the value\n");
			 scanf("%d",&value);
			 push(value);
			 count++;
			 printf("Count of linklist = %d\n",count);
			 break;
			 
		case 2:
		     printf("First value of stack= %d\n",pop());
			 count--;
			 printf("Count of linklist = %d\n",count);
			 break;
		
		case 3:
			 printf("First value of stack= %d\n",peek());
			 printf("Count of linklist = %d\n",count);
			 break;
	   
	    default:
	    	printf("Invalid opration!!\n");
			 
	}
	
		printf("\n\nDo you want to continue(1) and exit(0)\n");
	    scanf("%d",&q);
    }
    
    printf("\n--------------------------\n");
    print();
    
    
    
	
	    
   return 0;	 
   
}
 
