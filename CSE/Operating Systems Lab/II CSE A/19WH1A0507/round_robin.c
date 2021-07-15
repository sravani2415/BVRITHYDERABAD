#include<stdio.h>
#include<stdbool.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int tq, bt[n], wt[n], tt[n], copy_bt[n], i;
    float awt = 0, att = 0;
    printf("Enter the burst times: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
    for(i = 0; i < n; i++)
        copy_bt[i] = bt[i];
    int t = 0;
    while(true){
        bool done = true;
        for(i = 0; i < n; i++) {
            if(copy_bt[i] > 0){
                done = false;
                if(copy_bt[i] > tq){
                    t += tq;
                    copy_bt[i] -= tq;
                    }
                else{
                    t += copy_bt[i];
                    wt[i] = t - bt[i];
                    copy_bt[i] = 0;
                }}
        }
        if(done == true)
            break;
    }

    for(i = 0; i < n; i++){
        tt[i] = wt[i] + bt[i];
        awt += wt[i];
        att += tt[i];
    }

    printf("process\t  waiting time\t   burst time\t  turnaround time\n");

    for(i = 0; i < n; i++)
        printf("P[%d]\t\t%dms\t\t%dms\t\t%dms\n", i + 1, wt[i], bt[i], tt[i]);
    printf("Average waiting time: %0.2fms\n", awt/n);
    printf("Average turnaround time: %0.2fms\n", att/n);
}
