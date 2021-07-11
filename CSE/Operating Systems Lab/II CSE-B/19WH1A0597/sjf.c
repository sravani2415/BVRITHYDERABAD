#include<stdio.h>
int main()
{
	int n;
	printf("Enter number of processes: \n");
	scanf("%d", &n);
	int arrival_time[n], burst_time[n], process[n], service_time[n], i, j;
	printf("\nEnter burst time: \n");
	for(i=0;i<n;i++)
	{
		printf("P%d: ", i+1);
		scanf("%d", &burst_time[i]);
		process[i] = i+1;
	}
	printf("\nEnter arrival time: \n");
	for(i =0;i<n;i++)
	{
		printf("P%d: ", i+1);
		scanf("%d", &arrival_time[i]);
		process[i] = i+1;
	}
	service_time[0] = 0;
	int completion = burst_time[0], t;
	for(i=0;i<n;i++)
	{
		for(j=1;j<n-i-1; j++)
			if(burst_time[j] > burst_time[j+1] && arrival_time[j] <= completion)
			{
				t = burst_time[j];
				burst_time[j] = burst_time[j+1];
				burst_time[j+1] = t;

				t = arrival_time[j];
				arrival_time[j] = arrival_time[j+1];
				arrival_time[j+1] = t;

				t = process[j];
				process[j] = process[j+1];
				process[j+1] = t;

			} 
	}
	
	for(i=1;i<n;i++)	
		service_time[i] = service_time[i-1] + burst_time[i-1];
		
	printf("\nProcess    Arrival Time   Burst Time   Service Time\n");
	for(i=0;i<n;i++)
		printf("P%d\t\t%d\t\t%d\t\t%d\n", process[i], arrival_time[i], burst_time[i], service_time[i]);	
	
	float avg_wait_time = 0.0; 
	for(i=0; i<n; i++)
	{
		avg_wait_time += (service_time[i] - arrival_time[i]);
	}
	avg_wait_time = avg_wait_time / n;

	printf("\nAverage Wait Time = %f\n", avg_wait_time);
	return 0;
}
