#include <stdio.h>

void bubble_sort(int[], int[], int[], int);
void swap(int*, int*);

int main(){
    int n_proc, i;
    printf("Enter number of processes: ");
    scanf("%d", &n_proc);
    int processes[n_proc],  turnaround_time[n_proc], burst_time[n_proc], priority[n_proc], waiting_time[n_proc];
    for(i = 0; i < n_proc; i++)
        waiting_time[i] = 0;
    float wait_sum, turn_sum;
    for(i = 0; i < n_proc; i++){
        printf("Enter the burst time and priority of process(%d): ", i + 1);
        processes[i] = i + 1;
        scanf("%d %d", &burst_time[i], &priority[i]);
    }
    bubble_sort(priority, burst_time, processes, n_proc);
    for(i = 0; i < n_proc; i++){
        waiting_time[i + 1] += waiting_time[i] + burst_time[i];
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        wait_sum += waiting_time[i];
        turn_sum += turnaround_time[i];
    }
    printf("\n\tProcess\t\tBurst time\tPriority\tWaiting time\tTurnaround time\n");
    for(i = 0; i < n_proc; i++){
        printf("\tp(%d)\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage waiting time: %.2fms\nAverage turnaround time: %.2fms\n", wait_sum/n_proc, turn_sum/n_proc);
}

void bubble_sort(int prio[], int bt[], int p[], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0;j < n - i - 1; j++){
            if(prio[j] > prio[j + 1]){
                swap(&prio[j], &prio[j + 1]);
                swap(&bt[j], &bt[j + 1]);
                swap(&p[j], &p[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

