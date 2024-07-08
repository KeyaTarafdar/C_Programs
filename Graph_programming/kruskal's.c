//KRUSKAL'S ALGORITHM
#include<stdio.h>
#define MAX 20
int find(int);
void uni(int,int);
void kruskal(int [MAX][MAX],int);
int parent[MAX]={0};
int main()
{
	int n,i,j,graph[MAX][MAX];
	printf("\nEnter the number of nodes: ");
	scanf("%d",&n);
	printf("\n\nEnter the cost matrix of the graph:----(IF THERE DOESN'T EXIT ANY EDGE, ENTER 0)\n\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			//printf("\nEnter the weight of the edge between %d and %d: ",i,j);
			scanf("%d",&graph[i][j]);
			if(graph[i][j]==0)
				graph[i][j]=999;
		}
	}
	printf("\nThe edges of Minimum cost of spanning tree are:---- \n");
	kruskal(graph,n);
	return 0;
}
void kruskal(int graph[MAX][MAX],int n)
{
	int a=0,b=0,u=0,v=0,ne=1,min,mincost=0,i,j;
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(graph[i][j]<min)
				{
					min=graph[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(u!=v)
		{
			//uni(u,v);
			parent[v]=u;
			printf("\n%d edge (%d,%d): %d",ne,a,b,min);
			ne++;
			mincost=mincost+min;
		}
		graph[a][b]=graph[b][a]=999;
	}
	printf("\n\nThe minimum cost of spanning tree: %d",mincost);
}
int find(int i)
{
	while(parent[i]>0)
	{
		i=parent[i];
	}
	return i;
}
void uni(int i,int j)
{
	parent[j]=i;
}
