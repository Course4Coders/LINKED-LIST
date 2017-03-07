#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
	int data;
	struct node* next;	
};




void addelementatfirst(struct node**temp,int data)
 {
 	struct node*t=*temp;
 	
 	struct node*z=(struct node*)malloc(sizeof(struct node));
 	            
				 z->data=data;
	            if(*temp==NULL)
		     	 z->next=z;
	             else
	             {
	             	z->next=*temp;
	             	while(t->next!=*temp)
	             	    t=t->next;
	             	 t->next=z;   
				 }
			     
		 *temp=z; 
		  
 }



void addanywhere(struct node**temp,int data,int pos)
{
	int i;
	struct node*temp2=*temp,*t,*s;
	int m=count(temp);
	
	if((temp2==NULL&&pos>1)&&m<pos)
	   {
	   	printf("DESIRED POSITION NOT POSSIBLE\n");
	   	return;
	   }
	   
	    t=(struct node*)malloc(sizeof(struct node));
		t->data=data;
		t->next=(*temp);
		
	if(pos==1)
	   {
	      while(temp2->next!=*temp)
	           {
	           	temp2=temp2->next;
			   }
			   temp2->next=t;
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
		
	   
}



void sortedInsert(struct node** head_ref, int x)
{
    struct node*temp=*head_ref;
    struct node*temp2=(struct node*)malloc(sizeof(struct node));
      temp2->data=x;
    
  if((*head_ref)->data==x)
      {
         while(temp->next!=*head_ref)
             {
                 temp=temp->next;
             }
             
              temp->next=temp2;
              temp2->next=*head_ref;
              *head_ref=temp2;
             return;
      }
      
         
             while(1)
                 {
              if((temp->data<=x)&&((temp->next==*head_ref)||(temp->next->data>x))) 
               {
                   
                   temp2->next=temp->next;
                   temp->next=temp2;
                   break;
               }    
               temp=temp->next;
                 }
}



void addelement(struct node**temp,int data)
{
	struct node*z=(struct node*)malloc(sizeof(struct node));
	    
		if(*temp==NULL)
	       {
	       	z->data=data;
	       	z->next=z;
	       	*temp=z;
	       	return;
		   }
		   z=*temp;
		  while(z->next!=*temp)
		        {
		          z=z->next;	
				}  
	  		z->next=(struct node*)malloc(sizeof(struct node));
	  		z=z->next;
	  		z->data=data;
	  		z->next=*temp;
}



       


 void delete_atlast(struct node**temp)
    {
    	struct node*z=*temp;
    	while(z->next->next!=*temp)
    	    {
    	    	z=z->next;
			}
			free(z->next);
			z->next=*temp;
	}


  void  delete_atbegin(struct node**temp)
        {
          struct node* z=*temp,*m=*temp;
             while(m->next!=*temp)
                 {
                  	m=m->next;
				 }
				 *temp=z->next;
				 m->next=*temp;
           free(z);
		}


   void delete_atanyplace(struct node**temp,int place)
        {
          struct node*z=*temp,*x;
		  int i;
		  
		    if(place==1)
		       {
		       	x=*temp;
		       	while(z->next!=*temp)
                 {
                  	z=z->next;
			     }
			     
		       	*temp=(*temp)->next;
		       	   z->next=*temp;
		       	free(x);
		       	return;
			   }
		  
		  for(i=1;i<place-1;i++)
		      z=z->next;
		      
		   x=z->next;
		   z->next=z->next->next;   
		  	free(x);
		}


       void  reverselist(struct node**temp)
                  {
                   	struct node*prev=NULL,*present=*temp,*future;
                   	
                   	struct node*t=*temp;
                   	
                   	while(t->next!=*temp)
                   	      {
                   	      	t=t->next;
						  }
                   	
                   	prev=t;
                   	
                      do
                   	 {
                   	future=present->next;
                   	present->next=prev;
                   	prev=present;
                   	present=future;
                     }	while(present!=*temp);
                     *temp=prev;
                     
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
           	
           	struct node*curr=temp;
           	   do
           	    {
           	      printf(" %d",curr->data);
					 curr=curr->next;
					
			    }
				while(curr!=temp);
			    
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
	addelement(&temp,99);
	addelement(&temp,134);
	
	   
		print_element(temp);
          printf("\n");
       sortedInsert(&temp,95);
	       print_element(temp);  
          
  /*        
	addanywhere(&temp,200,1);
	addanywhere(&temp,920,3);
	addanywhere(&temp,19,2);
	addanywhere(&temp,180,5);
	addanywhere(&temp,4,1);
	
	
	print_element(temp);
	
	
  	delete_atlast(&temp);
	printf("\n");
	print_element(temp);
	
	
   	delete_atbegin(&temp);
	printf("\n");
	print_element(temp);
	
	
	
	delete_atanyplace(&temp,1);
	printf("\n");
	print_element(temp);

     printf("\nREVERSE LIST\n");
	reverselist(&temp);
		printf("\n");
	 
	print_element(temp);
	
	/*
	midlist(temp);
	
	evenoroddlength(temp);
	
	
	
	find(temp,99);*/
	
	//findnthfromlast(temp,1);
	
    return 0;
}
