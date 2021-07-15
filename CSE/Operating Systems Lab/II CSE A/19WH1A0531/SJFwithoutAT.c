#include<stdio.h>

void swap(int*, int*);

int main() {
    int n;
    printf("Enter the no of processes : ");
    scanf("%d", &n);

    int burst_time[n] , proc[n], i, j;
    for(i = 0 ; i < n ; i++) {
        printf("Enter the Burst time for the process %d : ", i+1);
        scanf("%d", &burst_time[i]);
    }

    for(i = 0 ; i < n ; i++) {
        proc[i] = i+1;
    }

    for (i = 0 ; i < n ; i++) {
        for ( j = 0 ; j  < n - i - 1 ; j++) {
            if (burst_time[j] > burst_time[j+1]) {
                swap(&burst_time[j], &burst_time[j+1]);
                swap(&proc[j], &proc[j+1]);
            }
        }
    }

    float waiting_time[n] , turn_around_time[n];
    waiting_time[0] = 0;
    for(i = 1 ; i < n ; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }
    for( i = 0 ; i < n ; i++) {
        turn_around_time[i] = waiting_time[i] + burst_time[i];
    }

    float avg_waiting_time = 0 , avg_turn_around_time = 0;
    for( i = 0 ; i < n ; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turn_around_time += turn_around_time[i];
    }

    avg_waiting_time /= n;
    avg_turn_around_time /= n;

    printf("Process no\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i = 0 ; i < n ; i++){
        printf("P[%d]\t\t%d\t\t%.0f\t\t%.0f\n", proc[i] , burst_time[i], waiting_time[i], turn_around_time[i]);
    }
    printf("Average Waiting Time = %.2fms\nAverage Turn Around Time = %.2fms\n" , avg_waiting_time , avg_turn_around_time);
}

void swap(int* x , int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
