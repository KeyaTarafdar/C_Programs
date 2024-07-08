//STACK IMPLEMENTATION BY USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct node{
	int info;
	struct node *link;
};
int n=1;
struct node *push(struct node *top);
struct node *pop(struct node *top);
void peak(struct node *top);
void display(struct node *top);
void main()
{
	int ch;
	struct node *top;
	top=NULL;
	while(1)
	{
		system("CLS");
		printf("\n\t\t\t -----***STACK IMPLEMENTATION BY USING LINKED LIST***-----\n");
		printf("\n\t\t\t\t 0) Exit");
		printf("\n\t\t\t\t 1) Push");
		printf("\n\t\t\t\t 2) Pop");
		printf("\n\t\t\t\t 3) Peak");
		printf("\n\t\t\t\t 4) Display");
		printf("\n\n\t\t Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(0);
			case 1:
				top=push(top);
				fflush(stdin);
				getchar();
				break;
			case 2:
				top=pop(top);
				fflush(stdin);
				getchar();
				break;
			case 3:
				peak(top);
				fflush(stdin);
				getchar();
				break;
			case 4:
				display(top);
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
struct node *push(struct node *top)
{
	struct node *newnode;
	if(n<=MAX)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\n\t\t Enter element %d: ",n);
		scanf("%d",&newnode->info);
		newnode->link=top;
		top=newnode;
		n++;
	}
	else
	{
		printf("\n\t\t\t\t Stack Overflow!!");
	}
	return top;
}
struct node *pop(struct node *top)
{
	if(top==NULL)
	{
		printf("\n\t\t\t Stack Underflow!!");
	}
	else
	{
		struct node *p;
		p=top;
		top=p->link;
		free(p);
		n--;
	}
	return top;
}
void display(struct node *top)
{
	struct node *tmp;
	if(top==NULL)
	{
		printf("\n\t\t Stack is Empty!!");
	}
	else
	{
		printf("\n\t\t The Stack is:---\n");
		printf("\n\t\t TOP--->");
		tmp=top;
		while(tmp!=NULL)
		{
			printf("| %d |\n\t\t\t",tmp->info);
			tmp=tmp->link;
		}
	}
}
void peak(struct node *top)
{
	printf("\n\t\t The Peak of the Stack is: %d",top->info);
}
