//DOUBLE LINKED LIST OPERATION:-
#include<stdio.h>
#include<stdlib.h>
struct node *last=NULL;
struct node{
	int info;
	struct node *prev;
	struct node *next;
};
struct node *create(struct node *start);
void display(struct node *start);
struct node *insert_beg(struct node *start);
void insert_end(struct node *start);
void insert_after(struct node *start);
struct node *insert_before(struct node *start);
struct node *insert_pos(struct node *start);
int count_node(struct node *start);
struct node *del_data(struct node *start);
struct node *reverse(struct node *start);
struct node *insertion_sort(struct node *start);
void main()
{
	int ch,chh,valid=0,data,chhh,chhhh,i,n;
	struct node *start,*tmp;
	while(1)
	{
		system("CLS");
		printf("\n\t\t\t\t ------***DOUBLE LINKED LIST OPERATIONS***------\n");
		printf("\n\t\t\t\t\t 0) Exit");
		printf("\n\t\t\t\t\t 1) Create");
		printf("\n\t\t\t\t\t 2) Display");
		printf("\n\t\t\t\t\t 3) Insertion");
		printf("\n\t\t\t\t\t 4) Deletion");
		printf("\n\t\t\t\t\t 5) Reverse");
		printf("\n\t\t\t\t\t 6) Insertion Sort");
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
					printf("\n\n");
					printf("\t------------------------------------------------------------------------");
					printf("\n\n");
					printf("\tlast:%u--->\t",last);
					tmp=last;
					while(tmp!=NULL)
					{
						printf("|| %u | %d | %u || ",tmp->prev,tmp->info,tmp->next);
						tmp=tmp->prev;
						if(tmp!=NULL)
						{
							printf("\n\t\t\t\t");
						}
					}
					printf("\b \t\t<---%u: start",start);
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
							start=insert_beg(start);
							break;
						case 2:
							insert_end(start);
							break;
						case 3:
							insert_after(start);
							break;
						case 4:
							start=insert_before(start);
							break;
						case 5:
							start=insert_pos(start);
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
			/*case 4:
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
				break;*/
			case 4:
				if(valid==1)
				{
					start=del_data(start);
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
					start=reverse(start);
				}
				else
				{
					printf("\n\t\t The linked list is not created!!");
				}
				fflush(stdin);
				getchar();
				break;
			case 6:
				if(valid==0)
				{
					start=insertion_sort(start);
					display(start);
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
	struct node *newnode;
	int n,i;
	start=NULL;
	printf("\n\t\t Enter the number of nodes want to insert: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\n\t\t Enter element %d: ",i);
		scanf("%d",&newnode->info);
		if(start==NULL)
		{
			newnode->prev=NULL;
			newnode->next=NULL;
			start=newnode;
			last=newnode;
		}
		else
		{
			newnode->next=NULL;
			last->next=newnode;
			newnode->prev=last;
			last=newnode;
		}
	}
	return start;
}
void display(struct node *start)
{
	struct node *tmp;
	printf("\n\t\t Your linked list is:---\n\n");
	printf("\tstart:%u--->\t",start);
	tmp=start;
	while(tmp!=NULL)
	{
		printf("|| %u | %d | %u || ",tmp->prev,tmp->info,tmp->next);
		tmp=tmp->next;
		if(tmp!=NULL)
		{
			printf("\n\t\t\t\t");
		}
	}
	printf("\b \t\t<---%u: last",last);
}
struct node *insert_beg(struct node *start)
{
	struct node *newnode;
	printf("\n\t\t Before insertion:---\n");
	display(start);
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\n\n\t\t Enter the element to be inserted: ");
	scanf("%d",&newnode->info);
	newnode->next=start;
	start->prev=newnode;
	newnode->prev=NULL;
	start=newnode;
	printf("\n\n\t\t After insertion:---\n");
	display(start);
	return start;
}
void insert_end(struct node *start)
{
	struct node *newnode;
	printf("\n\t\t Before insertion:---\n");
	display(start);
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("\n\n\t\t Enter the element to be inserted: ");
	scanf("%d",&newnode->info);
	newnode->prev=last;
	last->next=newnode;
	newnode->next=NULL;
	last=newnode;
	printf("\n\n\t\t After insertion:---\n");
	display(start);
}
void insert_after(struct node *start)
{
	int item,a=1;
	struct node *tmp,*newnode;;
	printf("\n\t\t Before insertion:---\n");
	display(start);
	printf("\n\n\t\t Enter the item after which the element will be inserted: ");
	scanf("%d",&item);
	tmp=start;
	while(tmp!=NULL)
	{
		if(tmp->info==item)
		{
			newnode=(struct node *)malloc(sizeof(struct node));
			printf("\n\t\t Enter the element to be inserted : ");
			scanf("%d",&newnode->info);
			if(tmp==last)
			{
				tmp->next=newnode;
				newnode->prev=tmp;
				newnode->next=NULL;
				last=newnode;
			}
			else
			{
 				newnode->next=tmp->next;
	 			tmp->next->prev=newnode;
				tmp->next=newnode;
				newnode->prev=tmp;
			}
			break;
		}
		else
		{
			tmp=tmp->next;
		}
	}
	if(tmp==NULL)
	{
		printf("\n\t\t Element is not present in the list!!");
	}
	else
	{
		printf("\n\n\t\t After insertion:---\n");
		display(start);
	}
}
struct node *insert_before(struct node *start)
{
	struct node *tmp,*newnode;
	int item;
	printf("\n\t\t Before insertion:---\n");
	display(start);
	printf("\n\n\t\t Enter the item before which the element will be inserted: ");
	scanf("%d",&item);
	tmp=start;
	while(tmp!=NULL)
	{
		if(tmp->info==item)
		{
			newnode=(struct node *)malloc(sizeof(struct node));
			printf("\n\t\t Enter the element to be inserted: ");
			scanf("%d",&newnode->info);
			if(tmp==start)
			{
				newnode->prev=NULL;
				newnode->next=start;
				start=newnode;
			}
			else if(tmp==last)
			{
				newnode->next=tmp;
				newnode->prev=tmp->prev;
				tmp->prev->next=newnode;
				tmp->prev=newnode;
			}
			else
			{
				newnode->next=tmp;
				newnode->prev=tmp->prev;
				tmp->prev->next=newnode;
				tmp->prev=newnode;
			}
			break;
		}
		else
		{
			tmp=tmp->next;
		}
	}
	if(tmp==NULL)
	{
		printf("\n\t\t Element is not present in the list!!");
	}
	else
	{
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
		tmp=tmp->next;
	}
	printf("\n\t\t Number of nodes in list: %d",i);
	return i;
}
struct node *insert_pos(struct node *start)
{
	struct node *newnode,*tmp,*p;
	int pos,i,n;
	tmp=start;
	printf("\n\t\t Before insertion:---\n");
	display(start);
	printf("\n");
	n=count_node(start);
	printf("\n\n\t\t Enter the position where the element will be inserted: ");
	scanf("%d",&pos);
	if(pos>n+1)
	{
		printf("\n\t\t Invalid position!!");
	}
	else
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\n\t\t Enter the element to be inserted: ");
		scanf("%d",&newnode->info);
		newnode->next=NULL;
		if(pos==1)
		{
			newnode->next=start;
			start->prev=newnode;
			newnode->prev=NULL;
			start=newnode;
		}
		else if(pos==n+1)
		{
			newnode->prev=last;
			last->next=newnode;
			newnode->next=NULL;
			last=newnode;
		}
		else
		{
			for(i=1;i<pos-1;i++)
			{
				tmp=tmp->next;
			}
		newnode->next=tmp->next;
		tmp->next->prev=newnode;
		newnode->prev=tmp;
		tmp->next=newnode;
		}
		printf("\n\n\t\t After insertion:---\n");
		display(start);
	}
	return start;
}
struct node *del_data(struct node *start)
{
	struct node *tmp,*p;
	int data,a=0;
	printf("\n\t\t Before deletion:---\n");
	display(start);
	printf("\n\n\t\t Enter the data which will be deleted: ");
	scanf("%d",&data);
	if(data==start->info)
	{
		tmp=start;
		start->next->prev=NULL;
		start=tmp->next;
		free(tmp);
		a=1;
	}
	else if(data==last->info)
	{
		tmp=last;
		last->prev->next=NULL;
		last=last->prev;
		free(tmp);
		a=1;
	}
	else
	{
		tmp=start->next;
		while(tmp->next!=NULL)
		{
			if(tmp->info==data)
			{
				tmp->prev->next=tmp->next;
				tmp->next->prev=tmp->prev;
				free(tmp);
				a=1;
				break;
			}
			else
			{
				tmp=tmp->next;
			}
		}
	}
	if(a==0)
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
struct node *reverse(struct node *start)
{
	struct node *post,*tmp,*p;
	tmp=start;
	printf("\n\t\t Before deletion:---\n");
	display(start);
	while(tmp!=NULL)
	{
		post=tmp->next;
		p=tmp->prev;
		tmp->prev=tmp->next;
		tmp->next=p;
		if(tmp==start)
		{
			last=tmp;
		}
		if(tmp->prev==NULL)
		{
			start=tmp;
		}
		tmp=post;
	}
	printf("\n\t\t After deletion:---\n");
	display(start);
	return start;
}
struct node *insertion_sort(struct node *start)
{
	int n,i,data;
	struct node *newnode,*tmp;
	printf("\n\t\t Enter the number of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\n\t\t Enter data %d: ",i+1);
		scanf("%d",&data);
		newnode->info=data;
		if(last==NULL && start==NULL)
		{
			last=newnode;
			start=newnode;
			newnode->next=NULL;
			newnode->prev=NULL;
		}
		else if(data<start->info)
		{
			newnode->next=start;
			newnode->prev=NULL;
			start->prev=newnode;
			start=newnode;
		}
		else if(data>last->info)
		{
			newnode->next=NULL;
			newnode->prev=last;
			last->next=newnode;
			last=newnode;
		}
		else
		{
			tmp=start;
			while(tmp->info<data && tmp!=NULL)
			{
				tmp=tmp->next;
			}
			newnode->prev=tmp->prev;
			newnode->next=tmp;
			newnode->prev->next=newnode;
			tmp->prev=newnode;
		}
	}
	return start;
}
