//BFS ALGORITHM
#include<stdio.h>
#define MAX 20
void BFS(int graph[MAX][MAX],int n,int s);
int front=-1,rear=-1,queue[MAX]={0};
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
		}
	}
	printf("\nEnter the starting vertex: ");
	scanf("%d",&s);
	BFS(graph,n,s);
	return 0;
}
void enqueue(int a)
{
	if(front==-1 && rear==-1)
	{
		front++;
		rear++;
		queue[rear]=a;
	}
	else
	{
		rear++;
		queue[rear]=a;
	}
}
int dequeue()
{
	int i;
	i=queue[front];
	front++;
	return i;
}
void BFS(int graph[MAX][MAX],int n,int s)
{
	int visited[MAX]={0},x[MAX]={0},i,c,j;
	x[1]=s;
	visited[s]=1;
	i=2;
	while(i<=n)
	{
		c=s;
		for(j=1;j<=n;j++)
		{
			if(graph[c][j]==1 && visited[j]==0)
			{
				/*printf("\nEnqueueing %d...",j);
				getch();*/
				enqueue(j);
				visited[j]=1;
			}
		}
		s=dequeue();
		/*printf("\nDequeueing %d...",s);
		getch();*/
		x[i]=s;
		i++;
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("%d | ",x[i]);
	}
}
