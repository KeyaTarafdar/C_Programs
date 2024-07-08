#include<stdio.h>
#include<stdlib.h>
struct node{
	float coff;
	int exp;
	struct node *link;
};
struct node *result=NULL;
void display(struct node *poly);
void create();
void poly_add(struct node *newnode);
void main()
{
	create();
	printf("\n\n\t\t The resultant polynomial equation is: ");
	display(result);
}
void create()
{
	struct node *poly,*newnode,*tmp;
	int i,n,no,j;
	printf("\n\t\t Enter the no of polynomial equation: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		poly=NULL;
		printf("\n\t\t Enter the number of terms in the equation %d: ",i+1);
		scanf("%d",&no);
		printf("\n");
		for(j=0;j<no;j++)
		{
			newnode=(struct node *)malloc(sizeof(struct node));
			newnode->link=NULL;
			printf("\n\tEnter coffetient part of term %d: ",j+1);
			scanf("%f",&newnode->coff);
			printf("\n\tEnter exponent part of term %d: ",j+1);
			scanf("%d",&newnode->exp);
			poly_add(newnode);
			if(poly==NULL)
			{
				poly=tmp=newnode;
			}
			else
			{
				tmp=poly;
				while(tmp->link!=NULL)
				{
					tmp=tmp->link;
				}
				tmp->link=newnode;
			}
		}
		printf("\n\t\t The polynomial equation %d: ",i+1);
		display(poly);
		printf("\n");
	}
}
void poly_add(struct node *newnode)
{
	struct node *p,*tmp;
	if(result==NULL)
	{
		result=(struct node *)malloc(sizeof(struct node));
		result->link=NULL;
		result->coff=newnode->coff;
		result->exp=newnode->exp;
	}
	else
	{
		tmp=result;
		if(result->exp==newnode->exp)
		{
			result->coff=result->coff + newnode->coff;
			result->exp=newnode->exp;
			return;
		}
		else if(result->exp!=newnode->exp && result->link==NULL)
		{
			p=(struct node *)malloc(sizeof(struct node));
			p->coff=newnode->coff;
			p->exp=newnode->exp;
			p->link=NULL;
			result->link=p;
			return;
		}
		else
		{
			tmp=result;
			while(tmp->link->exp>newnode->exp && tmp->link->link!=NULL)
			{
				tmp=tmp->link;
			}
			if(tmp->link->exp==newnode->exp)
			{
				tmp->link->coff=tmp->link->coff + newnode->coff;
				return;
			}
			else if(tmp->link->exp>newnode->exp)
			{
				tmp=tmp->link;
				p=(struct node *)malloc(sizeof(struct node));
				p->link=tmp->link;
				p->coff=newnode->coff;
				p->exp=newnode->exp;
				tmp->link=p;
				return;
			}
			else
			{
				p=(struct node *)malloc(sizeof(struct node));
				p->link=tmp->link;
				p->coff=newnode->coff;
				p->exp=newnode->exp;
				tmp->link=p;
				return;
			}
		}
	}
}
void display(struct node *poly)
{
	struct node *tmp;
	tmp=poly;
	if(poly==NULL)
	{
		printf("NULL");
	}
	else
	{
		while(tmp!=NULL)
		{
			if(tmp->coff==0)
			{
				tmp=tmp->link;
			}
			else
			{
				printf("%.fx^%d",tmp->coff,tmp->exp);
				tmp=tmp->link;
				if(tmp!=NULL)
				{
					if(tmp->coff>0)
					{
						printf(" + ");
					}
					else
					{
						tmp->coff=(-1)*tmp->coff;
						printf(" - ");
					}
				}
			}
		}
	}
	printf("= 0");
}
