
#include<stdio.h>
int main()
{
	int n, temp;
	printf("Enter no of processes\n");
	scanf("%d", &n);
	int priority[n], Burst_Time[n], P[n], Service_Time[n];	
	printf("Enter Burst time  and Priority \n");
	for(int i =0;i<n;i++)
	{
		scanf("%d %d", &Burst_Time[i], &priority[i]);
		P[i] = i+1;
	}

	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-i-1;j++)
			if(priority[j] < priority[j+1])
			{
			temp = priority[j];	
			priority[j] = priority[j+1];
			priority[j+1] = temp;	

			temp = Burst_Time[j];	
			Burst_Time[j] = Burst_Time[j+1];
			Burst_Time[j+1] = temp;

			temp = P[j];	
			P[j] = P[j+1];
			P[j+1] = temp;			
			}

	Service_Time[0] = 0;
	for(int i=1;i<n;i++)	
		Service_Time[i] = Service_Time[i-1] + Burst_Time[i-1];
	float tat=0.0;
	for(int i=0;i<n;i++)
		tat += Service_Time[i] + Burst_Time[i];
	
	printf("Process Burst_Time\t   Priority\t   Service_Time\n");
	for(int i=0;i<n;i++)
		printf("P%d\t       %d\t       %d\t         %d\n", P[i], Burst_Time[i], priority[i], Service_Time[i]);

	float avg_wait_time = 0.0; 
	for(int i=0; i<n; i++)
	{
		avg_wait_time += (Service_Time[i]);
	}
	avg_wait_time = avg_wait_time / n;
	tat = tat/n;
	printf("Average Waiting Time = %f\n", avg_wait_time);
	printf("Average Turn Around Time = %f\n",tat);
return 0;
}