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







struct node* rev(struct node*temp)
{
	
	struct node*r=NULL,*curr=temp,*x;;
	
	
	while(curr!=NULL)
	{
		
	x=curr->next;
	curr->next=r;
	r=curr;
	curr=x;
    }
    temp=r;
    
return temp;    
}






int pal(struct node*temp1,struct node*temp2,struct node*mid)
{
	
	int i=0;
 if(temp1==NULL&&temp2==NULL)
    {
    	printf("unsufficient\n");
    	return;
	}	
	
  while(temp1!=mid->next&&temp2!=NULL)
      {
      	printf("\n1=>%d 2=>%d\n",temp1->data,temp2->data);
       if(temp1->data!=temp2->data)
	      	{
	      		printf("\nLINKED LIST IS NON_PALLINDROME\n");
	      		return;
			}
		temp1=temp1->next;
		temp2=temp2->next;	
      }	
      
	return 1;
	
}




struct node*mid(struct node*temp)
    {
     struct node*fast=temp,*slow=temp;
	 int i=0;	
    	
    	while(fast->next!=NULL)
    	    {
    	    	if(i==0)
    	    	 {
    	    	 	i=1;
    	    	 	fast=fast->next;
				 }
				else if(i==1)
				 {
				 	i=0;
				 	slow=slow->next;
				 	fast=fast->next;
				 }
    	    	
			}
    	
    	return slow;
    }









void main()
{
	struct node*temp=NULL,*temp2=NULL,*part=NULL;
 	int n;
 	
	add(&temp,100);
	add(&temp,200);
	add(&temp,300);
	add(&temp,415);
	add(&temp,500);
	add(&temp,-77);
	add(&temp,500);
	add(&temp,415);
	add(&temp,300);
	add(&temp,200);
	add(&temp,100);
	

	
	part=mid(temp);
   
    temp2=rev(part);
    
   n=pal(temp,temp2,part);
    
   
   
	 	
   if(n==1)
   printf("\nTHIS IS PALLINDROME"); 	
}





