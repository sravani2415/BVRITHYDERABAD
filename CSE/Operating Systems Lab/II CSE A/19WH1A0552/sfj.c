#include <stdio.h>

void swap(int* num1, int* num2);
void bubbleSort(int arr[], int processes[], int n);
void sjf(int arrivalTimes[],int processes[], int burstTimes[], int n);

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int i;

    int burstTimes[n];
    int arrivalTimes[n];
    int processes[n];

    for (i = 0; i < n; i++) {
        printf("Enter the arrival time, burst time of the process %d:", i + 1);
        scanf("%d %d", &arrivalTimes[i], &burstTimes[i]);
        processes[i] = i + 1;
    }
    sjf(arrivalTimes, processes, burstTimes, n);

}

void sjf(int arrivalTimes[], int processes[], int burstTimes[], int n) {
    bubbleSort(burstTimes, processes, n);
    int waitingTimes[n];
    int turnAround[n];

    waitingTimes[0] = 0;
    int avgWait = 0;
    int avgTurn = 0;
    int i;

    for (i = 0; i < n - 1; i++) {
        waitingTimes[i + 1] = burstTimes[i] + waitingTimes[i];
        waitingTimes[i + 1] -= arrivalTimes[i + 1];
        avgWait += waitingTimes[i + 1];

        turnAround[i + 1] = waitingTimes[i + 1] + burstTimes[i + 1];
        avgTurn += turnAround[i + 1];
    }

    turnAround[0] = waitingTimes[1];
    avgTurn += turnAround[0];

    printf("\nProcess\t   Burst Time\t  Waiting Time\t  Turn Around Time\n");

    for (i = 0; i < n; i++)
        printf("   %d\t\t%d\t\t%d\t\t%d\n", processes[i] , burstTimes[i], waitingTimes[i], turnAround[i]);

    printf("\nAverage Waiting Time = %d\nAverage Turn Around Time = %d", avgWait / n, avgTurn / n);
}

void swap(int* num1, int* num2) {
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

void bubbleSort(int arr[], int processes[], int n) {
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j+1]);
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}
