#include<stdio.h>
int main()
{
    int n,process[20],burst_time[20],waiting_time[20],turn_a_time[20],i,j;
    float avg_wt=0,avg_tat=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("Enter the order of processes in terms of 1,2,3,4..n:");
    for(j=0;j<n;j++)
    {
    	scanf("%d",&process[j]);
    }
    for(i=0;i<n;i++)
    {
    	printf("Enter the process burst time %d:",process[i]);
        scanf("%d",&burst_time[i]);
    }
 	waiting_time[0]=0;
 	for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
    }

    printf("\nProcess No\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0;i<n;i++)
    {
        turn_a_time[i]=burst_time[i]+waiting_time[i];
        avg_wt+=waiting_time[i];
        avg_tat+=turn_a_time[i];
        printf("  %d\t\t  %d\t\t  %d\t\t  %d\n",process[i],burst_time[i],waiting_time[i],turn_a_time[i]);
    }
    avg_wt/=n;
    avg_tat/=n;
    printf("\nAverage Waiting Time=%.2f",avg_wt);
    printf("\nAverage Turnaround Time=%.2f",avg_tat);
 	return 0;
}
