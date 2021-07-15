#include <stdio.h>

void swap(int* num1, int* num2);
void bubbleSort(int priorities[], int burstTimes[], int processes[], int n);
void priority(int priorities[], int processes[], int burstTimes[], int n);

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int i;

    int burstTimes[n];
    int priorities[n];
    int processes[n];

    for (i = 0; i < n; i++) {
        printf("Enter the priority and burst time %d:", i + 1);
        scanf("%d %d", &priorities[i], &burstTimes[i]);
        processes[i] = i + 1;
    }
    priority(priorities, processes, burstTimes, n);

}

void priority(int priorities[], int processes[], int burstTimes[], int n) {
    bubbleSort(priorities, burstTimes, processes, n);

    int waitingTimes[n];
    int turnAround[n];

    waitingTimes[0] = 0;
    int avgWait = 0;
    int avgTurn = 0;
    int i;

    for (i = 0; i < n - 1; i++) {
        waitingTimes[i + 1] = burstTimes[i] + waitingTimes[i];
        avgWait += waitingTimes[i + 1];

        turnAround[i + 1] = waitingTimes[i + 1] + burstTimes[i + 1];
        avgTurn += turnAround[i + 1];
    }

    turnAround[0] = waitingTimes[1];
    avgTurn += turnAround[0];

    printf("\nProcess\t   Burst Time\t  Priority\t   Waiting Time\t  Turn Around Time\n");

    for (i = 0; i < n; i++)
        printf("   %d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i] , burstTimes[i], priorities[i], waitingTimes[i], turnAround[i]);

    printf("\nAverage Waiting Time = %d\nAverage Turn Around Time = %d", avgWait / n, avgTurn / n);
}

void swap(int* num1, int* num2) {
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

void bubbleSort(int priorities[], int burstTimes[], int processes[], int n) {
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(priorities[j] > priorities[j + 1]) {
                swap(&burstTimes[j], &burstTimes[j+1]);
                swap(&priorities[j], &priorities[j+1]);
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}
