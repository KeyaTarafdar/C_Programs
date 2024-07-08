//QUEUE IMPLEMENTATION BY USING ARRAY
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX],front=-1,rear=-1;
void enqueue();
void dequeue();
void peak();
void display();
void main()
{
	int ch;
	while(1)
	{
		system("CLS");
		printf("\n\t\t\t -----***QUEUE IMPLEMENTATION BY USING ARRAY***-----\n");
		printf("\n\t\t 0) Exit");
		printf("\n\t\t 1) Enqueue");
		printf("\n\t\t 2) Dequeue");
		printf("\n\t\t 3) Peak");
		printf("\n\t\t 4) Display");
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
	int item;
	if(rear==MAX-1)
	{
		printf("\n\t\t Queue Overflow!!");
	}
	else if(front==-1 && rear==-1)
	{
		printf("\n\t\t Enter the element to be inserted: ");
		scanf("%d",&item);
		front=0;
		rear=0;
		queue[rear]=item;
	}
	else
	{
		printf("\n\t\t Enter the element to be inserted: ");
		scanf("%d",&item);
		rear++;
		queue[rear]=item;
	}
}
void dequeue()
{
	int item;
	if(front==-1 && rear==-1)
	{
		printf("\n\t\t Queue Underflow!!");
	}
	else
	{
		item=queue[front];
		front++;
		printf("\n\t\t Deleted item is: %d",item);
	}
}
void peak()
{
	if(front=rear==-1)
	{
		printf("\n\t\t Queue is empty!!");
	}
	else
	{
		printf("\n\t\t The front element is: %d",queue[front]);
		printf("\n\t\t The rear element is: %d",queue[rear]);
	}
}
void display()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("\n\t\t Queue is empty!!");
	}
	if(front>rear)
	{
		printf("\n\t\t Front(%d)-->NO ELEMENT<--rear(%d)",front,rear);
	}
	else
	{
		printf("\n\t\t Your queue elements:---\n\n");
		printf("\n\t\t Front(%d)-->",front);
		for(i=front;i<=rear;i++)
		{
			printf(" |%d| ",queue[i]);
		}
		printf("<--rear(%d)",rear);
	}
}

