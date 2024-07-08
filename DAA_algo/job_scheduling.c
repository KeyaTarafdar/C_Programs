//JOB SCHEDULING PROBLEM
#include<stdio.h>
#include<stdlib.h>
struct node{
	int id;
	int deadline;
	float profit;
};
void sort(struct node *,int);
int max_deadline(struct node *,int);
float job_scheduling(struct node *,struct node *,int,int);
int main()
{
	struct node *job,*final_job;
	int n,i,max;
	float profit;
	printf("\n\t\t Enter the total number of jobs: ");
	scanf("%d",&n);
	job=(struct node *)malloc(n*(sizeof(struct node)));
	for(i=0;i<n;i++)
	{
		printf("\n\n\t\t %d. Enter the Job ID, Job Deadline & Job Profit: ",i+1);
		scanf("%d%d%f",&job[i].id,&job[i].deadline,&job[i].profit);
	}
	sort(job,n);
	max=max_deadline(job,n);
	final_job=(struct node *)malloc(max*(sizeof(struct node)));
	for(i=0;i<max;i++)
	{
		final_job[i].id=0;
		final_job[i].deadline=0;
		final_job[i].profit=0.0;
	}
	profit=job_scheduling(job,final_job,n,max);
	printf("\n\n\t Final Job Schedule is:---\n\n");
	printf("\n\n\t ID No.\t Deadline\t Profit\n");
	for(i=0;i<max;i++)
	{
		printf("\t %d\t %d\t\t %.2f\n",final_job[i].id,final_job[i].deadline,final_job[i].profit);
	}
	printf("\n\n\t\t Max profit: %.2f",profit);
	free(job);
	free(final_job);
}
void sort(struct node *job,int n)
{
	int i,j,temp;
	float tmp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(job[j].profit<job[j+1].profit)
			{
				tmp=job[j].profit;
				job[j].profit=job[j+1].profit;
				job[j+1].profit=tmp;
				
				temp=job[j].id;
				job[j].id=job[j+1].id;
				job[j+1].id=temp;
				
				temp=job[j].deadline;
				job[j].deadline=job[j+1].deadline;
				job[j+1].deadline=temp;
			}
		}
	}
}
int max_deadline(struct node *job,int n)
{
	int i,max=job[0].deadline;
	for(i=1;i<n;i++)
	{
		if(job[i].deadline>max)
			max=job[i].deadline;
	}
return max;
}
float job_scheduling(struct node *job,struct node *final_job,int n,int max)
{
	int i=0,j;
	float profit=0.0;
	for(i=0;i<n;i++)
	{
		j=(job[i].deadline)-1;
		while(final_job[j].id!=0 && j>0)
			j--;
		if(final_job[j].id==0)
		{
			final_job[j].id=job[i].id;
			final_job[j].deadline=job[i].deadline;
			final_job[j].profit=job[i].profit;
			profit=profit+final_job[j].profit;
		}
	}
	return profit;
}
