#include<stdio.h>

void swap(int*, int*);

int main() {
    int n;
    printf("Enter no of processes : ");
    scanf("%d", &n);
    int order[n], priority[n], burst_time[n];
    for(int i = 0 ; i < n ; i++) {
        printf("Enter burst time and priority of process %d : ", i+1);
        scanf("%d %d", &burst_time[i], &priority[i]);
    }

    for(int i = 0 ; i < n ; i++) {
        order[i] = i+1;
    }

    for (int i = 0 ; i < n ; i++) {
        for (int  j = 0 ; j  < n - i - 1 ; j++) {
            if (priority[j] > priority[j+1]) {
                swap(&burst_time[j], &burst_time[j+1]);
                swap(&order[j], &order[j+1]);
                swap(&priority[j], &priority[j+1]);
            }
        }
    }

    int turn_around_time[n], waiting_time[n];
    waiting_time[0] = 0;
    for(int i = 1 ; i < n ; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }

    for(int i = 0 ; i < n ; i++) {
        turn_around_time[i] = burst_time[i] + waiting_time[i];
    }
    printf("\nProcess\t\tBurst Time\tPriority\tWaiting Time\tTurn Around Time\n");
    for(int i = 0 ; i < n ; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", order[i], burst_time[i], priority[i], waiting_time[i], turn_around_time[i]);
    }
    int avg_waiting_time = 0, avg_turn_around_time = 0;
    for (int i = 0 ; i < n ; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turn_around_time += turn_around_time[i];
    }
    printf("Average Waiting Time = %d\nAverage Turn Around Time = %d", avg_waiting_time/n, avg_turn_around_time/n);

}

void swap(int* x , int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
