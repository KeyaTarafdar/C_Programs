//KNAPSACK PROBLEM
#include<stdio.h>
#include<stdlib.h>
struct node{
	int item_no;
	int weight;
	float profit;
	float pi;
};
int j=0;
//void sort(struct node *,int);
void merge_sort(int,int,struct node *);
void merge(int,int,int,struct node *);
float knapsack(struct node *,struct node *,int ,int);
int main()
{
	struct node *bag,*final_bag;
	int n,i,max,capacity;
	float profit;
	printf("\n\t\t Enter the total number of objects: ");
	scanf("%d",&n);
	bag=(struct node *)malloc(n*(sizeof(struct node)));
	for(i=0;i<n;i++)
	{
		printf("\n\n\t\t %d. Enter the Item No, Item Weight & Item Profit: ",i+1);
		scanf("%d%d%f",&bag[i].item_no,&bag[i].weight,&bag[i].profit);
		bag[i].pi=bag[i].profit/bag[i].weight;
	}
	printf("\n\t\t Enter the capacity of the final bag is: ");
	scanf("%d",&capacity);
	merge_sort(0,n-1,bag);
	/*for(i=0;i<n;i++)
	{
		printf("\n\n\t\t %d. Enter the Item No, Item Weight & Item Profit: %d %d %.2f %.2f",i+1,bag[i].item_no,bag[i].weight,bag[i].profit,bag[i].pi);
	}*/
	final_bag=(struct node *)malloc(n*sizeof(struct node));
	profit=knapsack(final_bag,bag,n,capacity);
	printf("\n\n\t Final Bag is:---\n\n");
	printf("\n\n\t Item No.\t Weight\t\t Profit\n");
	for(i=0;i<=j;i++)
	{
		printf("\t %d\t\t %d\t\t %.2f\n",final_bag[i].item_no,final_bag[i].weight,final_bag[i].profit);
	}
	printf("\n\n\t\t Max profit: %.2f",profit);
	free(bag);
	free(final_bag);
}
void merge_sort(int lb,int ub,struct node *bag)
{
	int mid;
	mid=(lb+ub)/2;
	if(lb<ub)
	{
		merge_sort(lb,mid,bag);
		merge_sort(mid+1,ub,bag);
		merge(lb,mid,ub,bag);
	}
}
void merge(int lb,int mid,int ub,struct node *bag)
{
	int i=lb,j=mid+1,k=lb;
	struct node *array;
	array=(struct node *)malloc((ub+1)*(sizeof(struct node)));
	while(i<=mid && j<=ub)
	{
		if(bag[i].pi>bag[j].pi)
		{
			array[k].item_no=bag[i].item_no;
			array[k].weight=bag[i].weight;
			array[k].profit=bag[i].profit;
			array[k].pi=bag[i].pi;
			i++;
			k++;
		}
		else
		{
			array[k].item_no=bag[j].item_no;
			array[k].weight=bag[j].weight;
			array[k].profit=bag[j].profit;
			array[k].pi=bag[j].pi;
			k++;
			j++;
		}
	}
	while(i>mid && j<=ub)
	{
		array[k].item_no=bag[j].item_no;
		array[k].weight=bag[j].weight;
		array[k].profit=bag[j].profit;
		array[k].pi=bag[j].pi;
		k++;
		j++;
	}
	while(j>ub && i<=mid)
	{
		array[k].item_no=bag[i].item_no;
		array[k].weight=bag[i].weight;
		array[k].profit=bag[i].profit;
		array[k].pi=bag[i].pi;
		i++;
		k++;
	}
	for(i=lb;i<=ub;i++)
	{
		bag[i].item_no=array[i].item_no;
		bag[i].weight=array[i].weight;
		bag[i].profit=array[i].profit;
		bag[i].pi=array[i].pi;
	}
	free(array);
}
float knapsack(struct node *final_bag,struct node *bag,int n,int capacity)
{
	int i=0;
	float profit=0.0;
	for(i=0;i<n;i++)
	{
		if(bag[i].weight<=capacity)
		{
			final_bag[j].weight=bag[i].weight;
			final_bag[j].profit=bag[i].profit;
			final_bag[j].item_no=bag[i].item_no;
			profit=profit+final_bag[i].profit;
			capacity=capacity-bag[i].weight;
			printf("\n\n\t\t Weight %d is loading in the bag... Remaing Weight is %d",bag[i].weight,capacity);
			printf("\n\t\t Enter to proceed...");
			getch();
			j++;
		}
		else
		{
			final_bag[j].profit=(bag[i].profit*(bag[i].weight-(bag[i].weight-capacity)))/(bag[i].weight);
			profit=profit+final_bag[i].profit;
			final_bag[j].weight=bag[i].weight-(bag[i].weight-capacity);
			final_bag[j].item_no=bag[i].item_no;
			printf("\n\n\t\t The fraction part of %d Kg weight, %d Kg is loading...",bag[i].weight,final_bag[i].weight);
			printf("\n\t\t Enter to proceed...");
			getch();
			return profit;
		}
	}
}