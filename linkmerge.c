#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node*next;	
};


void addatfirst(struct node**temp,int data)
   {
     	struct node*z=*temp;
     	
     	z=(struct node*)malloc(sizeof(struct node));
     	z->data=data;
     	z->next=*temp;
     	*temp=z;
   }
   
void  print(struct node*temp)
      {
       while(temp)
	      {
	        printf("%d ",temp->data);
			temp=temp->next;	
		  } 	
	  }
	  
	  
	struct node* merge(struct node*temp,struct node*temp2)
	               {
	               	struct node*result;
	               	
	               	  if(!temp)
	               	    return temp2;
						   
				      if(!temp2)
					    return temp;
						
					  if(temp->data>=temp2->data)
					      {
					        result=temp2;
							result->next=merge(temp,temp2->next);	
						  }	  		       
					   else
					      {
					        result=temp;
							result->next=merge(temp->next,temp2);	
						  }	  
					return result;	  
				   }
	  
	  
   
  void finddivide(struct node*temp,struct node**z,struct node**x)
         {
           struct node*fast,*slow;
		   
		   fast=slow=temp;
		   if(temp==NULL||temp->next==NULL)
		      {
		      	return;
			  }
		   
		   
		   
		   while(fast->next->next!=NULL&&fast->next->next->next!=NULL)
		         {
		         	
		           fast=fast->next->next;
				   slow=slow->next; 	
				 }	
				 
				 *x=slow->next;
				 slow->next=NULL;
				 *z=temp;
		 }   
	
	
	  

void linkmerge(struct node**temp)
      {
      	struct node*a=NULL,*b=NULL;
      	if(*temp==NULL||(*temp)->next==NULL)
      	   {
      	   	return;
		   }
		   
		 finddivide(*temp,&a,&b);  
		   
		  linkmerge(&a);
		  linkmerge(&b);
		  
		  *temp=merge(a,b);
	  }





int main() 
{
 struct node*temp=NULL;
	
addatfirst(&temp,10);
addatfirst(&temp,20);
addatfirst(&temp,30);
addatfirst(&temp,40);
addatfirst(&temp,50);
addatfirst(&temp,60);
addatfirst(&temp,70);	

print(temp);
printf("\n");

linkmerge(&temp);

print(temp);
	
return 0;
}
