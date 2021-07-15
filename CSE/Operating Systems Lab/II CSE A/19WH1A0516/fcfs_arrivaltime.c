/* First Come First Serve Scheduling(Non Preemptive) with Arrival Time - Lab Task 3*/
#include<stdio.h>
int main()
{
    int n,bt[20],wt[20],tat[20],i,j,p[20],at[20],temp;
    float sum_wt=0,sum_tat = 0,avwt=0,avtat=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    
    printf("\nEnter the order of processes in terms of 1,2,3,4,...n: ");
    for(i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }
    
    for(i=0;i<n;i++)
    {
    	printf("Enter the burst time and arrival time of process %d:", p[i]);
        scanf("%d %d",&bt[i], &at[i]);
		
    }
    for (i=0; i<n-1; i++){
     for (j=0; j<n-i-1; j++){
            if (at[j]>at[j+1]){
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }
    

    wt[0]=0;   
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    printf("Process\t    Arrival Time\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
		wt[i] = wt[i] - at[i];
        tat[i]=bt[i]+wt[i];
        sum_wt +=wt[i];
        sum_tat +=tat[i];
        printf("\np[%d]\t\t %d\t\t        %d\t\t    %d\t\t\t%d",p[i],at[i],bt[i],wt[i],tat[i]);
    }
 
    avwt =sum_wt/n;
    avtat = sum_tat/n;
    printf("\nAverage Waiting time=%.2f\n",avwt);
    printf("Average Turnaround time=%.2f",avtat);
 
    return 0;
}
