#include<stdio.h>

int main() {
    int n;
    printf("Enter no of processes : ");
    scanf("%d", &n);
    int burst_time[n], order[n];
    for(int i = 0 ; i < n ; i++) {
        printf("Enter burst time of process %d : ", i+1);
        scanf("%d", &burst_time[i]);
    }
    for(int  i = 0 ; i < n ; i++ ) {
        order[i] = i+1;
    }

    int time_quantum;
    printf("Enter time quantum : ");
    scanf("%d", &time_quantum);

    int remaining_burst_time[n];
    int waiting_time[n], turn_around_time[n];

    for(int i = 0 ; i < n ; i++) {
        remaining_burst_time[i] = burst_time[i];
    }

    int sum = 0, t = 0;
    for(int i = 0 ; i < n ; i++) {
        sum += burst_time[i];
    }

    printf("\n");

    while (t < sum) {
        for (int i = 0 ; i < n ;i++) {
            if (remaining_burst_time[i] > 0) {
                if (remaining_burst_time[i] > time_quantum) {
                    t += time_quantum;
                    remaining_burst_time[i] -= time_quantum;
                }
                else {
                    t += remaining_burst_time[i];
                    waiting_time[i] = t- burst_time[i];
                    remaining_burst_time[i] = 0;
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++) {
        turn_around_time[i] = burst_time[i] + waiting_time[i];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(int i = 0 ; i < n ; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", order[i], burst_time[i], waiting_time[i], turn_around_time[i]);
    }

    int avg_waiting_time = 0, avg_turn_around_time = 0;
    for (int i = 0 ; i < n ; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turn_around_time += turn_around_time[i];
    }
    printf("Average Waiting Time = %d\nAverage Turn Around Time = %d", avg_waiting_time/n, avg_turn_around_time/n);
    return 0;
}
