#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
                                               // global declaration i,k
int i=0,k;                                   //'i' = Total no of element in the list
                                                               
struct node
{       struct node *pre;
	int element;
	struct node *next;
}*h,*e;                                   // '*h'=First element & '*e' =Last element
                                                                       
void create(int data);
void display();
void insertfirst(int data);
void insertmid(int data,int p);          //  Function decleration
void insertlast(int data);
void change_header(int data);
void delete(int data);
void find(int data);

void main()
{
     int choice,p,data,t;
     char c;
     clrscr();
     h=(struct node *)malloc(sizeof(struct node));
     h=NULL; e=NULL;
     printf("\t\t** Doubely Linked List Implementation **");
     while(1)
     {
       printf("\n1.Create\t2.Display\t3.Insert First\t4.Insert Middle\t5.Insert Last\t6.Change first element\t\t7.Delete\t8.Search\t9.Exit");
       printf("\nEnter your choice :");
       scanf("%d",&choice);
       switch(choice)
       {
	 case 1:{ if(i==0)
		 {      printf("How many data to be entered in the list : ");
			scanf("%d",&t);
			printf("\nEnter data : ");
			 scanf("%d",&data);
			 create(data);
			 for(k=1;k<t;k++)
			 {  scanf("%d",&data);
			    insertlast(data);  }
			printf("\nList Created");
		 }
		 else
			  printf("list alrady exit");
		 break;
		 }
	 case 2:
		 {
		 display();
		 break;
		 }
	 case 3: {if(i==0)
		  printf("\n\"----LIST EMPTY----\"");
	       else
		 { printf("\nEnter data : ");
		   scanf("%d",&data);
		   insertfirst(data);
		 }
		break;
		}
	 case 5: {if(i==0)
		  printf("\n\"----LIST EMPTY----\"");
		else
		 {
		 printf("\nEnter data : ");
		 scanf("%d",&data);
		 insertlast(data);

		 }
	   }     break;

	 case 4: {if(i==0)
		  printf("\n\"----LIST EMPTY----\"");
		else
		  {
		 printf("Enter the position (1 to %d) : ",i-1);
		 scanf("%d",&p);
		 if( (p>0) && (p<i) )
		      {	printf("\nEnter data : ");
			scanf("%d",&data);
			insertmid(data,p);  }

		 }
	   }    break;

	 case 6: {if(i==0)
		  printf("\n\"----LIST EMPTY----\"");
		else
		 {
		  printf("\nWhich data do you want to set as a first element in the list : ");
		   scanf("%d",&data);
		   change_header(data);
		 }
	   }    break;

	 case 7: {if(i==0)
		 printf("\n\"----LIST EMPTY----\"");
		else
		 {
		   printf("\nWhich data do you want to delete from the list : ");
		   scanf("%d",&data);
		   delete(data);
		 }
	   }   break;

	 case 8: {if(i==0)
		  printf("\n\"----LIST EMPTY----\"");
		else
		 {
		   printf("\nEnter data to be searched from the list : ");
		   scanf("%d",&data);
		   find(data);
		 }  break;
	   }

	  case 9:
		 { printf("\n~~~~EXIT~~~~");
	     getch();
		     exit(0);
		 }
	  default :
		printf("\nInvalid option...!Please enter correct option");
       }               //End of switch
     }      //End of while loop
}       //End of main function

void create(int data)
{
     struct node *temp;
     temp=(struct node *)malloc(sizeof(struct node));
		  temp->element=data;
		  temp->next=temp;
		  temp->pre=temp;
		  h=temp;
		  e=temp;
		  i++;
}

void display()
{
     struct node *ptr,*p;
	ptr=h;
	if(ptr==NULL)
		printf("\n\"-----LIST EMPTY-----\"");
	else
	    {   printf("\nCorrect order...\n"); k=0;
		while(k<i)
		{
			printf("%d->",ptr->element);
			ptr=ptr->next;       k++;
		}
		printf("End of list\nReverse order...\n");
		ptr=e; k=0;
		while(k<i)
		{
			printf("%d<-",ptr->element);
			ptr=ptr->pre;          k++;
		}
		printf("Begining of list\n");
	    }
}

void insertfirst(data)
{
	struct node *temp;
	  temp=(struct node *)malloc(sizeof(struct node));
	  if(i>0)
	  {        temp->element=data;
	            temp->next=h;
	            temp->pre=e;
	            h->pre=temp;
	            h=temp;
                            e->next=h;
	            i++;                        }
}

void insertlast(int data)
{
	struct node *temp,*pos;
	  temp=(struct node *)malloc(sizeof(struct node));
	  if(i>0)
	  {        temp->element=data;
	            temp->next=h;
	            temp->pre=e;
	            e->next=temp;
	            e=temp;
	            h->pre=e;
	            i++;		  }
}

void insertmid(int data,int p)
{
	struct node *temp,*pos;
	temp=(struct node *)malloc(sizeof(struct node));
	pos=h;
	for(k=0;k<p-1;k++)
	          pos=pos->next;
                 temp->element=data;
                 temp->next=pos->next;
                 temp->pre=pos;
                 pos->next->pre=temp;
                 pos->next=temp;
	 i++;
}

void change_header(data)
{
	struct node *pos;
	pos=h;       k=0;
	while( (pos->element!=data) && (k<i) )
	   {    pos=pos->next;
		k++;        }
	if(pos->element==data)
	   {    h=pos;
		e=h->pre;   }
	else
	  printf("%d is not in this list",data);
}

void delete(data)
{
	struct node *pos;
	pos=h;       k=0;
	while( (pos->element!=data) && (k<i) )
	   {    pos=pos->next;
		k++;                }
	if(pos->element==data)
	   {	if(k==0)
		   {    h=h->next;
			e->next=h;      }
		if(k==i-1)
		   {    e=e->pre;
			h->pre=e;         }
		if( (k>0) && (k<i-2) )
		   {     pos->pre->next=pos->next;
			 pos->next->pre=pos->pre;
			 free(pos);        }
		i--;
		printf("%d has been deleted from position %d",data,k);
	   }
	else
	   printf("%d is not in this list ",data);
}

void find(int data)
{
	struct node *pos;
	pos=h;       k=1;
	while( (pos->element!=data) && (k<=i) )
	   {    pos=pos->next;
		k++;                }
	if(pos->element==data)
	    printf("%d is in the position %d",data,k);
	else
	    printf("%d is not in the list",data);
}
