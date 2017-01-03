#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
int i=0;
struct node
{
	int element;
	struct node *next;
};
struct node *H;
void create(int data);
void display();
void insertfirst(int data);
void insertmid(int data,int p);
void insertlast(int data);
void delete(int data);
void find(int data);

void main()
{
	int choice,data,y;
	char ch;
	clrscr();
	H=(struct node *)malloc(sizeof(struct node));
	H->next=NULL;
	printf("** Linked List Implementation **");
	do
	{
		printf("\n 1. Create \t2.display\t3.Insertfirst\t4.Insertmid\t5.InsertLast\t6.Delete\t7.search\t");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("\n enter data:");
				scanf("%d",&data);

				create(data);
				break;

			case 2:display();
				break;

			case 3:
			printf("\n enter data:");
				scanf("%d",&data);
				insertfirst(data);
				break;
			case 4:
				printf("\n Enter the data to be inserted:");
				scanf("%d",&data);
				printf("\n Enter the position:");
				scanf("%d",&y);
				insertmid(data,y);
				break;
			case 5:
				   printf("\n enter data:");
				scanf("%d",&data);
				insertlast(data);
				break;

			case 6:
				printf("\n Enter the data to be deleted:");
				scanf("%d",&data);
				delete(data);
				break;

			case 7:
				printf("\n Enter the data to be searched:");
				scanf("%d",&data);
				find(data);
				break;

			default:
			printf("invalid choice");

		}
		printf("\n do you want to continue?");
		scanf("%s",&ch);
	}while(ch=='y'||ch=='Y');
}

void create(int data)
{
	  struct node *temp;
	  temp=(struct node *)malloc(sizeof(struct node));
	  if(i==0)
	  {
		  temp->element=data;
		  temp->next=NULL;
		  H=temp;
	  } i++;
	   printf("list created");
	  getch();
}

void display()
{
	struct node *ptr;
	ptr=H;

	if(ptr==NULL)
	{
		printf("\n empty list");
		getch();
		return;
	}
	while(ptr!=NULL)
	{
		printf("%d->",ptr->element);
		ptr=ptr->next;
	}
	printf("end of list");
	getch();
}

void insertfirst(int data)
{
	struct node *temp;
	  temp=(struct node *)malloc(sizeof(struct node));
	  if(i>0)
	  {
		  temp->element=data;
		  temp->next=H;
		  H=temp;
	  }
	  i++;
}

void insertmid(int data,int p)
{
   struct node *temp,*pos;

	  temp=(struct node *)malloc(sizeof(struct node));
	  temp->element=data;
	  if(p>i)
	  {
		printf("invalid position");
	  }
	  else
	  {
	  pos=H;
		for(i=1;i<p;i++)
			pos=pos->next;


		  temp->next=pos->next;
		  pos->next=temp;
	  }
	  i++;
}
void insertlast(int data)
{
	struct node *temp,*p;
	  temp=(struct node *)malloc(sizeof(struct node));
	  if(i>0)
	  {
		  p=H;
		  while(p->next!=NULL)
		  {
			p=p->next;
		  }
		  temp->element=data;
		  temp->next=NULL;
		  p->next=temp;
	  }
	  i++;
}
void find(int data)
{
	struct node *p;
	int j=0;
	  p=H;
	  while(p!=NULL&&p->element!=data)
	  {
		p=p->next;
		j++;
	  }
	  if(p->next==NULL)
		printf("The element is not in the list");
	  else
		printf("The Element %d is in position %d",data,j+1);
}
void delete(int data)
{
	struct node *p,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	p=H;
	while(p->next!=NULL&&p->next->element!=data)
		p=p->next;
	if(p->next!=NULL)
	{
	temp=p->next;
	p->next=temp->next;
	free(temp);
	}
	i--;
	printf("\n The element has been deleted");
}








