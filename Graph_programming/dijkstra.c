//DIJKSTRA ALGORITHM
#include<stdio.h>
#define MAX 20
void dijkstra(int [MAX][MAX],int,int);
int min(int [MAX],int [MAX],int);
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
				graph[i][j]=999;
		}
	}
	printf("\nEnter the starting vertex: ");
	scanf("%d",&s);
	dijkstra(graph,s,n);
	return 0;
}
void dijkstra(int graph[MAX][MAX],int s,int n)
{
	int visited[MAX],dis[MAX],u,v,i,j;
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
		dis[i]=graph[s][i];
	}
	visited[s]=1;
	dis[s]=1;
	i=2;
	while(i<=n)
	{
		u=min(visited,dis,n);
		visited[u]=1;
		i++;
		for(v=1;v<=n;v++)
		{
			if((dis[u]+graph[u][v]<dis[v]) && visited[v]==0)
			{
				dis[v]=dis[u]+graph[u][v];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(i!=s)
		{
			printf("\n %d--> %d : %d",s,i,dis[i]);
		}
	}
}
int min(int visited[MAX],int dis[MAX],int n)
{
	int i,j=1,min=999;
	for(i=1;i<=n;i++)
	{
		if(dis[i]<min && visited[i]==0)
		{
			min=dis[i];
			j=i;
		}
	}
	return j;
}
