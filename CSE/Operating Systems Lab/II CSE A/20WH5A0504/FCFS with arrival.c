#include<stdio.h>
int main(){
    int burst_time[20],waiting_time[20],turn_a_time[20],process[20],arrival_time[20],i,j,n,temp;
    float sum_wt=0,sum_tat=0,avg_wt=0,avg_tat=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("Enter the order of processes in terms of 1,2,3,4..n:");
    for(j=0;j<n;j++)
    {
    	scanf("%d",&process[j]);
    }
    for(i=0;i<n;i++){
        printf("Enter the arrival time and burst time for P%d:",i+1);
        scanf("%d %d",&arrival_time[i], &burst_time[i]);
        process[i]=i+1;
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(arrival_time[j]>arrival_time[j+1]){
                temp = process[j+1];
                process[j+1]=process[j];
                process[j] = temp;
                temp = arrival_time[j+1];
                arrival_time[j+1]=arrival_time[j];
                arrival_time[j] = temp;
                temp = burst_time[j+1];
                burst_time[j+1]=burst_time[j];
                burst_time[j] = temp;
            }
        }
    }
    waiting_time[0]=0;
    for(i=1;i<n;i++){
        waiting_time[i] = 0;
        for(j=0;j<i;j++){
            waiting_time[i] += burst_time[j];
        }
    }
    printf("Process    Arrival Time    Burst Time    Waiting Time     TurnAround Time");
    for(i=0;i<n;i++){
        waiting_time[i]=waiting_time[i] - arrival_time[i];
        turn_a_time[i] = burst_time[i] + waiting_time[i];
        sum_wt += waiting_time[i];
        sum_tat += turn_a_time[i];
        printf("\n P%d\t\t%d\t\t%d\t\t%d\t\t%d",process[i],arrival_time[i],burst_time[i],waiting_time[i],turn_a_time[i]);
    }
    avg_wt = sum_wt/n;
    avg_tat = sum_tat/n;
    printf("\nAverage Waiting Time=%.2f\n",avg_wt);
    printf("\nAverage Turnaround Time=%.2f\n",avg_tat);
    return 0;;
}
