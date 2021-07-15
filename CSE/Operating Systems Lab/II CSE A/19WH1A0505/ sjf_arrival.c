#include <stdio.h>

void swap(int* num1, int* num2);
void bubbleSort(int arr[], int processes[], int arr_time[], int n);
void sjf(int arrivalTimes[],int processes[], int burstTimes[], int n, int b, int a);

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int i, j;

    int burstTimes[n-1];
    int arrival_times[n-1];
    int processes[n-1];
    int b1, a1, a, b;

    for (i = 0; i < n; i++) {
        printf("Enter the arrival and burst time %d:", i + 1);
        scanf("%d %d", &a, &b);

        if (a == 0) {
            a1 = a;
            b1 = b;
        }
        else {
            arrival_times[i] = a;
            burstTimes[i] = b;
            processes[i] = i + 1;
        }
    }
    sjf(arrival_times, processes, burstTimes, n, b1, a1);
}

void sjf(int arrivalTimes[], int processes[], int burstTimes[], int n, int b1, int a1) {
    bubbleSort(burstTimes, processes, arrivalTimes, n);
    int waitingTimes[n], waitingTimes2[n];
    int turnAround[n], i;

    waitingTimes[0] = 0;
    waitingTimes[1] = b1 + waitingTimes[0];
    waitingTimes2[1] = waitingTimes[1] - arrivalTimes[1];

    waitingTimes2[0] = waitingTimes[0] - a1;

    float avgWait = waitingTimes2[0] + waitingTimes2[1];
    float avgTurn = 0;

    for (i = 1; i < n - 1; i++) {
        waitingTimes[i + 1] = burstTimes[i] + waitingTimes[i];
        waitingTimes2[i + 1] = waitingTimes[i + 1] - arrivalTimes[i + 1];
        avgWait += waitingTimes2[i + 1];

        turnAround[i + 1] = waitingTimes2[i + 1] + burstTimes[i + 1];
        avgTurn += turnAround[i + 1];
    }

    turnAround[0] = waitingTimes2[0] + b1;
    turnAround[1] = waitingTimes2[1] + burstTimes[1];
    avgTurn += turnAround[0] + turnAround[1];

    printf("\nProcess\t   Arrival Times\t  Burst Time\t  Waiting Time\t  Turn Around Time\n");
    printf("   %d\t\t    %d\t\t    %d\t\t    %d\t\t    %d\n", 1, a1, b1, 0, turnAround[0]);

    for (i = 1; i < n; i++)
        printf("   %d\t\t    %d\t\t    %d\t\t    %d\t\t    %d\n", processes[i], arrivalTimes[i], burstTimes[i], waitingTimes2[i], turnAround[i]);

    printf("\nAverage Waiting Time = %f\nAverage Turn Around Time = %f", avgWait / n, avgTurn / n);
}

void swap(int* num1, int* num2) {
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

void bubbleSort(int arr[], int processes[], int arrivalTimes[], int n) {
    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j+1]);
                swap(&processes[j], &processes[j + 1]);
                swap(&arrivalTimes[j], &arrivalTimes[j + 1]);
            }
        }
    }
}
