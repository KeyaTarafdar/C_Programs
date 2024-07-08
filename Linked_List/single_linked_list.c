//SINGLELY LINKED LIST OPERATIONS:--
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *create(struct node *start);
void display(struct node *start);
struct node *insert_beg(struct node *start, int data);
struct node *insert_end(struct node *start, int data);
struct node *insert_after(struct node *start,int data);
struct node *insert_before(struct node *start,int data);
struct node *insert_pos(struct node *start, int data);
int count_node(struct node *start);
void search(struct node *start,int data);
struct node *del_data(struct node *start,int data);
struct node *del_pos(struct node *start);
struct node *reverse(struct node *start);
struct node *sort_data(struct node *start);
struct node *sort_insert(struct node *start);
void main()
{
	int ch,chh,valid=0,data,chhh,chhhh,i,n;
	struct node *start;
	while(1)
	{
		system("CLS");
		printf("\n\t\t\t\t ------***LINKED LIST OPERATIONS***------\n");
		printf("\n\t\t\t\t\t 0) Exit");
		printf("\n\t\t\t\t\t 1) Create");
		printf("\n\t\t\t\t\t 2) Display");
		printf("\n\t\t\t\t\t 3) Insertion");
		printf("\n\t\t\t\t\t 4) Count node");
		printf("\n\t\t\t\t\t 5) Search");
		printf("\n\t\t\t\t\t 6) Deletion");
		printf("\n\t\t\t\t\t 7) Reverse");
		printf("\n\t\t\t\t\t 8) Sorting");
		printf("\n\n\t\t Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(0);
			case 1:
				if(valid==0)
				{
					start=create(start);
					valid=1;
				}
				else
				{
					printf("\n\t\t The linked list is already created!!");
				}
				fflush(stdin);
				getchar();
				break;
			case 2:
				if(valid==1)
				{
					display(start);
				}
				else
				{
					printf("\n\t\t The linkde list is not created!!");
				}
				fflush(stdin);
				getchar();
				break;
			case 3:
				if(valid==1)
				{
					printf("\n\t\t\t 1) Insert at beg");
					printf("\n\t\t\t 2) Insert at end");
					printf("\n\t\t\t 3) Insert by after");
					printf("\n\t\t\t 4) Insert by before");
					printf("\n\t\t\t 5) Insert by position");
					printf("\n\n\t\t Enter your choice for insertion: ");
					scanf("%d",&chh);
					switch(chh)
					{
						case 1:
							start=insert_beg(start,data);
							break;
						case 2:
							start=insert_end(start,data);
							break;
						case 3:
							start=insert_after(start,data);
							break;
						case 4:
							start=insert_before(start,data);
							break;
						case 5:
							start=insert_pos(start,data);
							break;
						default:
							printf("\n\t\t\t Wrong choice!!");
							fflush(stdin);
							getchar();
					}
				}
				else
				{
					printf("\n\t\t The linkde list is not created!!");
				}
				fflush(stdin);
				getchar();
				break;
			case 4:
				if(valid==1)
				{
					count_node(start);
				}
				else
				{
					printf("\n\t\t The linked list is not created!!");
				}
				fflush(stdin);
				getchar();
				break;
			case 5:
				if(valid==1)
				{
					search(start,data);
				}
				else
				{
					printf("\n\t\t The linked list is not created!!");
				}
				fflush(stdin);
				getchar();
				break;
			case 6:
				if(valid==1)
				{
					printf("\n\t\t\t 1) Delete by element");
					printf("\n\t\t\t 2) Delete by position");
					printf("\n\n\t\t Enter your choice for deletion: ");
					scanf("%d",&chhh);
					switch(chhh)
					{
						case 1:
							start=del_data(start,data);
							break;
						case 2:
							start=del_pos(start);
							break;
						default:
							printf("\n\t\t\t Wrong choice!!");
							fflush(stdin);
							getchar();
					}
				}
				else
				{
					printf("\n\t\t The linked list is not created!!");
				}
				fflush(stdin);
				getchar();
				break;
			case 7:
				if(valid==1)
				{
					start=reverse(start);
				}
				else
				{
					printf("\n\t\t The linked list is not created!!");
				}
				fflush(stdin);
				getchar();
				break;
			case 8:
				printf("\n\t\t\t 1) Sort by data exchange");
				printf("\n\t\t\t 2) Sort by insert");
				printf("\n\n\t\t Enter your choice for sorting: ");
				scanf("%d",&chhhh);
				switch(chhhh)
				{
					case 1:
						if(valid==1)
						{
							start=sort_data(start);
						}
						else
						{
							printf("\n\t\t The linked list is not created!!");
						}	
						break;
					case 2:
						{
							start=sort_insert(start);
						}
						break;
					default:
						printf("\n\t\t\t Wrong choice!!");
						fflush(stdin);
						getchar();
				}
				fflush(stdin);
				getchar();
				break;
			default:
				printf("\n\t\t Wrong choice!!");
				fflush(stdin);
				getchar();
		}
	}
}
struct node *create(struct node *start)
{
	int i,n;
	struct node *newnode,*tmp;
	start=NULL;
	printf("\n\t\t Enter the no of nodes: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->link=NULL;
		printf("\n\t\t Enter element %d: ",i);
		scanf("%d",&newnode->info);
		if(start==NULL)
		{
			start=tmp=newnode;
		}
		else
		{
			while(tmp->link!=NULL)
			{
				tmp=tmp->link;
			}
			tmp->link=newnode;
		}
	}
	printf("\n\t\t **The linked list is successfully created**");
	return start;
}
void display(struct node *start)
{
	struct node *tmp;
	tmp=start;
	printf("\n\t\t Your linked list is:---\n\n");
	printf("\tstart:%d--->\t",start);
	while(tmp!=NULL)
	{
		printf("||%u|%d|%u||\n\t\t\t\t",tmp,tmp->info,tmp->link);
		tmp=tmp->link;
	}
}
struct node *insert_beg(struct node *start, int data)
{
	struct node *newnode,*p;
	printf("\n\t\t Before insertion:---\n");
	display(start);
	printf("\n\n\t\t Enter the data will be inserted: ");
	scanf("%d",&data);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=data;
	p=start;
	start=newnode;
	newnode->link=p;
	printf("\n\n\t\t After insertion:---\n");
	display(start);
	return start;
}
struct node *insert_end(struct node *start, int data)
{
	struct node *newnode,*tmp;
	tmp=start;
	printf("\n\t\t Before insertion:---\n");
	display(start);
	printf("\n\n\t\t Enter the data will be inserted: ");
	scanf("%d",&data);
	while(tmp->link!=NULL)
	{
		tmp=tmp->link;
	}
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->link=NULL;
	newnode->info=data;
	tmp->link=newnode;
	printf("\n\n\t\t After insertion:---\n");
	display(start);
	return start;
}
struct node *insert_after(struct node *start,int data)
{
	struct node *newnode,*tmp,*p;
	int item;
	tmp=start;
	printf("\n\t\t Before insertion:---\n");
	display(start);
	printf("\n\n\t\t Enter the item after which the element will be inserted: ");
	scanf("%d",&item);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->link=NULL;
	newnode->info=data;
	while(tmp!=NULL)
	{
		if(tmp->info==item)
		{
			printf("\n\t\t Enter the data will be inserted: ");
			scanf("%d",&data);
			newnode=(struct node *)malloc(sizeof(struct node));
			newnode->link=NULL;
			newnode->info=data;
			p=tmp->link;
			tmp->link=newnode;
			newnode->link=p;
			printf("\n\n\t\t After insertion:---\n");
			display(start);	
			break;
		}
		else
		{
			tmp=tmp->link;
		}
	}
	if(tmp==NULL)
	{
		printf("\n\t\t Element is not present in the list!!");
	}
	return start;
}
struct node *insert_before(struct node *start,int data)
{
	struct node *newnode,*tmp,*p;
	int item;
	tmp=start;
	printf("\n\t\t Before insertion:---\n");
	display(start);
	printf("\n\n\t\t Enter the item before which the element will be inserted: ");
	scanf("%d",&item);
	while(tmp->link!=NULL)
	{
		if(tmp->link->info==item)
		{
			printf("\n\t\t Enter the data will be inserted: ");
			scanf("%d",&data);
			newnode=(struct node *)malloc(sizeof(struct node));
			newnode->link=NULL;
			newnode->info=data;
			p=tmp->link;
			tmp->link=newnode;
			newnode->link=p;
			printf("\n\n\t\t After insertion:---\n");
			display(start);
			break;
		}
		else
		{
			tmp=tmp->link;
		}
	}
	if(tmp->link==NULL)
	{
		printf("\n\t\t Element is not present in the list!!");
	}
	return start;
}
struct node *insert_pos(struct node *start, int data)
{
	struct node *newnode,*tmp,*p;
	int pos,i,n;
	tmp=start;
	printf("\n\t\t Before insertion:---\n");
	display(start);
	n=count_node(start);
	printf("\n\n\t\t Enter the position where the element will be inserted: ");
	scanf("%d",&pos);
	if(pos>n+1)
	{
		printf("\n\t\t Invalid position!!");
	}
	else
	{
		printf("\n\t\t Enter the data will be inserted: ");
		scanf("%d",&data);
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->link=NULL;
		newnode->info=data;
		if(pos==1)
		{
			newnode->link=start;
			start=newnode;
		}
		else
		{
			for(i=1;i<pos-1;i++)
			{
				tmp=tmp->link;
			}
		newnode->link=tmp->link;
		tmp->link=newnode;
		}
		printf("\n\n\t\t After insertion:---\n");
		display(start);
	}
	return start;
}
int count_node(struct node *start)
{
	struct node *tmp;
	int i=0;
	tmp=start;
	while(tmp!=NULL)
	{
		i++;
		tmp=tmp->link;
	}
	printf("\n\t\t Number of nodes in list: %d",i);
	return i;
}
void search(struct node *start,int data)
{
	int a=0,i=1;
	struct node *tmp;
	tmp=start;
	printf("\n\t\t Enter the element to be searched: ");
	scanf("%d",&data);
	while(tmp!=NULL)
	{
		if(tmp->info==data)
		{
			if(a==0)
			{
				printf("\n\t\t The data in present in node: ");
				a=1;
			}
			printf("%d, ",i);
		}
		i++;
		tmp=tmp->link;
	}
	printf("  \b\b");
	if(a==0)
	{
		printf("\n\t\t Element is not present in the list!!");
	}
}
struct node *del_data(struct node *start,int data)
{
	struct node *tmp,*p;
	printf("\n\t\t Before deletion:---\n");
	display(start);
	printf("\n\t\t Enter the data which will be deleted: ");
	scanf("%d",&data);
	tmp=start;
	while(tmp->link!=NULL)
	{
		if(tmp->info==data)
		{
			break;
		}
		else
		{
			p=tmp;
			tmp=tmp->link;
		}
	}
	if(tmp->link!=NULL)
	{
		if(tmp==start)
		{
			start=tmp->link;
			free(tmp);
		}
		else
		{
			p->link=tmp->link;
			free(tmp);
		}
	}
	if(tmp->link==NULL)
	{
		printf("\n\t\t The element is not present in the list!!");
	}
	else
	{
		printf("\n\t\t After deletion:---\n");
		display(start);
	}
	return start;
}
struct node *del_pos(struct node *start)
{
	int n,i,pos;
	struct node *tmp,*p;
	printf("\n\t\t Before deletion:---\n");
	display(start);
	n=count_node(start);
	printf("\n\n\t\t Enter the position from where the data will be delted: ");
	scanf("%d",&pos);
	tmp=start;
	if(pos>n)
	{
		printf("\n\t\t Invalid position!!");
	}
	else
	{
		if(pos==1)
		{
			start=tmp->link;
			free(tmp);
			printf("\n\t\t After deletion:---\n");
			display(start);
		}
		if(pos==n)
		{
			while(tmp->link->link!=NULL)
			{
				tmp=tmp->link;
			}
			free(tmp->link);
			tmp->link=NULL;
			printf("\n\t\t After deletion:---\n");
			display(start);
		}
		else
		{
			for(i=2;i<pos;i++)
			{
				tmp=tmp->link;
			}
			p=tmp->link->link;
			free(tmp->link);
			tmp->link=p;
			printf("\n\t\t After deletion:---\n");
			display(start);
		}
	}
	return start;
}
struct node *reverse(struct node *start)
{
	struct node *pre_node,*tmp,*next_node;
	pre_node=NULL;
	tmp=start;
	next_node=start;
	printf("\n\t\t Before deletion:---\n");
	display(start);
	while(tmp!=NULL)
	{
		next_node=tmp->link;
		tmp->link=pre_node;
		pre_node=tmp;
		tmp=next_node;
	}
	start=pre_node;
	printf("\n\t\t After deletion:---\n");
	display(start);
	return start;
}
struct node *sort_data(struct node *start)
{
	struct node *tmp,*p;
	int n,i,j,a;
	printf("\n\t\t Before sort:---\n");
	display(start);
	tmp=start;
	p=NULL;
	while(tmp!=NULL)
	{
		p=tmp->link;
		while(p!=NULL)
		{
			if(tmp->info>p->info)
			{
				a=tmp->info;
				tmp->info=p->info;
				p->info=a;
			}
			p=p->link;
		}
		tmp=tmp->link;
	}
	printf("\n\t\t After sort:---\n");
	display(start);
}
struct node *sort_insert(struct node *start)
{
	struct node *tmp,*newnode;
	int data,n,i;
	printf("\n\t\t Enter the number of nodes: ");
	scanf("%d",&n);
	start=NULL;
	for(i=1;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\n\t\t Enter element: ");
		scanf("%d",&data);
		newnode->info=data;
	if(start==NULL||data<start->info)
	{
		newnode->link=start;
		start=tmp=newnode;
	}
	else
	{
		while(tmp->link!=NULL && tmp->link->info<data)
		{
			tmp=tmp->link;
		}
		newnode->link=tmp->link;
		tmp->link=newnode;
	}
	}
	display(start);
	return start;
}

