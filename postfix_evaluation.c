#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int info;
	struct node *link;
};
struct node *top=NULL;
int priority(char);
void push(int);
int pop();
void postfix_evaluation(char[]);
void display_stack();
void main()
{
	char postfix[100];
	printf("Enter Postfix Expression: ");
	gets(postfix);
	postfix_evaluation(postfix);
}
void postfix_evaluation(char postfix[])
{
	int len,i,a,b,c;
	len=strlen(postfix);
	for(i=0;i<len;i++)
	{
		if(isalpha(postfix[i]))
		{
			printf("\n\t\t Alphabetes are not allowed!");
			printf("\n\t\t Enter only Numericals!");
			fflush(stdin);
			getchar();
			exit(0);
		}
	}
	for(i=0;i<len;i++)
	{
		switch(priority(postfix[i]))
		{
			case 0:
				printf("\n\t\t\tOperand Encountered");
				printf("\n\n\tPushing %c...",postfix[i]);
				push((int)postfix[i]-48);
				display_stack();
				fflush(stdin);
				getchar();
				break;
			case 1:
				printf("\n\t\t\tOperator Encountered");
				printf("\n\n\tPoping %d...",top->info);
				a=(int)pop();
				printf("\n\n\tPoping %d...",top->info);
				b=(int)pop();
				display_stack();
				printf("\n\nAppling '+' operator---> Result= %d is pushing back to the stack",b+a);
				c=b+a;
				push(c);
				display_stack();
				fflush(stdin);
				getchar();
				break;
			case 2:
				printf("\n\t\t\tOperator Encountered");
				printf("\n\n\tPoping %d...",top->info);
				a=(int)pop();
				printf("\n\n\tPoping %d...",top->info);
				b=(int)pop();
				display_stack();
				printf("\n\nAppling '-' operator---> Result= %d is pushing back to the stack",b-a);
				c=b-a;
				push(c);
				display_stack();
				fflush(stdin);
				getchar();
				break;
			case 3:
				printf("\n\t\t\tOperator Encountered");
				printf("\n\n\tPoping %d...",top->info);
				a=(int)pop();
				printf("\n\n\tPoping %d...",top->info);
				b=(int)pop();
				display_stack();
				printf("\n\nAppling '*' operator---> Result= %d is pushing back to the stack",b*a);
				c=b*a;
				push(c);
				display_stack();
				fflush(stdin);
				getchar();
				break;
			case 4:
				printf("\n\t\t\tOperator Encountered");
				printf("\n\n\tPoping %d...",top->info);
				a=(int)pop();
				printf("\n\n\tPoping %d...",top->info);
				b=(int)pop();
				display_stack();
				printf("\n\nAppling '/' operator---> Result= %d is pushing back to the stack",b/a);
				c=b/a;
				push(c);
				display_stack();
				fflush(stdin);
				getchar();
				break;
			case 5:
				printf("\n\t\t\tOperator Encountered");
				printf("\n\n\tPoping %d...",top->info);
				a=(int)pop();
				printf("\n\n\tPoping %d...",top->info);
				b=(int)pop();
				c=pow(b,a);
				display_stack();
				printf("\n\nAppling '^' operator---> Result= %d is pushing back to the stack",c);
				push(c);
				display_stack();
				fflush(stdin);
				getchar();
				break;
		}
	}
	c=pop();
	printf("\n\t\t The result is: %d",c);
}
int priority(char c)
{
	if(c=='+')
		return 1;
	else if(c=='-')
		return 2;
	else if(c=='*')
		return 3;
	else if(c=='/')
		return 4;
	else if(c=='^')
		return 5;
	else
		return 0;
}
void push(int c)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=c;
	newnode->link=top;
	top=newnode;
}
int pop()
{
	int c;
	struct node *t;
	c=top->info;
	t=top;
	top=top->link;
	free(t);
	return c;
}
void display_stack()
{
	struct node *tmp;
	if(top==NULL)
	printf("\n\n\t\t\t Stack is empty!");
	else
	{
		tmp=top;
		printf("\n\n\t\t TOP--> ");
		while(tmp!=NULL)
		{
			printf("| %d |\n\t\t\t",tmp->info);
			tmp=tmp->link;
		}
	}
}
