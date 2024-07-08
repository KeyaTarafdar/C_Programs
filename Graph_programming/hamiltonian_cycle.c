// HAMILTONIAN CYCLE
#include <stdio.h>
#define MAX 20
int c = 1;
void hamiltonian(int graph[MAX][MAX], int n, int k);
int is_next(int graph[MAX][MAX], int n, int i, int k);
int x[MAX] = {0};
int main()
{
	int n, i, j, graph[MAX][MAX], s;
	printf("\nEnter the number of nodes: ");
	scanf("%d", &n);
	printf("\n\nEnter the weightages of the edges:----(IF THERE DOESN'T EXIT ANY EDGE, ENTER 0)\n");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	x[1] = 1;
	hamiltonian(graph, n, 2);
	if (c == 1)
	{
		printf("\n\nHamiltonian cycle is not possible in this graph!");
	}
	return 0;
}
void hamiltonian(int graph[MAX][MAX], int n, int i)
{
	int k, j;
	for (k = 1; k <= n; k++)
	{
		if (is_next(graph, n, k, i) == 1)
		{
			x[i] = k;
			if (i == n)
			{
				printf("\nSolution %d:--\n", c++);
				for (j = 1; j <= n; j++)
				{
					printf("%d | ", x[j]);
				}
				printf("\n");
			}
			else
			{
				hamiltonian(graph, n, i + 1);
			}
		}
	}
	for (j = i; j <= n; j++)
	{
		x[j] = 0;
	}
}
int is_next(int graph[MAX][MAX], int n, int k, int i)
{
	int j;
	for (j = 1; j < i; j++)
	{
		if (x[j] == k || graph[x[i - 1]][k] == 0)
			return 0;
		else if (graph[k][1] == 0 && i == n)
			return 0;
	}
	return 1;
}
