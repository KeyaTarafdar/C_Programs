//DFS ALGORITHM
#include<stdio.h>
#define MAX 20
void DFS(int graph[MAX][MAX],int n,int s);
int top=-1,stack[MAX];
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
	DFS(graph,n,s);
	return 0;
}
void push(int a)
{
	top++;
	stack[top]=a;
}
int pop()
{
	int i;
	i=stack[top];
	top--;
	return i;
}
void DFS(int graph[MAX][MAX],int n,int s)
{
	int i,x[MAX]={0},visited[MAX]={0},c,j;
	x[1]=s;
	visited[s]=1;
	c=s;
	i=2;
	while(i<=n+1)
	{
		for(j=1;j<=n;j++)
		{
			/*printf("\n i=%d, j=%d",i,j);
			printf("\nc=%d",c);
			getch();*/
			if(graph[c][j]==1 && visited[j]==0)
			{
				/*printf("\ngraph[%d][%d]==1",c,j);
				printf("\npushing %d...",x[i-1]);
				getch();*/
				push(x[i-1]);
				x[i++]=j;
				c=j;
				visited[j]=1;
			}
		}
		if(i<=n)
		{
			c=pop();
			/*printf("\npoping %d...",c);
			getch();*/
		}
		else
			break;
	}
	printf("\n");
	for(i=1;i<=n;i++)
	{
		printf("%d | ",x[i]);
	}
}
