#include<stdio.h>
int main()
{
	int execution_time[100], wait_time[100], service_time[100];
	int n, i;
	float avg_wait_time = 0;
	printf("Enter number of processes\n");
	scanf("%d",&n);
	int arrival_time[100];
	for(i=0;i<n;i++)
		arrival_time[i] = i;
	printf("Enter Execution time\n");
	for(i=0;i<n;i++)
		scanf("%d",&execution_time[i]);
	service_time[0] = 0;
	for(i=1;i<n;i++)
		service_time[i] = execution_time[i] + service_time[i-1];
	printf("Service times: ");
	for(i=0;i<n;i++)
		printf("%d\t",service_time[i]);
	wait_time[0] = 0;
	for(i=1;i<n;i++)
		wait_time[i] = execution_time[i-1] - arrival_time[i];		
	printf("\nWait times: ");
	for(i=0;i<n;i++)
		printf("%d\t", wait_time[i]);	
	int sum = 0;
	for(i=0;i<n;i++)
		sum = sum + wait_time[i];		
	printf("\nProcess \t Arrival Time \t Execution Time \t Service Time\n");
	for(i=0;i<n;i++)
		printf("  %d\t\t\t%d\t\t%d\t\t\t%d\n", i , arrival_time[i], execution_time[i], service_time[i]);
	avg_wait_time = (float) sum / n;
	printf("\nAverage Wait Time = %f", avg_wait_time);
	return 0;
}
