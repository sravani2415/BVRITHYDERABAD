#include <stdio.h>

void min_arrival(int [], int [], int [], int);
void bubble_sort(int [], int [], int[], int);
void swap(int*, int*);

int main(){
    int n_proc, i;
    float wait_sum = 0, turn_sum = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n_proc);
    int burst_time[n_proc],int  processes[n_proc], int arrival_time[n_proc],int  waiting_time[n_proc] = {0},int  turnaround_time[n_proc];
    for(i = 0; i < n_proc; i++){
        printf("Enter the arrival time and burst time of process p(%d): ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        processes[i] = i + 1;
    }
    min_arrival(arrival_time, burst_time, processes, n_proc);
    bubble_sort(burst_time, arrival_time, processes, n_proc);

    for(i = 0; i < n_proc; i++){
        waiting_time[i + 1] += (burst_time[i] + waiting_time[i]);
        waiting_time[i] -= arrival_time[i];
    }

    for(i = 0; i < n_proc; i++){
        turnaround_time[i] = (waiting_time[i] + burst_time[i]);
    }
    for(i = 0; i < n_proc; i++){
        wait_sum += waiting_time[i];
        turn_sum += turnaround_time[i];
    }
    arrival_time[0] = 0;
    printf("Process no.\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
    for(i = 0; i < n_proc; i++){
        printf("\tp(%d)\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting time: %2.2f ms\nAverage Turnaround time: %2.2f ms\n\n", (wait_sum/n_proc), turn_sum/n_proc);

}

void min_arrival(int at[], int bt[], int p[], int n){
    int min = at[0], j;
    for(int i = 1; i < n; i++){
        if(min > at[i]){
            min = at[i];
            j = i;
        }
    }
    swap(&at[j], &at[0]);
    swap(&bt[j], &bt[0]);
    swap(&p[j], &p[0]);
}

void bubble_sort(int bt[], int at[], int p[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n - i - 1; j++){
            if(bt[j] > bt[j + 1]){
                swap(&bt[j], &bt[j + 1]);
                swap(&at[j], &at[j + 1]);
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