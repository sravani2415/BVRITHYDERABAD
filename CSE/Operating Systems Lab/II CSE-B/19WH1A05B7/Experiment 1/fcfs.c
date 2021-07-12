#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of process:\n");
	scanf("%d",&n);
	float avg_wt,wt = 0;
	int at[n],et[n],st[n],i;
	st[0] = 0;
	printf("Enter the arrival times for processors:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&at[i]);	
	}
	printf("Enter the execution times for processors:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&et[i]);	
	}
	printf("--------Output----------\n");
	printf("The service times for processors are:\n");
	for(i=0;i<n;i++)
	{
		st[i] = st[i-1] + et[i-1];
		printf("%d\n",st[i]);
	}
	for(i=1;i<n;i++)
	{
		wt += st[i] - at[i];
	}
	avg_wt = wt/n;
	printf("Average Wait Time = %f",avg_wt);
    return 0;
}
