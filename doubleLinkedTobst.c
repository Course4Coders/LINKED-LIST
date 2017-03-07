#include <stdio.h>
#include <stdlib.h>


struct node
{
struct node*prev;	
int data;
struct node*next;	
};


void addatfirst(struct node**temp,int data)
   {
     	struct node*z=*temp;
     	
     	z=(struct node*)malloc(sizeof(struct node));
     	z->data=data;
     	z->next=*temp;
     	z->prev=NULL;
     	*temp=z;
   }
   
   
void preorder(struct node*temp)
      {
        if(temp==NULL)
		   return;
		   
		 printf("%d ",temp->data);
		 preorder(temp->prev);
		 preorder(temp->next);  	
	  }   
   
   
int count(struct node*temp)
{
int count=0;
while(temp)
   {
     ++count;
	 temp=temp->next;	
   }
   return count;	
}   
   
   
struct node*newnode(int data)
       {
          struct node*temp=(struct node*)malloc(sizeof(struct node));
		  temp->data=data;
		  temp->prev=NULL;
		  temp->next=NULL;
		  
		  return temp;	
	   }
	   
	         
void  print(struct node*temp)
      {
       while(temp)
	      {
	        printf("%d ",temp->data);
			temp=temp->next;	
		  } 	
	  }
   


struct node*dltobst(struct node**temp,int n)
  { 
  	if(n<=0)
  	  return NULL;
  	  
  	struct node*left=dltobst(temp,n/2);
	  
	 struct node*head=newnode((*temp)->data);
	 
	 head->prev=left;
	 
	 (*temp)=(*temp)->next;
	 
	 head->next=dltobst(temp,n-n/2-1);
	 
	 return head;   
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

struct node*temp2=dltobst(&temp,count(temp));
preorder(temp2);
return 0;
}
