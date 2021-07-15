#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int i;

    printf("Enter order of processes:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &processes[i]);

    int burstTimes[n];
    int arrivalTimes[n];

    for (i = 0; i < n; i++) {
        printf("Enter the arrival and burst time %d: " , processes[i]);
            scanf("%d %d", &arrivalTimes[i], &burstTimes[i]);
    }

    int waitingTimes[n];
    int turnAround[n];
    int waitingTimes2[n];

    waitingTimes[0] = 0;
    waitingTimes2[0] = 0 - arrivalTimes[0];

    float avgWait = waitingTimes2[0];
    float avgTurn = 0;

    for (i = 0; i < n - 1; i++) {
        waitingTimes[i + 1] = burstTimes[i] + waitingTimes[i];
        waitingTimes2[i + 1] = waitingTimes[i + 1] - arrivalTimes[i + 1];
        avgWait += waitingTimes2[i + 1];

        turnAround[i + 1] = waitingTimes2[i + 1] + burstTimes[i + 1];
        avgTurn += turnAround[i + 1];
    }

    turnAround[0] = waitingTimes2[0] + burstTimes[0];
    avgTurn += turnAround[0];
    printf("\nProcess\t   Arrival Time\t   Burst Time\t  Waiting Time\t  Turn Around Time\n");

    for (i = 0; i < n; i++)
        printf("   %d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], arrivalTimes[i], burstTimes[i], waitingTimes2[i], turnAround[i]);

    printf("\nAverage Waiting Time = %.2f\nAverage Turn Around Time = %.2f", avgWait / n, avgTurn / n);
    return 0;
}
