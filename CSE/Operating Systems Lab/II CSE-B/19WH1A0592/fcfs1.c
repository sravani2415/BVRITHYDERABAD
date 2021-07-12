#include <stdio.h>
int main()
{
	int n,i,A[10], E[10],S[10],total_worktime=0;
	float avg_worktime;
	printf("Enter the number of process:");
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the Arrival time for the process:");
		scanf("%d", &A[i]);
		printf("Enter the Execute time for the process:");
		scanf("%d", &E[i]);
		printf("Enter the Service time for the process:");
		scanf("%d", &S[i]);	
		total_worktime = total_worktime + (S[i]-A[i]);
		avg_worktime = (float)total_worktime/n;
	}
	printf("Average work time is %f", avg_worktime);
}
