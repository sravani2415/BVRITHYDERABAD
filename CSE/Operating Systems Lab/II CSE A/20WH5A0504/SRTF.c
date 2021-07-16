#include <stdio.h>
int main(){
    int arrival_time[10],burst_time[10],temp[10],waiting_time1[10],turn_a_time1[10];
    int i,j,small,count=0,time,n;
    float waiting_time = 0,turn_a_time = 0,end;
    printf("Enter the number of Processes:");
    scanf("%d", &n);
    printf("Enter the order of processes in terms of 1,2,3,4..n:");
    for(j=0;j<n;j++)
    {
    	scanf("%d",&temp[j]);
    }
    for(i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time for P%d:",i+1);
        scanf("%d %d",&arrival_time[i], &burst_time[i]);
        temp[i] = burst_time[i];
    }
    burst_time[9] = 9999;
    for(time = 0; count != n; time++){
        small = 9;
        for(i = 0;i<n; i++){
            if(arrival_time[i] <= time && burst_time[i] < burst_time[small] && burst_time[i] > 0)
                small = i;
        }
        burst_time[small]--;
        if(burst_time[small] == 0){
            count++;
            end = time + 1;
            waiting_time = waiting_time + end - arrival_time[small] - temp[small];
            turn_a_time = turn_a_time + end - arrival_time[small];
            waiting_time1[small] = end - arrival_time[small] - temp[small];
            turn_a_time1[small] = end -arrival_time[small];
        }
    }
     printf("\nProcess No\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(int i = 0;i<n;i++){
        printf("  %d\t\t  %d\t\t  %d\t\t  %d\n" ,i,temp[i],waiting_time1[i],turn_a_time1[i]);
    }
    printf("\nAverage Waiting Time:%.2f\n", waiting_time/n);
    printf("Average Turnaround Time:%.2f\n", turn_a_time/n);

    return 0;
}
