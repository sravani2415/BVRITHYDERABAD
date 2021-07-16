#include<stdio.h>
int main()
{
    int process[20],burst_time[20],waiting_time[20],turn_a_time[20],priority[20],i,j,n,total=0,pos,temp;
	float avg_wt,avg_tat;
    printf("Enter the number of Processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("Enter the Burst Time and Priority for P%d:",i+1);
        scanf("%d %d",&burst_time[i],&priority[i]);
        process[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }

        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;

        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;

        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
    waiting_time[0]=0;
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
        total+=waiting_time[i];
    }
    avg_wt=(float)total/n;
    total=0;
    printf("\nProcess No\tPriority\tBurst Time\tWaiting Time\tTurn Around Time");
    for(i=0;i<n;i++)
    {
        turn_a_time[i]=burst_time[i]+waiting_time[i];
        total+=turn_a_time[i];
        printf("\nP%d\t\t  %d\t\t  %d\t\t    %d\t\t\t%d",process[i],priority[i],burst_time[i],waiting_time[i],turn_a_time[i]);
    }
    avg_tat=(float)total/n;
    printf("\n\nAverage Waiting Time=%.2f",avg_wt);
    printf("\nAverage Turnaround Time=%.2f\n",avg_tat);
	return 0;
}
