#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
	int data;
	struct node* prev;
	struct node* next;	
};




void addelementatfirst(struct node**temp,int data)
 {
 	struct node*z=(struct node*)malloc(sizeof(struct node));
 	      z->data=data;
 	      z->next=*temp;
 	      z->prev=NULL;
 	      if(*temp!=NULL)
 	      (*temp)->prev=z;
		    
		 *temp=z;
 }



void addanywhere(struct node**temp,int data,int pos)
{
	int i;
	struct node*temp2=*temp,*t,*s;
	
	if(temp2==NULL&&pos>1)
	   {
	   	printf("LIST IS EmPTY DESIRED POSITION NOT POSSIBLE\n");
	   	return;
	   }
	   
	    t=(struct node*)malloc(sizeof(struct node));
		t->data=data;
		t->next=*temp;
	    t->prev=NULL;
	    if(*temp!=NULL)
		(*temp)->prev=t;
			
	if(pos==1)
	   {
	    
		 *temp=t;
		 return;	
	   }   
	   
	   
	   
	for(i=1;i<pos-1;i++)
	    {
	      temp2=temp2->next;      	
		}   
		
		s=temp2->next;
		temp2->next=t;
		t->next=s;
		s->prev=t;
		t->prev=temp2;
	   
}





void addelement(struct node**temp,int data)
{
	struct node*d;
	struct node*z=(struct node*)malloc(sizeof(struct node));
	    
		if(*temp==NULL)
	       {
	       	z->data=data;
	       	z->next=NULL;
	       	z->prev=NULL;
	       	*temp=z;
	       	return;
		   }
		   z=*temp;
		  while(z->next!=NULL)
		        {
		          z=z->next;	
				} 
				d=z; 
	  		z->next=(struct node*)malloc(sizeof(struct node));
	  		z=z->next;
	  		z->data=data;
	  		z->next=NULL;
	  		z->prev=d;
}







 void delete_atlast(struct node**temp)
    {
    	struct node*z=*temp;
    	while(z->next->next!=NULL)
    	    {
    	    	z=z->next;
			}
			free(z->next);
			z->next=NULL;
	}


  void  delete_atbegin(struct node**temp)
        {
          struct node*z=*temp;
           *temp=z->next;
            (*temp)->prev=NULL;
           free(z);
		}


   void delete_atanyplace(struct node**temp,int place)
        {
          struct node*z=*temp,*x;
		  int i;
		  
		    if(place==1)
		       {
		       	x=*temp;
		       	*temp=(*temp)->next;
		       	(*temp)->prev=NULL;
		       	free(x);
		       	return;
			   }
		  
		  for(i=1;i<place-1;i++)
		      {
		      z=z->next;
              }
              
		   x=z->next;
		   z->next=z->next->next;
		   if(z->next!=NULL)
		   z->next->next->prev=z;   
		  	free(x);
		}


       void  reverselist(struct node**temp)
                  {
                   	struct node*prev1=NULL,*present=*temp,*future,*prev;
                   	
                   	
                   	
                   	while(present!=NULL)
                   	 {
                   	future=present->next;
                   	present->next=prev1;
                   	present->prev=future;
                   	prev1=present;
                   	present=future;
                   	  if(present==NULL)
                   	     {
                   	      prev1->prev=NULL;	
					     }
                     }
                     *temp=prev1;
				  }   


void midlist(struct node*temp)
   {
   	struct node*fast,*slow;
   	
   	if(temp==NULL)
   	   return;
   	
   	fast=slow=temp;
   	
   	  while(fast->next!=NULL&&fast->next->next!=NULL)
   	    {
   	    	
   	    	fast=fast->next->next;
   	    	slow=slow->next;
   	    
		}
		
   	printf("\n\n  Middle element  is=> %d",slow->data);
   }


void evenoroddlength(struct node*temp)
      {
      	int i=0;
      	while(temp!=NULL)
      	      {
      	        temp=temp->next;
				 ++i; 	
			  }
		
		 if(i%2==0)
		     printf("\nlist is even\n");
	     else
		     printf("\nlist is odd\n");		 	  
	  }



void find(struct node*temp,int data)
{
	while(temp!=NULL)
	      {
	      	if(temp->data==data)
	      	     {
	      	     	printf("\nFOUND ELEMENT\n");
	      	     	return;
				 }
				 temp=temp->next;
		  }
		  printf("\nNOT FOUND\n");
}


  int count(struct node*temp)
       {
       	int n=0;
       	  while(temp!=NULL)
       	      {
       	         ++n;	
       	        temp=temp->next;	
			  }
			  return n;
	   }



void findnthfromlast(struct node*temp,int n)
           {
           	
           	int m=count(temp);
           	
			    if(n>m)
           	    {
           	      printf("\nSIZE IS NOT POSSIBLE\n");
					 return;	
				}
           	 
           	 m=m-n;
           	 int i;
           	 for(i=1;i<=m;i++)
           	     {
           	       temp=temp->next;	
				 }
				 
				 printf("\nThe %d element from last is %d\n",n,temp->data);
		   }



       void print_element(struct node*temp)
           {
           	  while(temp!=NULL)
           	    {
           	      printf(" %d",temp->data);
					 temp=temp->next;	
			    }
		   }



int main() 
{
struct node*temp=NULL;
	/*
	addelementatfirst(&temp,100);
	addelementatfirst(&temp,200);
	addelementatfirst(&temp,300);
	addelementatfirst(&temp,400);
	addelementatfirst(&temp,500);
	
	
	print_element(temp);
	*/
	printf("\n");
	addelement(&temp,80);
	addelement(&temp,90);
	addelement(&temp,97);
	addelement(&temp,9);
	addelement(&temp,134);
	
//	print_element(temp);
     printf("\n"); 
	addanywhere(&temp,200,1);
	addanywhere(&temp,920,3);
	addanywhere(&temp,19,2);
	addanywhere(&temp,180,5);
	addanywhere(&temp,4,1);
	
	
	print_element(temp);
	
	/*
  	delete_atlast(&temp);
	printf("\n");
	print_element(temp);
	
	
   	delete_atbegin(&temp);
	printf("\n");
	print_element(temp);
	
	*/
	
	delete_atanyplace(&temp,10);
	printf("\n");
	print_element(temp);
	/*
	printf("\nreverse linked list  \n");
	reverselist(&temp);
		printf("\n");
	print_element(temp);
	*/
	/*
	midlist(temp);
	
	evenoroddlength(temp);
	
	
	
	find(temp,99);
	
	findnthfromlast(temp,1);*/
	
    return 0;
}
