#include<stdio.h>
#include <stdlib.h> 
struct Node
{
  int data; 
  struct Node *next;
};
 
struct Node *front=0,*rear=0;
int count=0;

void enqueue(int value)
{
	struct Node *new_node;
	new_node = (struct Node*)malloc(sizeof(struct Node));
	if(new_node==0)
	{
		printf("Overflow!!");
		return;
	}
	
	new_node->data=value;
	new_node->next=0;
	if(front==0)
	{
		front=new_node;
	}
	if(rear!=0)
	{
		rear->next=new_node;
	}
    rear= new_node; 
    
	count++;

  return;
}

void dequeue()	
{
	if(front==0)
	   printf("Underflow condition!!");
	   
	else if(front==rear)
	   front=rear=0;
	   
	else
	   front=front->next;
	
	count--;
	 
	return;
}

int peek()
{
    return front->data;
}

int isempty()
{
	if(front==0)
	   return 1;
	   
return 0;
}

int isfull()
{
	struct Node* new_node;
	new_node = (struct Node*)malloc(sizeof(struct Node));
	if(new_node==0)
	{
		return 1;
	}
	
	return 0;
}

void print()
{
	while(!isempty()){
		printf("%d->",peek());
		dequeue();
	}
}

int main()
{
	int q=1;
	
	while(q){
		
          printf("Enter the opration.\n");
          printf("1.Equeue\n2.dequeue\n3.peek\n4.isfull\n5.isempty\n");
          int ch,value;
          scanf("%d",&ch);
          switch(ch){
          	    case 1:
          	    	printf("Enter the value:");
          	    	scanf("%d",&value);
          	    	enqueue(value);
          	    	printf("count in queue = %d",count);
          	    	break;
          	    
          	    case 2:
          	    	dequeue();
          	    	printf("count in queue = %d",count);
          	    	break;
          	    
          	    case 3:
          	    	printf("front value = %d",peek());
          	    	break;
          	    
          	    case 4:
          	    	if(isfull())
          	    	    printf("queue is full!!\n");
          	    	else
          	            printf("queue is not full!!\n");
          	        break;
          	    
          	    case 5:
          	    	if(isempty())
          	    	    printf("queue is empty!!\n");
          	    	else
          	            printf("queue is not empty!!\n");
          	        break;
				
				default:
					printf("Invalid opration!!\n");
          	    	
		  }
		  
		  printf("\n\nDid u want o continue(1) and exit(0).\n");
		  scanf("%d",&q);
   } 
   
	 printf("Queue is:");
	 print();
	
	    
   return 0;	 
   
}

