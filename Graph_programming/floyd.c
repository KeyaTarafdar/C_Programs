//FLOYD'S ALGORITHM
#include<stdio.h>
#define MAX 20
void floyd(int graph[MAX][MAX],int n);
int d[MAX][MAX];
int main()
{
	int n,i,j,graph[MAX][MAX],s;
	printf("\nEnter the number of nodes: ");
	scanf("%d",&n);
	printf("\n\nEnter the weightages of the edges:----(IF THERE DOESN'T EXIT ANY EDGE, ENTER 0)\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			//printf("\nEnter the weight of the edge between %d and %d: ",i,j);
			scanf("%d",&graph[i][j]);
			if(graph[i][j]==0 && i!=j)
			{
				graph[i][j]=9999;
			}
		}
	}
	floyd(graph,n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void floyd(int graph[MAX][MAX],int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			d[i][j]=graph[i][j];
		}
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((i!=k && j!=k) && (d[i][j]>d[i][k]+d[k][j]))
				{
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
}
