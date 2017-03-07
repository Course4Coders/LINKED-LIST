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











int hasknodes(struct node*temp,int k)
{

struct node*curr=temp;
int i=0;
if(temp==NULL)
return 0;

while(curr!=NULL&&i<k)
    {
     curr=curr->next;	
     i++;
    }
    
    
    
   if(i==k)
    return 1;
    else
    return 0;
}



struct node*getkplusonepos(struct node*temp,int k)
{

struct node*curr=temp;
int i=0;
if(temp==NULL)
return temp;

while(curr!=NULL&&i<k)
   {
   	
   	i++;
   	curr=curr->next;
   }


	if(i==k)
	return curr;
	else
	return temp->next;

}
	
	





struct node* reversetoknodes(struct node*temp,int k)
 {
   
   struct node*curr=temp,*temp2,*newnode,*x;
   int i;
     
	  if(k==0&&k==1)
	   return temp;//because there will not any effect on linkedlist
 
      if(temp==NULL)
       return temp;
       
      if(hasknodes(temp,k))
	   newnode=getkplusonepos(temp,k-1);
	  else
	    newnode=temp;
	   
	   while(curr&&hasknodes(curr,k))
	     {
	     	i=0;	
	       temp2=getkplusonepos(curr,2*k-1);
		 while(i<k)
		       {
		       	x=curr->next;
		       	curr->next=temp2;
		       	temp2=curr;
		       	curr=x;
		       	i++;
			   } 	
	    
		 }
		printf(" the %d\n",curr->data);  	 	 
	   	 	 
   return newnode;
 }




void display(struct node *temp)
{
  int i=1;
 while(temp!=NULL)
   {
   	 if(i==13)
   	  {
   	  	return;
		 }
     i++;
 	//printf("  %d",temp);
 
	temp=temp->next;
   }
 
}









void main()
{
struct node *temp=NULL;



add(&temp,100);
add(&temp,200);
add(&temp,800);
add(&temp,400);
add(&temp,900);
add(&temp,982);
add(&temp,610);
add(&temp,129);
add(&temp,875);
add(&temp,340);
add(&temp,954);
//add(&temp,612);

temp=reversetoknodes(temp,3);
//display(temp);

}
