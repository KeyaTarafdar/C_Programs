//STACK IMPLEMENTATION BY USING ARRAY
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX],top=-1;
void push();
void pop();
void peak();
void display();
void main()
{
	int ch;
	while(1)
	{
		system("CLS");
		printf("\n\t\t\t -----***STACK IMPLEMENTATION BY USING ARRAY***-----\n");
		printf("\n\t\t 0) Exit");
		printf("\n\t\t 1) Push");
		printf("\n\t\t 2) Pop");
		printf("\n\t\t 3) Peak");
		printf("\n\t\t 4) Display");
		printf("\n\n\t\t Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(0);
			case 1:
				push();
				fflush(stdin);
				getchar();
				break;
			case 2:
				pop();
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
void push()
{
	int item;
	if(top==MAX-1)
	{
		printf("\n\t\t Array Overflow!!");
	}
	else
	{
		printf("\n\t\t Enter the element to be inserted: ");
		scanf("%d",&item);
		top++;
		stack[top]=item;
	}
}
void pop()
{
	int item;
	if(top==-1)
	{
		printf("\n\t\t Stack is underflow!!");
	}
	else
	{
		item=stack[top];
		top--;
		printf("\n\t\t Deleted item is: %d",item);
	}
	printf("\n\t\t After pop operation:----\n");
}
void peak()
{
	if(top==-1)
	{
		printf("\n\t\t Stack is empty!!");
	}
	else
	{
		printf("\n\t\t The top element is: %d",stack[top]);
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("\n\t\t Stack is empty!!");
	}
	else
	{
		printf("\n\t\t Your stack elements:---\n");
		printf("\n\t\t\t top---->");
		for(i=top;i>=0;i--)
		{
			printf(" %d\n\t\t\t\t ",stack[i]);
		}
	}
}