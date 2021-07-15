#include <stdio.h>
void bubble_sort(int [], int [], int [], int);
void swap(int*, int*);
int main(){
    int n_proc;
    printf("Enter the number of processes: ");
    scanf("%d", &n_proc);
    int proc[n_proc], burst_time[n_proc], arrival_time[n_proc], waiting_time[n_proc] = {0}, turnaround_time[n_proc];
    printf("\nEnter the order of processes in terms of 1,2,3,4,...n:");
    for(int i = 0; i < n_proc; i++){
        scanf("%d", &proc[i]);
    }
    for(int i = 0; i < n_proc; i++){
        printf("Enter the arrival time and burst time of the process p(%d): ", proc[i]);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    bubble_sort(arrival_time, burst_time, proc, n_proc);
    for(int i = 0; i < n_proc; i++){
        waiting_time[i + 1] += (burst_time[i] + waiting_time[i]);
        waiting_time[i] -= arrival_time[i];
    }
    arrival_time[0] = 0;
    for(int i = 0; i < n_proc; i++){
        turnaround_time[i] = (waiting_time[i] + burst_time[i]);
    }
    float wait_sum = 0, turn_sum = 0;
    printf("Process no.\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
    for(int i = 0; i < n_proc; i++){
        wait_sum += waiting_time[i];
        turn_sum += turnaround_time[i];
        printf("\tp(%d)\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i], arrival_time[i],burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting time = %.2f ms\n", wait_sum/n_proc);
    printf("Average Turn around time = %.2f ms\n",turn_sum/n_proc);
    return 0;
}
void bubble_sort(int at[], int bt[], int p[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(at[j] > at[j + 1]){
                swap(&at[j], &at[j + 1]);
                swap(&bt[j], &bt[j + 1]);
                swap(&p[j], &p[j + 1]);
            }
        }
    }
}
void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

