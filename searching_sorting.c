#include<stdio.h>
#include<stdlib.h>
#define Max 100
int a[Max];
int create();
void display(int);
int insertion_pos(int);
int insertion_data(int);
int delet_pos(int);
int delet_data(int);
void linear_search(int);
void binary_search(int);
void reverse(int);
void bubble_sort(int);
void selection_sort(int);
void insertion_sort(int);
void merge_sort(int,int);
void merge(int,int,int);
void quick_sort(int,int);
int main()
{
	int ch,chh,chhh,chhhh,chhhhh,n,valid=0;
	while(1)
	{
		system("CLS");
		printf("\n\t\t 1) Exit\n\t\t 2) Create\n\t\t 3) Display\n\t\t 4) Insertion\n\t\t 5) Deletion\n\t\t 6) Searching\n\t\t 7) Reverse\n\t\t 8) Sorting");
		printf("\n\n\t\t Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				exit(0);
			case 2:
				if(valid==0)
				{
					n=create();
					valid=1;
				}
				else
				printf("Array is alredy created!");
				fflush(stdin);
				getchar();
				break;
			case 3:
				if(valid==1)
				display(n);
				else
				printf("\n\t\t Array is not created!!");
				fflush(stdin);
				getchar();
				break;
			case 4:
				if(valid==0)
				printf("\n\t\t Array is not created!!");
				else
				{
					printf("\n\t\t 1) Insertion_pos\n\t\t 2) Insertion_data");
					printf("\n\n\t\t Enter your choice: ");
					scanf("%d",&chh);
					switch(chh)
					{
						case 1:
							n=insertion_pos(n);
							break;
						case 2:
							n=insertion_data(n);
							break;
						default:
							printf("\n\t\t Wrong choice!!");
					}
				}
				fflush(stdin);
				getchar();
				break;
			case 5:
				if(valid==0)
				printf("\n\t\t Array is not created!!");
				else
				{
					printf("\n\t\t 1) Deletion_pos\n\t\t 2) Deletion_data");
					printf("\n\n\t\t Enter your choice: ");
					scanf("%d",&chhh);
					switch(chhh)
					{
						case 1:
							n=delet_pos(n);
							break;
						case 2:
							n=delet_data(n);
							break;
						default:
							printf("\n\t\t Wrong choice!!");
					}
				}
				fflush(stdin);
				getchar();
				break;
			case 6:
				if(valid==0)
				printf("\n\t\t Array is not created!!");
				else
				{
					printf("\n\t\t 1) Linear Search\n\t\t 2) Binary Search");
					printf("\n\n\t\t Enter your choice: ");
					scanf("%d",&chhhh);
					switch(chhhh)
					{
						case 1:
							linear_search(n);
							break;
						case 2:
							binary_search(n);
							break;
						default:
							printf("\n\t\t Wrong choice!!");
					}
				}
				fflush(stdin);
				getchar();
				break;
			case 7:
				if(valid==0)
				printf("\n\t\t Array is not created!!");
				else
				{
					reverse(n);
				}
				fflush(stdin);
				getchar();
				break;
			case 8:
				if(valid==0)
				printf("\n\t\t Array is not created!!");
				else
				{
					printf("\n\t\t 1) Bubble Sort\n\t\t 2) Selection Sort\n\t\t 3) Insertion Sort\n\t\t 4) Merge Sort\n\t\t 5) Quick Sort");
					printf("\n\n\t\t Enter your choice: ");
					scanf("%d",&chhhhh);
					switch(chhhhh)
					{
						case 1:
							bubble_sort(n);
							break;
						case 2:
							selection_sort(n);
							break;
						case 3:
							insertion_sort(n);
							break;
						case 4:
							merge_sort(0,n-1);
							display(n);
							break;
						case 5:
							quick_sort(0,n-1);
							display(n);
							break;
						default:
							printf("\n\t\t Wrong choice!!");
					}
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
	return 0;
}
int create()
{
	int n,i;
	printf("\n\t\t Enter the n = ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    printf("\n\t\t Enter the elements %d : ",(i+1));
		scanf("%d",&a[i]);
	}
	printf("\n\t\t!! Array is created !!\n");
	return n;
}
void display(int n)
{
	int i;
	if(n>0)
	{
		printf("\n\t\t Your array is: ");
		for(i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}
	}
	else
	printf("\n\t\t Array is empty!");
}
int insertion_pos(int n)
{
	int data,loc,i;
	printf("\n\t\t Enter the position: ");
	scanf("%d",&loc);
	if(loc>n+1)
	{
		printf("\n\t\t Invalid location!");
	}
	else
	{
		printf("\n\t\t Enter the data: ");
		scanf("%d",&data);
		for(i=n-1;i>=loc-1;i--)
		{
			a[i+1]=a[i];
		}
		a[i+1]=data;
		n++;
		display(n);
	}
	return n;
}
int insertion_data(int n)
{
	int data,i,loc,flag=0;
	printf("\n\t\t Enter the data after which to insert: ");
	scanf("%d",&data);
	for(i=0;i<n;i++)
	{
		if(a[i]==data)
		{
			loc=i;
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("\n\t\t Enter the data: ");
		scanf("%d",&data);
		for(i=n-1;i>loc;i--)
		{
			a[i+1]=a[i];
		}
		a[i+1]=data;
		n++;
		display(n);
	}
	else
	{
		printf("\n\t\t Data is not present in the array!");
	}
	return n;
}
int delet_pos(int n)
{
	int i,loc;
	printf("\n\t\t Enter the location to be deleted: ");
	scanf("%d",&loc);
	if(loc>n)
	{
		printf("\n\t\t Invalid position!!");
	}
	else
	{
		for(i=loc-1;i<n;i++)
		{
			a[i]=a[i+1];
		}
		n--;
		display(n);
	}
	return n;
}
int delet_data(int n)
{
	int i,flag,loc,data;
	printf("\n\t\t Enter the data: ");
	scanf("%d",&data);
	for(i=0;i<n;i++)
	{
		if(a[i]==data)
		{
			loc=i;
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		for(i=loc;i<n;i++)
		{
			a[i]=a[i+1];
		}
		n--;
		display(n);
	}
	else
	{
		printf("\n\t\t Data is not present in the array!");
	}
	return n;
}
void binary_search(int n)
{
	int mid,lb=0,ub=n-1,data,flag=0;
	printf("\n\t\t Enter the data to be searched: ");
	scanf("%d",&data);
	while(lb<ub)
	{
		mid=(lb+ub)/2;
		if(data==a[mid])
		{
			printf("\n\t\t Data is present at %d position",mid+1);
			flag=1;
			break;
		}
		if(data<a[mid])
		{
			ub=mid-1;
		}
		else if(data>a[mid])
		{
			lb=mid+1;
		}
	}
	if(flag==0 && lb>ub)
	{
		printf("\n\t\t Unsuccessful search!");
	}
}
void linear_search(int n)
{
	int data,flag=0,i,loc,x=0;
	printf("\n\t\t Enter the data to be searched: ");
	scanf("%d",&data);
	for(i=0;i<n;i++)
	{
		if(data==a[i])
		{
			loc=i;
			if(x==0)
			{
				printf("\n\t\t Data is present at position ",loc+1);
				x=1;
			}
			printf("%d, ",loc+1);
			flag=1;
		}
	}
	printf("\b\b ");
	if(flag==0)
	{
		printf("\n\t\t Unsuccessful search!");
	}
}
void reverse(int n)
{
	int i,tmp;
	for(i=0;i<n/2;i++)
	{
		tmp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=tmp;
	}
	display(n);
}
void bubble_sort(int n)
{
	int i,j,tmp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	display(n);
}
void selection_sort(int n)
{
	int min,i=0,tmp,j;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			tmp=a[i];
			a[i]=a[min];
			a[min]=tmp;
		}
	}
	display(n);
}
void insertion_sort(int n)
{
	int i,tmp,j;
	for(i=1;i<n;i++)
	{
		tmp=a[i];
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>tmp)
			{
				a[j+1]=a[j];
				a[j]=tmp;
			}
		}
	}
	display(n);
}
void merge_sort(int lb,int ub)
{
	int mid;
	mid=(lb+ub)/2;
	if(lb!=ub)
	{
		merge_sort(lb,mid);
		merge_sort(mid+1,ub);
		merge(lb,mid,ub);
	}
}
void merge(int lb,int mid,int ub)
{
	int b[Max];
	int i=lb,j=mid+1,k=lb;
	while(i<=mid && j<=ub)
	{
		if(a[i]<=a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	if(i>mid)
	{
		while(j<=ub)
		{
			b[k++]=a[j++];
		}
	}
	if(j>ub)
	{
		while(i<=mid)
		{
			b[k++]=a[i++];
		}
	}
	for(k=lb;k<=ub;k++)
	{
		a[k]=b[k];
	}
}
void quick_sort(int lb,int ub)
{
	int pivot,start=lb+1,end=ub,tmp,i=1;
	pivot=lb;
	while(start<=end)
	{
		while(a[start]<=a[pivot] && start<ub)
		{
			start++;
		}
		while(a[end]>a[pivot] && end>lb)
		{
			end--;
		}
		if(start<end)
		{
			tmp=a[start];
			a[start]=a[end];
			a[end]=tmp;
		}
	}
	tmp=a[end];
	a[end]=a[pivot];
	a[pivot]=tmp;
	if(0<end && start!=end)
	{
		quick_sort(0,end);
	}
	if(start<ub && start!=end)
	{
		quick_sort(start,ub);
	}
}
