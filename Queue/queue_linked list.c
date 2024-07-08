//QUEUE IMPLEMENTATION BY USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int n=1;
struct node{
	int info;
	struct node *link;
};
struct node *rear=NULL,*front=NULL;
void enqueue();
void dequeue();
void peak();
void display();
void main()
{
	int ch;
	rear=front=NULL;
	while(1)
	{
		system("CLS");
		printf("\n\t\t\t -----***QUEUE IMPLEMENTATION BY USING LINKED LIST***-----\n");
		printf("\n\t\t\t\t 0) Exit");
		printf("\n\t\t\t\t 1) Enqueue");
		printf("\n\t\t\t\t 2) Dequeue");
		printf("\n\t\t\t\t 3) Peak");
		printf("\n\t\t\t\t 4) Display");
		printf("\n\n\t\t Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(0);
			case 1:
				enqueue();
				fflush(stdin);
				getchar();
				break;
			case 2:
				dequeue();
				fflush(stdin);
				getchar();
				break;
			case 3:
				peak();
				fflush(stdin);
				getchar();
				break;
			case 4:
				display();
				fflush(stdin);
				getchar();
				break;
			default:
				printf("\n\t\t\t Wrong Choice!!");
				fflush(stdin);
				getchar();	
		}
	}
}
void enqueue()
{
	struct node *tmp,*newnode;
	if(n<=MAX)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\n\t\t Enter element %d: ",n);
		scanf("%d",&newnode->info);
		newnode->link=NULL;
		if(n==1)
		{
			front=newnode;
			rear=newnode;
		}
		else
		{
			tmp=front;
			while(tmp->link!=NULL)
			{
				tmp=tmp->link;
			}
			tmp->link=newnode;
			rear=newnode;
		}
		n++;
	}
	else
	{
		printf("\n\t\t\t Queue Overflow!!");
	}
}
void dequeue()
{
	if(n==1)
	{
		printf("\n\t\t\t Queue Underflow!!");
	}
	else
	{
		struct node *p;
		p=front;
		front=p->link;
		free(p);
		n--;
	}
}
void display()
{
	struct node *tmp;
	int i=1;
	if(front==NULL || rear==NULL)
	{
		printf("\n\t\t\t Front---> NO ELEMENT <---Rear");
		printf("\n\n\t\t\t\t Queue is empty!!");
	}
	else
	{
		tmp=front;
		printf("\n\t\t The Queue is:---\n\n");
		printf("\t--------------------------------------------------------------------------\n");
		printf("\t\t Front--->  |");
		while(i<=n && tmp!=NULL)
		{
			printf(" %d ",tmp->info);
			tmp=tmp->link;
			i++;
		}
		printf("|");
		printf(" <---Rear");
		printf("\n\t--------------------------------------------------------------------------");
	}
}
void peak()
{
	printf("\n\t\t\t Front element: %d\n",front->info);
	printf("\n\t\t\t Rear element: %d",rear->info);
}
