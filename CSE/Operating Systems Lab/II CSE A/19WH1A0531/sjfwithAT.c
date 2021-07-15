#include <stdio.h>

void shortest_arrival(int [], int [], int [], int);
void bubble_sort(int [], int [], int[], int);
void swap(int*, int*);

int main(){
    int n, i;
    float wait_sum = 0, turn_sum = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int burst_time[n], proc[n], arrival_time[n], waiting_time[n], turnaround_time[n];
    for(i = 0; i < n; i++){
        printf("Enter arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        proc[i] = i + 1;
        waiting_time[i] = 0;
    }
    shortest_arrival(arrival_time, burst_time, proc, n);
    bubble_sort(burst_time, arrival_time, proc, n);

    for(i = 0; i < n; i++){
        waiting_time[i + 1] += (burst_time[i] + waiting_time[i]);
        waiting_time[i] -= arrival_time[i];
    }

    for(i = 0; i < n; i++){
        turnaround_time[i] = (waiting_time[i] + burst_time[i]);
    }
    for(i = 0; i < n; i++){
        wait_sum += waiting_time[i];
        turn_sum += turnaround_time[i];
    }
    arrival_time[0] = 0;
    printf("Process no.\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
    for(i = 0; i < n; i++){
        printf("\tp[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i], arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting time: %2.2f ms\nAverage Turnaround time: %2.2f ms\n\n", (wait_sum/n), turn_sum/n);

}

void shortest_arrival(int arrival_time[], int burst_time[], int proc[], int n){
    int min = arrival_time[0], j, i;
    for(i = 1; i < n; i++){
        if(min > arrival_time[i]){
            min = arrival_time[i];
            j = i;
        }
    }
    swap(&arrival_time[j], &arrival_time[0]);
    swap(&burst_time[j], &burst_time[0]);
    swap(&proc[j], &proc[0]);
}

void bubble_sort(int burst_time[], int arrival_time[], int proc[], int n){
    int i, j;
	for(i = 0; i < n; i++){
        for( j = 1; j < n - i - 1; j++){
            if(burst_time[j] > burst_time[j + 1]){
                swap(&burst_time[j], &burst_time[j + 1]);
                swap(&arrival_time[j], &arrival_time[j + 1]);
                swap(&proc[j], &proc[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}
