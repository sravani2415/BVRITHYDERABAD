#include<stdio.h>
int main()
{
    int process[20],burst_time[20],waiting_time[20],turn_a_time[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
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
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
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
    printf("\nProcess No\tBurst Time\tWaiting Time\tTurn Around Time\n"); 
    for(i=0;i<n;i++)
    {
        turn_a_time[i]=burst_time[i]+waiting_time[i];   
        total+=turn_a_time[i];
        printf("\nP%d\t\t  %d\t\t    %d\t\t\t%d",process[i],burst_time[i],waiting_time[i],turn_a_time[i]);
    }
    avg_tat=(float)total/n;    
    printf("\n\nAverage Waiting Time=%.2f",avg_wt);
    printf("\nAverage Turnaround Time=%.2f\n",avg_tat);
}
