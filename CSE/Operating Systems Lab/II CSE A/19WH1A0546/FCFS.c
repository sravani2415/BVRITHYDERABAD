#include<stdio.h>

int main() {
    int n;
    printf("Enter no of processes : ");
    scanf("%d", &n);

    int order[n];
    printf("Enter the order of processes in terms of 1,2,3,...n: ");
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &order[i]);
    }

    int burst_time[n];
    for (int i = 0 ; i < n ; i++) {
        printf("Enter the burst time of the processes %d : ",order[i]);
        scanf("%d", &burst_time[i]);
    }

    float waiting_time[n];
    waiting_time[0] = 0;
    for(int i = 1 ; i < n ; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }

    float turn_around_time[n];
    turn_around_time[0] = burst_time[0];
    for(int i = 1 ; i < n ;i++) {
        turn_around_time[i] = burst_time[i] + waiting_time[i];
    }

    float avg_waiting_time = 0 , avg_turn_around_time = 0;
    for(int i = 0 ; i < n ;i++) {
        avg_waiting_time += waiting_time[i];
    }
    for(int i = 0 ; i < n ;i++) {
        avg_turn_around_time += turn_around_time[i];
    }

    avg_waiting_time = avg_waiting_time/n;
    avg_turn_around_time = avg_turn_around_time / n;

    printf("Process no\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(int i = 0 ; i < n ; i++){
        printf("%d\t\t%d\t\t%.0f\t\t%.0f\n", order[i] , burst_time[i], waiting_time[i], turn_around_time[i]);
    }
    printf("Average Waiting Time = %.2f\nAverage Turn Around Time = %.2f\n" , avg_waiting_time , avg_turn_around_time);
}
