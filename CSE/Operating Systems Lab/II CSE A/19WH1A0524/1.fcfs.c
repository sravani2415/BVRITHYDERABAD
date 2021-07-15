#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processes[n];
    printf("Enter order of processes: ");

    for (i=0; i<n; i++)
        scanf("%d", &processes[i]);
    int burstTime[n];

    for (i=0; i<n; i++) {
        printf("Enter the burst time of process %d:" , processes[i]);
        scanf("%d", &burstTime[i]);
    }

    int waitingTime[n],turnAround[n];

    waitingTime[0] = 0;
    int avgWait = 0;
    int avgTurn = 0;

    for (i=0; i<n-1; i++) {
        waitingTime[i+1] = burstTime[i] + waitingTime[i];
        avgWait += waitingTime[i+1];

        turnAround[i+1] = waitingTime[i+1] + burstTime[i+1];
        avgTurn += turnAround[i+1];
    }

    turnAround[0] = waitingTime[1];
    avgTurn += turnAround[0];
    printf("\nProcess\t   Burst Time\t  Waiting Time\t  Turn Around Time\n");

    for (i=0; i< n; i++)
        printf("   %d\t\t%d\t\t%d\t\t%d\n", processes[i], burstTime[i], waitingTime[i], turnAround[i]);

    printf("\nAverage Waiting Time = %d\nAverage Turn Around Time = %d", avgWait / n, avgTurn / n);
    return 0;
}
