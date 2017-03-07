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
 	struct node*z=(struct node*)malloc(sizeof(struct node));
 	      z->data=data;
 	      z->next=*temp;
 	    
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
	   
}




void addelement(struct node**temp,int data)
{
	struct node*z=(struct node*)malloc(sizeof(struct node));
	    
		if(*temp==NULL)
	       {
	       	z->data=data;
	       	z->next=NULL;
	       	*temp=z;
	       	return;
		   }
		   z=*temp;
		  while(z->next!=NULL)
		        {
		          z=z->next;	
				}  
	  		z->next=(struct node*)malloc(sizeof(struct node));
	  		z=z->next;
	  		z->data=data;
	  		z->next=NULL;
}



       void print_element(struct node*temp)
           {
           	while(temp!=NULL)
           	    {
           	      printf(" %d",temp->data);
					 temp=temp->next;	
			    }
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
          struct node* z=*temp;
           *temp=z->next;
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
                   	
                   	
                   	
                   	while(present!=NULL)
                   	 {
                   	future=present->next;
                   	present->next=prev;
                   	prev=present;
                   	present=future;
                     }
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


        struct node*rotatekthelement(struct node*temp,int k)
              {
              	  struct node*curr=temp,*prev=NULL,*next;
              	  int count=0;
              	  
              	  while(curr!=NULL&&count<k)
              	        {
              	          next=curr->next;
						  curr->next=prev;
						  prev=curr;
						  curr=next;
						  ++count;		
						}
						
						if(next!=NULL)
						   {
						   	temp->next=rotatekthelement(next,k);
						   }
						   
						   return prev;
			  }


    void  nthfromlast(struct node*temp,int n)
           {
           	
           	   if(n>count(temp))
           	      {
           	        printf("\nNOT POSSIBLE\n");
					   return;	
				  }
           	
              struct node*p=temp,*q=temp;
			  int i;
			   for(i=1;i<n;i++)
			       p=p->next;
				               	
			    while(p->next!=NULL)
				   {
				   	p=p->next;
				   	q=q->next;
				   }  	      
				 printf("\n from last %d element is %d\n",n,q->data);  
				            	
		   }


void insert(struct node**temp,int data)
     {
     	struct node*p=(struct node*)malloc(sizeof(struct node)),*m=*temp;
     	  p->data=data;
     	if(*temp==NULL||(*temp)->data>=data)
     	   {
     	   	  p->next=*temp;
     	   	  *temp=p;
     	     return;	
		   }
		     
		     while(1)
		          {
		    if((m->data<=data)&&((m->next==NULL)||(m->next->data>data))) 
		          {

		          	p->next=m->next;
		          	m->next=p;
		          	return;
				  }
				  m=m->next;
		      }
	 }

   void printrecursively(struct node*temp)
             {
             	if(temp==NULL)
             	    return;
             	 	     
              printrecursively(temp->next);
			  printf("%d ",temp->data);   
			 }

     struct node* recmerge(struct node*temp1,struct node*temp2)
              {
              	if(temp1==NULL)
              	   return temp2;
              	if(temp2==NULL)
				   return temp1;
				   
				 if(temp1->data>=temp2->data) 
				   {
				     temp2->next=recmerge(temp1,temp2->next);
					 return temp2;	
				   }   
				 else
				   {
				    temp1->next=recmerge(temp1->next,temp2);
					return temp1;	
				   }    
			  }  

              struct node* merge(struct node*temp1,struct node*temp2)
                    {
                    	
						struct node*newnode=(struct node*)malloc(sizeof(struct node));
                    	struct node*p=newnode;          
                    	          
                    	if(temp1==NULL)
                    	   return temp2;
                    	if(temp2==NULL)
						   return temp1;
						   
						  while(temp2&&temp1)
						     {
						       if(temp1->data>=temp2->data)
							         {
							           newnode->next=temp2;
							           newnode=newnode->next;
							           temp2=temp2->next; 
							   	     }
							   	else
								     {
								       newnode->next=temp1;
								        newnode=newnode->next;
							           temp1=temp1->next; 	
									 }     
							 }    
							 if(temp1!=NULL)
							   {
							   	newnode->next=temp1;
							   }
							 if(temp2!=NULL)
							   {
							   	newnode->next=temp2;
							   }  
							 return p->next;
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
	
	printf("\n");
	addelement(&temp,80);
	addelement(&temp,90);
	addelement(&temp,97);
	addelement(&temp,99);
	addelement(&temp,134);
      
	addanywhere(&temp,200,1);
	addanywhere(&temp,920,3);
	addanywhere(&temp,19,2);
	addanywhere(&temp,180,5);
	addanywhere(&temp,4,1);
	
	
	printf("\n");
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
	
	reverselist(&temp);
		printf("\n");
	print_element(temp);
	
	
	midlist(temp);
	
	evenoroddlength(temp);
	
	
	
	find(temp,99);
	
	findnthfromlast(temp,1);
	
	 temp=rotatekthelement(temp,5);
	
		printf("\n");
		printf("after rotation\n");
	    print_element(temp);
	    
	    nthfromlast(temp,6);
	    
	   
	   
	    insert(&temp,88);
	    	printf("\n");
	    print_element(temp);
		
		 printf("\n");
		printrecursively(temp);*/
		
		struct node *temp1=NULL;
		struct node *temp2=NULL;
		
		addelement(&temp1,80);
	    addelement(&temp1,90);
	    addelement(&temp1,97);
	    addelement(&temp1,99);
	    addelement(&temp1,134);
		
		addelement(&temp2,18);
	    addelement(&temp2,30);
	    addelement(&temp2,54);
	    addelement(&temp2,179);
	    addelement(&temp2,194);
	
		struct node *temp3=merge(temp1,temp2);
		  	printf("\n");
	    print_element(temp3);
    return 0;
}
