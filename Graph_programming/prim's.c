//PRIM'S ALGORITHM
#include<stdio.h>
#define MAX 20
void print_matrix(int [MAX][MAX],int);
void prims(int [MAX][MAX],int);
int visited[MAX]={0};
int main()
{
	int n,i,j,graph[MAX][MAX];
	printf("\nEnter the number of nodes: ");
	scanf("%d",&n);
	printf("\n\nEnter the cost edjacency matrix of the graph:----(IF THERE DOESN'T EXIT ANY EDGE, ENTER 0)\n");
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
	print_matrix(graph,n);
	prims(graph,n);
	return 0;
}
void print_matrix(int graph[MAX][MAX],int n)
{
	int i,j;
	printf("\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(graph[i][j]==999)
			{
				printf("\t0");
			}
			else
				printf("\t%d",graph[i][j]);
		}
		printf("\n");
	}
}
void prims(int graph[MAX][MAX],int n)
{
	int ne=1,u=0,v=0,a=0,b=0,min,mincost=0,i,j;
	visited[1]=1;
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(graph[i][j]<min)
				{
					if(visited[i]!=0)
					{
						min=graph[i][j];
						a=u=i;
						b=v=j;
					}
				}
			}
		}
		if(visited[u]==0 || visited[v]==0)
		{
			mincost=mincost+min;
			printf("\n%d edge (%d,%d): %d",ne,a,b,min);
			ne++;
			visited[v]=1;
		}
		graph[a][b]=graph[b][a]=999;
	}
	printf("\n\nThe minimum cost of spanning tree: %d",mincost);
}
