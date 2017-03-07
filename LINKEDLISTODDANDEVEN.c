#include <stdio.h>
#include <malloc.h>




struct node
{
  int data;
  struct node*next;	
};





void add(struct node**temp,int data)
{
struct node*x;

x=(struct node*)malloc(sizeof(struct node));

if(!x)
  {
  	printf("MEMORY HAS NOT ALLOCATED\n");
  	return;
  }
    x->data=data;
 
 if(*temp==NULL)
    {
       x->next=NULL;
	   *temp=x;	
 	}    	
 	
 else
    {
    	struct node*temp2=*temp;
	 
    	while(temp2->next!=NULL)
    	   {
    	   	
        	   	temp2=temp2->next;
        	   
	 	   }
		        temp2->next=x;
		        temp2=temp2->next;
		        temp2->next=NULL;
	}	
}
















void display(struct node *temp)
{
  
 while(temp!=NULL)
   {
   	
 	printf("  %d",temp->data);
 
	temp=temp->next;
   }
 
}



void evenodd(struct node**temp)
{
 
 
 struct node*even=NULL,*odd=NULL,*curr=*temp,*evennode,*oddnode;
 
 	if(*temp==NULL)
 	  return;
 	  
 	  evennode=even=(struct node*)malloc(sizeof(struct node));
 	  even->next=NULL;
 	  oddnode=odd=(struct node*)malloc(sizeof(struct node));
 	  odd->next=NULL;
 	  
    while(curr!=NULL)
	        {
	  	     if(curr->data%2==0)
	  	       {
	  	        even->next=curr;
	  	        even=even->next;
	  	        curr=curr->next;
	  	       }
	  	      else
				{
				 odd->next=curr;
	  	         odd=odd->next;
	  	         curr=curr->next;	
				}  
			}	  
	even->next=oddnode->next;
	odd->next=NULL;
	
	*temp=evennode->next;
}




void main()
{
	struct node*temp=NULL;
 	
	add(&temp,100);
	add(&temp,200);
	add(&temp,300);
	add(&temp,415);
	add(&temp,500);
	add(&temp,-77);
	add(&temp,600);
	add(&temp,700);
	add(&temp,803);
	add(&temp,900);
	add(&temp,75);
	
	
    evenodd(&temp);   	
    display(temp);	
}




