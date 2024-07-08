//HEAP TREE
#include<stdio.h>
#define MAX 20
void swap(int a,int b);
int insert(int tree[],int n);
void heap_insert(int tree[],int i,int n);
int deletion(int tree[],int n);
void heap_delete(int tree[],int i,int n);
void heap_sort(int tree[],int n);
void swap(int a,int b);
int main()
{
	int n,i,tree[MAX]={0};
	printf("\nEnter the no. of nodes: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&tree[i]);
		/*if(i==1)
		{
			printf("\n\nEnter the root node: ");
			scanf("%d",&tree[i]);
		}
		else 
		{
			if(tree[n]==0)
			{
			printf("\nEnter the left child of %d: ",tree[i-1]);
			scanf("%d",&tree[2*(i-1)]);
			}
			if(tree[n]==0)
			{
			printf("\nEnter the right child of %d: ",tree[i-1]);
			scanf("%d",&tree[(2*(i-1))]+1);
			}
		}*/
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("%d | ",tree[i]);
	}
	//n=insert(tree,n);
	//n=deletion(tree,n);
	heap_sort(tree,n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("%d | ",tree[i]);
	}
}
int insert(int tree[],int n)
{
	int data,i;
	printf("\n\n\nEnter the data to be inserted: ");
	scanf("%d",&data);
	n++;
	tree[n]=data;
	heap_insert(tree,n,n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("%d | ",tree[i]);
	}
	return n;
}
void heap_insert(int tree[],int i,int n)
{
	int j;
	if(tree[i]>tree[i/2] && i>0)
	{
		j=tree[i];
		tree[i]=tree[i/2];
		tree[i/2]=j;
		i=i/2;
		heap_insert(tree,i,n);
	}
}
int deletion(int tree[],int n)
{
	int data,i;
	printf("\n\n\nEnter the element to be deleted: ");
	scanf("%d",&data);
	for(i=1;i<=n;i++)
	{
		if(tree[i]==data)
		{
			tree[i]=tree[n];
			n--;
			break;
		}
	}
	heap_delete(tree,i,n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("%d | ",tree[i]);
	}
	return n;
}
void heap_delete(int tree[],int i,int n)
{
	int tmp;
	if((tree[i]<tree[2*i] || tree[i]<tree[(2*i)+1]) && (((2*i)<=n) || ((2*i)+1)<=n))
	{
		if(tree[2*i]>tree[(2*i)+1] || (2*i)==n)
		{
			tmp=tree[2*i];
			tree[2*i]=tree[i];
			tree[i]=tmp;
			i=2*i;
		}
		else
		{
			tmp=tree[(2*i)+1];
			tree[(2*i)+1]=tree[i];
			tree[i]=tmp;
			i=(2*i)+1;
		}
		heap_delete(tree,i,n);
	}
}
void heap_sort(int tree[],int n)
{
	int i,tmp;
	heapify(tree,n,1);
	for(i=n;i>=1;i--)
	{
		tmp=tree[n];
		tree[n]=tree[1];
		tree[1]=tmp;
		n--;
		heapify(tree,n,1);
	}
}
void heapify(int a[],int n,int i)
{
	int tmp,large=i,l=2*i,r=2*i+1;
	if(l<=n && a[l]>a[large])
	{
		large=l;
	}
	if(r<=n && a[r]>a[large])
	{
		large=r;
	}
	if(large!=i)
	{
		tmp=a[i];
		a[i]=a[large];
		a[large]=tmp;
		heapify(a,n,large);
	}
}
