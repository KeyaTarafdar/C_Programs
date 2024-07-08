#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	char info;
	struct node *link;
};
int priority(char);
void push(char);
char pop();
void infix_postfix(char[],char[]);
void display_stack();
struct node *top=NULL;
int main()
{
	char infix[100],postfix[100];
	printf("Enter Infix Expression: ");
	gets(infix);
	infix_postfix(infix,postfix);
	return 0;
}
void push(char c)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=c;
	newnode->link=top;
	top=newnode;
}
char pop()
{
	char c;
	struct node *t;
	c=top->info;
	top=top->link;
	return c;
}
void infix_postfix(char infix[],char postfix[])
{
	int len,i,j=0,k;
	char c;
	struct node *tmp;
	push('(');
	len=strlen(infix);
	for(i=0;i<len;i++)
	{
		switch(priority(infix[i]))
		{
			case 1:
				push(infix[i]);
				break;
			case 2:
				tmp=top;
				while(top->info!='(' && tmp!=NULL)
				{
					c=pop();
					postfix[j++]=c;
					tmp=tmp->link;
				}
				pop();
				break;
			case 3:
				tmp=top;
				while(tmp!=NULL && tmp->info!='(')
				{
					if(priority(tmp->info)>=3)
					{
						c=pop();
						postfix[j++]=c;
					}
					tmp=tmp->link;
				}
				push(infix[i]);
				break;
			case 4:
				tmp=top;
				while(tmp!=NULL && tmp->info!='(')
				{
					if(priority(tmp->info)>=4)
					{
						c=pop();
						postfix[j++]=c;
					}
					tmp=tmp->link;
				}
				push(infix[i]);
				break;
			case 5:
				tmp=top;
				while(tmp!=NULL && tmp->info!='(')
				{
					if(priority(tmp->info)==5)
					{
						c=pop();
						postfix[j++]=c;
					}
					tmp=tmp->link;
				}
				push(infix[i]);
				break;
			default:
				postfix[j++]=infix[i]; 
		}
	}
	while(top->info!='(')
	{
		c=pop();
		postfix[j++]=c;
	}
	for(k=0;k<j;k++)
	{
		printf("%c",postfix[k]);
	}
}
int priority(char c)
{
	if(c=='(')
		return 1;
	else if(c==')')
		return 2;
	else if(c=='+')
		return 3;
	else if(c=='-')
		return 3;
	else if(c=='*')
		return 4;
	else if(c=='/')
		return 4;
	else if(c=='^')
		return 5;
	else
		return 0;
}
void display_stack()
{
	struct node *tmp;
	tmp=top;
	printf("\n[");
	while(tmp!=NULL)
	{
		printf("%c ",tmp->info);
		tmp=tmp->link;
	}
	printf("]");
}
