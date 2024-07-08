//N-QUEEN PROBLEM
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 50
void n_queen(int,int);
int place(int,int);
void display(int);
int array[MAX],c=0,call=1;
int main()
{
	int n;
	printf("\n\t\t Enter the number of queens: ");
	scanf("%d",&n);
	n_queen(1,n);
}
void n_queen(int k,int column)
{
	int i,g,r=0;
	/*printf("\n\nn_queen(%d,%d)--> (Call %d)\n\n",k,column,call++);
	getch();*/
	for(i=1;i<=column;i++)
	{
		/*printf("\ni=%d\n",i);
		printf("place(%d,%d)= %d\n",k,i,place(k,i));
		getch();*/
		if(place(k,i)==1)
		{
			array[k]=i;
			/*printf("\nAs place(%d,%d) return 1 so array[%d]= %d\n",k,i,k,i);
			printf("\n");
			for(g=1;g<=k;g++){
				printf("| %d |",array[g]);
				r=1;
			}
			getch();
			printf("\n");*/
			if(k==column)
				display(column);
			else
				n_queen(k+1,column);
		}
		
	}
	/*if(r==1)
	printf("\n");
	if(i>column)
	{
		printf("\n **As i>column, that means this positions of the queens are not correct! It will retuen to the previous call\n");
	}*/
}
int place(int k,int i)
{
	int j;
	for(j=1;j<=k-1;j++)
	{
		if((array[j]==i) || abs(array[j]-i)==abs(j-k))
			return 0;
	}
	return 1;
}
void display(int n)
{
	int i,j;
	printf("\n\nSolution %d:----\n\n\t",++c);
	for(i=1;i<=n;i++)
	{
		printf("%d\t",i);
	}
	for(i=1;i<=n;i++)
	{
		printf("\n%d\t",i);
		for(j=1;j<=n;j++)
		{
			if(j==array[i])
				printf("Q\t");
			else
				printf("-\t");
		}
	}
	printf("\n\n");
}
