//BELLMAN-FORD ALGORITHM
#include<stdio.h>
#define MAX 20
void bellman_ford(int graph[MAX][MAX],int n,int s);
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
			printf("\nEnter the weight of the edge between %d and %d: ",i,j);
			scanf("%d",&graph[i][j]);
			if(graph[i][j]==0 && i!=j)
				graph[i][j]=999;
		}
	}
	printf("\nEnter the starting vertex: ");
	scanf("%d",&s);
	bellman_ford(graph,n,s);
	return 0;
}
void bellman_ford(int graph[MAX][MAX],int n,int s)
{
	int d[MAX],i,u,v,j,k,c;
	for(i=1;i<=n;i++)
	{
		d[i]=999;
	}
	d[s]=0;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n;j++)
		{
			u=j;
			for(k=1;k<=n;k++)
			{
				if(graph[j][k]!=999 && graph[j][k]!=0)
				{
					v=k;
					if(d[u]+graph[u][v]<d[v])
					{
						d[v]=d[u]+graph[u][v];
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("\n%d---> %d : %d",s,i,d[i]);
	}
}
