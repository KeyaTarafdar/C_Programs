//CHAIN MATRIX
#include<stdio.h>
int p[20];
void matrix_mul(long int[20][20],long int[20][20],int);
void print_matrix(long int[20][20],int);
void brackets(long int[20][20],long int,long int);
int main()
{
	long int m[20][20]={0},s[20][20]={0};
	int i,n,j;
	printf("\n Enter the number of matrix: ");
	scanf("%d",&n);
	printf("\n Enter the dimensions of the matrices:-\n ");
	for(i=0;i<=n;i++)
	{
		printf("\n\t P%d: ",i);
		scanf("%d",&p[i]);
	}
	matrix_mul(m,s,n);
	print_matrix(m,n);
	printf("\n\n");
	print_matrix(s,n);
	printf("\n\n");
	brackets(s,1,n);
	return 0;
}
void matrix_mul(long int m[20][20],long int s[20][20],int n)
{
	int i,j,k,min,c;
	for(i=1;i<=n;i++)
	{
		c=i;
		j=i;
		i=1;
		while(i<=n && j<=n)
		{
			if(i==j)
			{
				m[i][j]=0;
				s[i][j]=0;
			}
			else
			{
				for(k=i;k<j;k++)
				{
					min=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
					if(m[i][j]==0)
					{
						m[i][j]=min;
						s[i][j]=k;
					}
					else
						if(min<=m[i][j])
						{
							m[i][j]=min;
							s[i][j]=k;
						}
				}
			}
			i++;
			j++;
		}
		i=c;
	}
}
void print_matrix(long int m[20][20],int n)
{
	int i,j;
	printf("\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\t%d",m[i][j]);
		}
		printf("\n");
	}
}
void brackets(long int s[20][20],long int i,long int j)
{
	if(i==j)
	{
		printf("A%d ",i);
	}
	else
	{
		printf("(");
		brackets(s,i,s[i][j]);
		brackets(s,s[i][j]+1,j);
		printf(")");
	}
}
