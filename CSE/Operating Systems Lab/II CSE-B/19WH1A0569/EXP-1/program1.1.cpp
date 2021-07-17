#include<stdio.h>
int main()
{
	int wt,at[100],st[100],i,n,wt1;
	wt = 0;
	printf("enter the values of processors:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the arriving time for %d processor:",i);
		scanf("%d",&at[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("enter the service time for %d processor:",i);
		scanf("%d",&st[i]);
	}
	for(i=0;i<n;i++)
	{
		wt = st[i] - at[i];
		printf("the waiting time of %d processor is = %d\n",i,wt);
		wt++;
	}
	wt1 = 0;
	wt = 0;
	for(i=0;i<n;i++)
	{
		wt = st[i] - at[i];
		wt1 = wt + wt1;
		wt++;	
	}
	double avg;
	avg = (double)wt1/n;
	printf("the average waiting time is %f\n",avg);
}
