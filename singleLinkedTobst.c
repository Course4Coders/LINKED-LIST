#include <stdio.h>
#include <stdlib.h>




struct node
{
int data;
struct node*next;	
};





struct bst
{
struct bst*lf;	
int data;	
struct bst*rt;
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
   
   
   
struct bst*newnode(int data)
   {
   	struct bst*temp=(struct bst*)malloc(sizeof(struct bst));
   	temp->data=data;
   	temp->lf=NULL;
   	temp->rt=NULL;
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



void preorder(struct bst*temp)
      {
      	if(temp==NULL)
      	    return;
      	
		printf("%d ",temp->data);
		preorder(temp->lf);
		preorder(temp->rt);      
	  }


struct bst*linkedtobst(struct node**temp,int n)
             {
             	if(n<=0)
             	   return NULL;
             	   
             	struct bst*left=linkedtobst(temp,n/2);
				
				struct bst*head=newnode((*temp)->data);
				*temp=(*temp)->next;
				
				head->lf=left;
				
				head->rt=linkedtobst(temp,n-n/2-1);
				
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

struct bst*temp2=linkedtobst(&temp,count(temp));
preorder(temp2);

return 0;
}
