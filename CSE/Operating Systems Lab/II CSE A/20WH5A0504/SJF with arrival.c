#include<stdio.h>
int main()
{
    int n,i,j;
    float avg_wt,avg_tat;
    int tot_wt = 0, tot_tat = 0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int burst_time[n],process[n],waiting_time[n],turn_a_time[n],arrival_time[n];
    printf("Enter the order of processes in terms of 1,2,3,4..n:");
    for(j=0;j<n;j++)
    {
    	scanf("%d",&process[j]);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time and burst time for P%d:",i+1);
        scanf("%d %d",&arrival_time[i], &burst_time[i]);
        process[i]=i+1;
    }
    int temp;
    for(i=0;i<n-1;i++)
   {
     for(j=0;j<n-i-1;j++)
      {
        if(arrival_time[j]>arrival_time[j+1])
          {
            temp=arrival_time[j];
            arrival_time[j]=arrival_time[j+1];
            arrival_time[j+1]=temp;

            temp=burst_time[j];
            burst_time[j]=burst_time[j+1];
            burst_time[j+1]=temp;

            temp=process[j];
            process[j]=process[j+1];
            process[j+1]=temp;
           }
        }
    }
    int exec_time = 0, min, k = 1;
    for(j=0;j<n;j++)
    {
        exec_time=exec_time+burst_time[j];
        min=burst_time[k];
        for(i=k;i<n;i++)
        {
            if (exec_time>=arrival_time[i] && burst_time[i]<min)
               {
                temp=process[k];
                process[k]=process[i];
                process[i]=temp;

                temp=arrival_time[k];
                arrival_time[k]=arrival_time[i];
                arrival_time[i]=temp;

                temp=burst_time[k];
                burst_time[k]=burst_time[i];
                burst_time[i]=temp;
            }
       }
        k++;
    }

    waiting_time[0]=0;
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
    }
    printf("Process    Arrival Time    Burst Time    Waiting Time     TurnAround Time");
    for(i=0;i<n;i++)
    {
        waiting_time[i] = waiting_time[i] - arrival_time[i];
        turn_a_time[i]=burst_time[i]+waiting_time[i];
        tot_wt +=waiting_time[i];
        tot_tat +=turn_a_time[i];
        printf("\n P%d\t\t%d\t\t%d\t\t%d\t\t%d",process[i],arrival_time[i],burst_time[i],waiting_time[i],turn_a_time[i]);
    }
    avg_wt = (float)tot_wt/n;
    avg_tat= (float)tot_tat/n;
    printf("\n\nAverage Waiting Time=%.2f",avg_wt);
    printf("\nAverage Turnaround Time=%.2f\n",avg_tat);
}
