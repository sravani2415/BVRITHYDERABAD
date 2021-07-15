#include <stdio.h>
#include <math.h>

void bubble_sort(int [], int [], int);
void swap(int*, int*);

int main(){
    int n_proc, i;
    float wait_sum = 0, turn_sum = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n_proc);
    int burst_time[n_proc], processes[n_proc], waiting_time[n_proc] = {0}, turnaround_time[n_proc];
    for(i = 0; i < n_proc; i++){
        printf("Enter the burst time of process p(%d): ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1;
    }
    bubble_sort(burst_time, processes, n_proc);
    for(int j = 0; j < n_proc; j++){
        if(j != 0){
            waiting_time[j] = (burst_time[j - 1] + waiting_time[j- 1]);
            wait_sum += waiting_time[i];
            turnaround_time[j] = (burst_time[j] + turnaround_time[j - 1]);
            turn_sum += turnaround_time[j];
        }
        else{
            turnaround_time[j] = burst_time[j];
            wait_sum += waiting_time[i];
            turn_sum += turnaround_time[j];
        }
    }
    /*for(i = 0; i < n_proc; i++){
        wait_sum += waiting_time[i];
        turn_sum += turnaround_time[i];
    }*/

    printf("Process no.\tBurst time\tWaiting time\tTurnaround time\n");
    for(i = 0; i < n_proc; i++){
        printf("\tp(%d)\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting time: %2.2f ms\nAverage Turnaround time: %2.2f ms\n\n", (wait_sum/n_proc), turn_sum/n_proc);

}

void bubble_sort(int bt[], int p[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(bt[j] > bt[j + 1]){
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
