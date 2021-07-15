#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int i;

    printf("Enter order of processes in the format 1, 2, 3, 4,.... ,n: ");
    for (i = 0; i < n; i++)
        scanf("%d", &processes[i]);

    int burstTimes[n];

    for (i = 0; i < n; i++) {
        printf("Enter the burst time of process %d:" , processes[i]);
        scanf("%d", &burstTimes[i]);
    }

    int waitingTimes[n];
    int turnAround[n];

    waitingTimes[0] = 0;
    int avgWait = 0;
    int avgTurn = 0;

    for (i = 0; i < n - 1; i++) {
        waitingTimes[i + 1] = burstTimes[i] + waitingTimes[i];
        avgWait += waitingTimes[i + 1];

        turnAround[i + 1] = waitingTimes[i + 1] + burstTimes[i + 1];
        avgTurn += turnAround[i + 1];
    }

    turnAround[0] = waitingTimes[1];
    avgTurn += turnAround[0];
    printf("\nProcess\t   Burst Time\t  Waiting Time\t  Turn Around Time\n");

    for (i = 0; i < n; i++)
        printf("   %d\t\t%d\t\t%d\t\t%d\n", processes[i], burstTimes[i], waitingTimes[i], turnAround[i]);

    printf("\nAverage Waiting Time = %d\nAverage Turn Around Time = %d", avgWait / n, avgTurn / n);
    return 0;
}