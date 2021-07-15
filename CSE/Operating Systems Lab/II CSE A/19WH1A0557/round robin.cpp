#include<stdio.h>
#include<stdbool.h>
int main() {
    int n,bt[20],wt[20],tat[20],temp,p[20];
    float avg_wt = 0, avg_tat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times: ");
    for(int i = 0; i < n; i++) {
    	
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;  
    }
    printf("Enter the time quantum: ");
    scanf("%d", &temp);
    int rem_bt[n];
    for(int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
    }
    int t = 0;
    while(1) {
        bool done = true;
        for(int i = 0; i < n; i++) {
            if(rem_bt[i] > 0) {
                done = false;
                if(rem_bt[i] > temp) {
                    t += temp;
                    rem_bt[i] -= temp;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if(done == true) {
            break;
        }
    }

    for(int j = 0; j < n; j++) {
        tat[j] = wt[j] + bt[j];
    }
    for(int i = 0; i < n; i++) {
        avg_wt += wt[i];
    }
    for(int i = 0; i < n; i++) {
        avg_tat += tat[i];
    }
    printf("process\t  waiting time\t   burst time\t  turnaround time\n");
    for(int i = 0; i < n; i++) {
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i + 1, wt[i], bt[i], tat[i]);
    }
    printf("Average waiting time: %0.2f\n", avg_wt/n);
    printf("Average turnaround time: %0.2f\n", avg_tat/n);
}
