//non preemptive of priority scheduling
#include<stdio.h>
int main()
{
    int burst_time[20], process[20], wait_time[20], tat[20], priority[20], i, j, n, pos, t, total;
	float avg_wait_time, avg_tat;
    printf("Enter Total Number of Process: \n");
    scanf("%d",&n);
 
    printf("Enter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nProcess %d\n",i+1);
        printf("Burst Time: ");
        scanf("%d",&burst_time[i]);
        printf("Priority: ");
        scanf("%d",&priority[i]);
        process[i]=i+1;   
    }
    //sorting
    for(i=0;i<n;i++)
    {
        pos = i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j] > priority[pos])
                pos = j;
        }
        for(j=i+1;j<n;j++)
        {
        	if(priority[j] == priority[pos])
        		if(process[j] < process[pos])
        			pos = j;
		}

        t = priority[i];
        priority[i] = priority[pos];
        priority[pos] = t;
        
        t = burst_time[i];
        burst_time[i] = burst_time[pos];
        burst_time[pos] = t;
 
        t = process[i];
        process[i] = process[pos];
        process[pos] = t;
    }
 
    wait_time[0]=0;
    for(i=1;i<n;i++)
    {
        wait_time[i]=0;
        for(j=0;j<i;j++)
            wait_time[i]+=burst_time[j];
 
        total += wait_time[i];
    }
    
    avg_wait_time = (float) total / n;
	total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurn Around Time");
    for(i=0;i<n;i++)
    {
        tat[i] = burst_time[i] + wait_time[i];  
        total += tat[i];
        printf("\nProcess %d\t  %d\t\t    %d\t\t\t%d",process[i],burst_time[i],wait_time[i],tat[i]);
    }
    avg_tat = (float) total / n;
    printf("\n\nAverage Waiting Time = %0.3f",avg_wait_time);
    printf("\nAverage Turn Around Time = %0.3f\n",avg_tat);
 
	return 0;
}
