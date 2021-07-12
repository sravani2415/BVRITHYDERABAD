#include <stdio.h>
int main()
{
	int exe[10],arr[10],ser_time[10];
	int n,i;
	float avg_wt; 
	avg_wt = 0;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter execution time for process %d ",i);
		scanf("%d",&exe[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("Enter arrvial order for process %d ",i);
		scanf("%d",&arr[i]);
	}
	ser_time[0] = 0;
	for(i=1;i<n;i++)
	{
		ser_time[i] = ser_time[i-1] + exe[i-1];
		avg_wt = avg_wt + (ser_time[i]-arr[i]);
	}
	printf("Process Execution Arrival Service\n");
	for(i=0;i<n;i++)
	{
		printf("\nP%d  \t%d \t\t%d   \t%d",i,exe[i],arr[i],ser_time[i]);
	}
	printf("\n Average waiting time = %f",avg_wt/n);
	return 0;
}
