//CIRCULAR LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *create(struct node *last);
void display(struct node *last);
struct node *insert_beg(struct node *last, int data);
struct node *insert_end(struct node *last, int data);
struct node *insert_after(struct node *last,int data);
struct node *insert_before(struct node *last,int data);
struct node *insert_pos(struct node *last, int data);
int count_node(struct node *last);
void search(struct node *last,int data);
struct node *del_beg(struct node *last);
struct node *del_end(struct node *last);
struct node *del_data(struct node *last,int data);
struct node *del_pos(struct node *last);
struct node *reverse(struct node *last);
struct node *sort_data(struct node *last);
struct node *sort_insert(struct node *last);
void main()
{
	int ch,chh,valid=0,data,chhh,i,n;
	struct node *last=NULL;
	while(1)
	{
		system("CLS");
		printf("\n\t\t\t\t *****CIRCULAR LINKED LIST OPERATIONS****");
		printf("\n\n\t\t\t\t\t 0) Exit");
		printf("\n\t\t\t\t\t 1) Create");
		printf("\n\t\t\t\t\t 2) Display");
		printf("\n\t\t\t\t\t 3) Insertion");
		printf("\n\t\t\t\t\t 4) Count node");
		printf("\n\t\t\t\t\t 5) Search");
		printf("\n\t\t\t\t\t 6) Deletion");
		printf("\n\t\t\t\t\t 7) Reverse");
		printf("\n\t\t\t\t\t 8) Sort_data");
		printf("\n\t\t\t\t\t 9) Sort_insert");
		printf("\n\n\t\t\t\t Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(0);
			case 1:
				if(valid==0)
				{
					last=create(last);
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
					display(last);
				}
				else
				{
					printf("\n\t\t The linked list is not created!!");
				}
				fflush(stdin);
				getchar();
				break;
			case 3:
				if(valid==1)
				{
					printf("\n\t\t\t\t 1) Insert_beg");
					printf("\n\t\t\t\t 2) Insert_end");
					printf("\n\t\t\t\t 3) Insert_after");
					printf("\n\t\t\t\t 4) Insert_before");
					printf("\n\t\t\t\t 5) Insert_position");
					printf("\n\n\t\t\t Enter your choice: ");
					scanf("%d",&chh);
					switch(chh)
					{
						case 1:
							last=insert_beg(last,data);
							break;
						case 2:
							last=insert_end(last,data);
							break;
						case 3:
							last=insert_after(last,data);
							break;
						case 4:
							last=insert_before(last,data);
							break;
						case 5:
							last=insert_pos(last,data);
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
			case 4:
				if(valid==1)
				{
					n=count_node(last);
					printf("\n\t\t The number of nodes: %d",n);
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
					search(last,data);
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
					printf("\n\t\t\t\t 1) Delete from beginning");
					printf("\n\t\t\t\t 2) Delete from end");
					printf("\n\t\t\t\t 3) Delete_by_element");
					printf("\n\t\t\t\t 4) Delete_by_position");
					printf("\n\n\t\t\t Enter your choice: ");
					scanf("%d",&chhh);
					switch(chhh)
					{
						case 1:
							last=del_beg(last);
							break;
						case 2:
							last=del_end(last);
							break;
						case 3:
							last=del_data(last,data);
							break;
						case 4:
							last=del_pos(last);
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
					last=reverse(last);
				}
				else
				{
					printf("\n\t\t The linkde list is not created!!");
				}
				fflush(stdin);
				getchar();
				break;
			case 8:
				if(valid==1)
				{
					last=sort_data(last);
				}
				else
				{
					printf("\n\t\t The linked list is not created!!");
				}
				fflush(stdin);
				getchar();
				break;
			case 9:
				last=sort_insert(last);
				display(last);
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
struct node *create(struct node *last)
{
	int i,n;
	struct node *newnode,*tmp,*p;
	last=NULL;
	printf("\n\t\t Enter the no of nodes: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\n\t\t Enter element %d: ",i);
		scanf("%d",&newnode->info);
		if(last==NULL)
		{
			last=newnode;
			newnode->link=newnode;
		}
		else
		{
			tmp=last->link;
			while(tmp!=last)
			{
				tmp=tmp->link;
			}
			newnode->link=last->link;
			tmp->link=newnode;
			last=newnode;
		}
	}
	printf("\n\t\t **The linked list is successfully created**");
	return last;
}
void display(struct node *last)
{
	struct node *tmp;
	if(last==NULL)
	{
		printf("\n\t\t\t Last---> NULL");
		printf("\n\n\t\t The list is empty!!");
	}
	else
	{
	tmp=last->link;
	printf("\n\t\t Your linked list is:---\n\n");
	do
	{
		printf("\n\t\t||%u| %d |%u|| ",tmp,tmp->info,tmp->link);
		tmp=tmp->link;
	}while(tmp!=last->link);
	printf("<-- %d | last",last);
}
}
struct node *insert_beg(struct node *last, int data)
{
	struct node *newnode,*p;
	printf("\n\t\t Before insertion:---\n");
	display(last);
	printf("\n\n\t\t Enter the data will be inserted: ");
	scanf("%d",&data);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=data;
	newnode->link=last->link;
	last->link=newnode;
	printf("\n\n\t\t After insertion:---\n");
	display(last);
	return last;
}
struct node *insert_end(struct node *last, int data)
{
	struct node *newnode,*tmp;
	printf("\n\t\t Berore insertion:---");
	display(last);
	printf("\n\n\t\t Enter the data will be inserted: ");
	scanf("%d",&data);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=data;
	newnode->link=last->link;
	last->link=newnode;
	last=newnode;
	printf("\n\n\t\t After insertion:---\n");
	display(last);
	return last;
}
struct node *insert_after(struct node *last,int data)
{
	struct node *newnode,*tmp,*p;
	int item;
	tmp=last->link;
	printf("\n\t\t Before insertion:---\n");
	display(last);
	printf("\n\n\t\t Enter the item after which the element will be inserted: ");
	scanf("%d",&item);
	if(item==last->info)
	{
		printf("\n\t\t Enter the data will be inserted: ");
		scanf("%d",&data);
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->info=data;
		newnode->link=last->link;
		last->link=newnode;
		last=newnode;
		printf("\n\n\t\t After insertion:---\n");
		display(last);
	}
	else
	{
		while(tmp->info!=item && tmp!=last)
		{
			tmp=tmp->link;
		}
		if(tmp==last && tmp->info!=item)
		{
			printf("\n\t\t\t The item is not present in the list!!");
		}
		else
		{
			printf("\n\t\t Enter the data will be inserted: ");
			scanf("%d",&data);
			newnode=(struct node *)malloc(sizeof(struct node));
			newnode->info=data;
			p=tmp->link;
			tmp->link=newnode;
			newnode->link=p;
			printf("\n\n\t\t After insertion:---\n");
			display(last);
		}
	}
	return last;
}
struct node *insert_before(struct node *last,int data)
{
	struct node *newnode,*tmp,*p;
	int item;
	tmp=last->link;
	printf("\n\t\t Before insertion:---\n");
	display(last);
	printf("\n\n\t\t Enter the item before which the element will be inserted: ");
	scanf("%d",&item);
	newnode=(struct node *)malloc(sizeof(struct node));
	if(item==last->link->info)
	{
		printf("\n\t\t Enter the data will be inserted: ");
		scanf("%d",&data);
		newnode->info=data;
		newnode->link=last->link;
		last->link=newnode;
		printf("\n\n\t\t After insertion:---\n");
		display(last);
	}
	else if(item==last->info)
	{
		printf("\n\t\t Enter the data will be inserted: ");
		scanf("%d",&data);
		newnode->info=data;
		tmp=last->link;
		while(tmp->link->info!=item)
		{
			tmp=tmp->link;
		}
		newnode->link=tmp->link;
		tmp->link=newnode;
		printf("\n\n\t\t After insertion:---\n");
		display(last);
	}
	else
	{
		while(tmp->link->info!=item && tmp!=last)
		{
			tmp=tmp->link;
		}
		if(tmp==last)
		{
			printf("\n\t\t\t The item is not present in the list!!");
		}
		else
		{
			printf("\n\t\t Enter the data will be inserted: ");
			scanf("%d",&data);
			newnode->info=data;
			p=tmp->link;
			tmp->link=newnode;
			newnode->link=p;
			printf("\n\n\t\t After insertion:---\n");
			display(last);
		}
	}
	return last;
}
struct node *insert_pos(struct node *last, int data)
{
	struct node *newnode,*tmp,*p;
	int pos,i,n;
	printf("\n\t\t Before insertion:---\n");
	display(last);
	printf("\n");
	n=count_node(last);
	printf("\n\n\t\t Enter the position where the element will be inserted: ");
	scanf("%d",&pos);
	if(pos>n+1)
	{
		printf("\n\t\t\t Invalid Position!!");
	}
	else
	{
		printf("\n\t\t Enter the data will be inserted: ");
		scanf("%d",&data);
		if(pos==1)
		{
			newnode=(struct node *)malloc(sizeof(struct node));
			newnode->info=data;
			newnode->link=last->link;
			last->link=newnode;
		}
		else
		{
			newnode=(struct node *)malloc(sizeof(struct node));
			newnode->info=data;
			tmp=last->link->link;
			if(pos==n+1)
			{
				newnode->link=last->link;
				last->link=newnode;
				last=newnode;
			}
			else
			{
				for(i=2;i<pos-1;i++)
				{
					tmp=tmp->link;
				}
				newnode->link=tmp->link;
				tmp->link=newnode;
			}
		}
		printf("\n\n\t\t After insertion:---\n");
		display(last);
	}
	return last;
}
int count_node(struct node *last)
{
	struct node *tmp;
	int i=0;
	if(last==NULL)
	i=0;
	else
	{
		tmp=last->link;
		while(tmp!=last)
		{
			i++;
			tmp=tmp->link;
		}
		if(tmp==last)
		{
			i++;
		}
	}
	return i;
}
void search(struct node *last,int data)
{
	int a=0,i=1;
	struct node *tmp;
	if(last==NULL)
	{
		printf("\n\t\t\t The list is empty!!");
		printf("\n\n\t\t No data is present in the list to be searched!!");
	}
	else
	{
		printf("\n\t\t Enter the element to be searched: ");
		scanf("%d",&data);	
		tmp=last->link;
		while(tmp!=last)
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
		if(tmp==last && tmp->info==data)
		{
			if(a==0)
			{
				printf("\n\t\t The data in present in node: ");
				a=1;
			}
			printf("%d",i);
		}
		if(a==0)
		{
			printf("\n\t\t Element is not present in the list!!");
		}
	}
}
struct node *del_beg(struct node *last)
{
	int n;
	struct node *p;
	n=count_node(last);
	if(last==NULL)
	{
		printf("\n\t\t The list is empty!!");
	}
	else
	{
		printf("\n\t\t Before deletion:---\n");
		display(last);
		if(n==1)
		{
			free(last);
			last=NULL;
		}
		else
		{
			p=last->link;
			last->link=p->link;
			free(p);
		}
		printf("\n\n\t\t After deletion:---\n");
		display(last);
	}
	return last;
}
struct node *del_end(struct node *last)
{
	int n;
	struct node *tmp,*p;
	n=count_node(last);
	if(last==NULL)
	{
		printf("\n\t\t The list is empty!!");
	}
	else
	{
		printf("\n\t\t Before deletion:---\n");
		display(last);
		if(n==1)
		{
			free(last);
			last=NULL;
		}
		else
		{
			tmp=last->link;
			while(tmp->link!=last)
			{
				tmp=tmp->link;
			}
			p=tmp->link;
			tmp->link=p->link;
			last=tmp;
			free(p);
		}
		printf("\n\n\t\t After deletion:---\n");
		display(last);
	}
	return last;
}
struct node *del_data(struct node *last,int data)
{
	struct node *tmp,*p,*pt;
	int a=0,n;
	if(last==NULL)
	{
		printf("\n\t\t The list is empty!!");
	}
	else
	{
		n=count_node(last);
		printf("\n\t\t Before deletion:---\n");
		display(last);
		printf("\n\n\t\t Enter the data which will be deleted: ");
		scanf("%d",&data);
		tmp=last->link;
		if(n==1 && last->info==data)
		{
			free(last);
			last=NULL;
			a=1;
		}
		else
		{
			while(tmp!=last)
			{
				if(tmp->info==data)
				{
					a=1;
					break;
				}
				else
				{
					p=tmp;
					tmp=tmp->link;
				}
			}
			if(tmp==last->link && last->link->info==data)
			{
				p=tmp;
				last->link=tmp->link;
				free(p);
			}
			else if(tmp==last && last->info==data && a==1)
			{
				pt=tmp;
				p->link=tmp->link;
				last=p;
				free(pt);
			}
			else if(a==1)
			{
				p->link=tmp->link;
				free(tmp);
			}
		}
		if(a==0)
		{
			printf("\n\t\t The element is not present in the list!!");
		}
		else
		{
			printf("\n\n\t\t After deletion:---\n");
			display(last);
		}
	}
	return last;
}
struct node *del_pos(struct node *last)
{
	int n,i,pos;
	struct node *tmp,*p;
	if(last==NULL)
	{
		printf("\n\t\t The list is empty!!");
	}
	else
	{
		printf("\n\t\t Before deletion:---\n");
		display(last);
		n=count_node(last);
		printf("\n\n\t\t Enter the position from where the data will be delted: ");
		scanf("%d",&pos);
		tmp=last->link;
		if(pos>n)
		{
			printf("\n\t\t Position is out of nodes!!");
		}
		else
		{
			if(n==1)
			{
				free(last);
				last=NULL;
				printf("\n\t\t After deletion:---\n");
				display(last);
			}
			else if(pos==1)
			{
				p=last->link;
				last->link=p->link;
				free(p);
				printf("\n\t\t After deletion:---\n");
				display(last);
			}
			else if(pos==n)
			{
				while(tmp->link!=last)
				{
					tmp=tmp->link;
				}
				p=tmp->link;
				tmp->link=p->link;
				last=tmp;
				free(p);
				printf("\n\t\t After deletion:---\n");
				display(last);
			}
			else
			{
				for(i=1;i<pos-1;i++)
				{
					tmp=tmp->link;
				}
				p=tmp->link;
				tmp->link=p->link;
				free(p);
				printf("\n\t\t After deletion:---\n");
				display(last);
			}
		}
	}
	return last;
}
struct node *reverse(struct node *last)
{
	struct node *pre_node,*tmp,*next_node;
	int n,i=1;
	if(last==NULL)
	{
		printf("\n\t\t\t The list is empty!!");
	}
	else
	{
		pre_node=last;
		tmp=last->link;
		n=count_node(last);
		printf("\n\t\t Before reverse:---\n");
		display(last);
		while(i<=n+1)
		{
			next_node=tmp->link;
			tmp->link=pre_node;
			pre_node=tmp;
			tmp=next_node;
			i++;
		}
		last=pre_node;
		printf("\n\t\t After reverse:---\n");
		display(last);
	}
	return last;
}
struct node *sort_data(struct node *last)
{
	struct node *tmp,*p;
	int n,i,j,a;
	printf("\n\t\t Before sort:---\n");
	display(last);
	tmp=last->link;
	while(tmp!=last)
	{
		p=tmp->link;
		while(p!=last->link)
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
	display(last);
}
struct node *sort_insert(struct node *last)
{
	int n,i,data;
	struct node *newnode,*tmp;
	printf("\n\t\t Enter n: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\n\t\t Enter data: ");
		scanf("%d",&data);
		newnode->info=data;
		if(last==NULL)
		{
			last=newnode;
			newnode->link=newnode;
		}
		else if(data>last->info)
		{
			newnode->link=last->link;
			last->link=newnode;
			last=newnode;
		}
		else
		{
			tmp=last;
			while(tmp->link->info<data)
			{
				tmp=tmp->link;
			}
			newnode->link=tmp->link;
			tmp->link=newnode;
		}
	}
	return last;
}
