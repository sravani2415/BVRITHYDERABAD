#include<stdio.h>
int main()
{
	int n;
	printf("how many number of processors:\n");
	scanf("%d",&n);
	int arrival_time[n], execution_time[n], service_time[n];
	float avg_waiting_time = 0;
	for(int i=0; i<n; i++)
	{
		printf("Enter arrival and execution times for processor %d", i+1);
		scanf("%d %d",&arrival_time[i], &execution_time[i]);
		if(i == 0)
			service_time[i] = 0;
		else
			service_time[i] = service_time[i-1] + execution_time[i-1];
	}
	printf("arrival\t   excecution\t   service\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\t	%d\t	%d\n", arrival_time[i], execution_time[i], service_time[i]);
		avg_waiting_time += (service_time[i] - arrival_time[i]);
	}
	avg_waiting_time = avg_waiting_time / n;
	printf("Average Waiting Time = %f", avg_waiting_time);
	
	return 0;
}