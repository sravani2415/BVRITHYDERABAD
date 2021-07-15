#include<stdio.h>
#include<stdbool.h>
int main() {
    int n,i,j;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    int process[n],burst_time[n],waiting_time[n],turn_a_time[n],time_quantum;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter the order of processes in terms of 1,2,3,4..n:");
    for(j=0;j<n;j++)
    {
    	scanf("%d",&process[j]);
    }
    for(i=0;i<n;i++)
    {
    	printf("Enter the burst time for P%d:",process[i]);
        scanf("%d",&burst_time[i]);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    int copy_bt[n];
    for(int i = 0; i < n; i++) {
        copy_bt[i] = burst_time[i];
    }
    int t = 0;
    while(1) {
        bool done = true;
        for(int i = 0; i < n; i++) {
            if(copy_bt[i] > 0) {
                done = false;
                if(copy_bt[i] > time_quantum) {
                    t += time_quantum;
                    copy_bt[i] -= time_quantum;
                } else {
                    t += copy_bt[i];
                    waiting_time[i] = t - burst_time[i];
                    copy_bt[i] = 0;
                }
            }
        }
        if(done == true) {
            break;
        }
    }

    for(int j = 0; j < n; j++) {
        turn_a_time[j] = waiting_time[j] + burst_time[j];
    }
    for(int i = 0; i < n; i++) {
        avg_wt += waiting_time[i];
        avg_tat += turn_a_time[i];
    }
    printf("\nProcess No\tBurst Time\tWaiting Time\tTurn Around Time");
    for(int i = 0; i < n; i++) {
        printf("\nP%d\t\t  %d\t\t    %d\t\t\t%d",process[i],burst_time[i],waiting_time[i],turn_a_time[i]);
    }
    printf("\nAverage waiting time:%.2f", avg_wt/n);
    printf("\nAverage turnaround time:%.2f\n", avg_tat/n);
}
