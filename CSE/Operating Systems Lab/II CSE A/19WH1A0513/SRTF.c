#include <stdio.h>
int main(){
    int arrival_time[10], burst_time[10], temp[10];
    int i, smallest, count = 0, time, limit;
    double wait_time = 0, turnaround_time = 0, end;
    float average_waiting_time, average_turnaround_time;
    printf("Enter the Total Number of Processes:");
    scanf("%d", &limit); 
    printf("\n");
    for(i = 0; i < limit; i++){
        printf("Enter Arrival Time and Burst Time for process %d:",i);
        scanf("%d %d", &arrival_time[i],&burst_time[i]);
        temp[i] = burst_time[i];
    }
    burst_time[9] = 9999;  
    for(time = 0; count != limit; time++){
        smallest = 9;
        for(i = 0; i < limit; i++){
            if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0){
                smallest = i;
            }
        }
        burst_time[smallest]--;
        if(burst_time[smallest] == 0){
            count++;
            end = time + 1;
            wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
            turnaround_time = turnaround_time + end - arrival_time[smallest];
        }
    }
    average_waiting_time = wait_time / limit; 
    average_turnaround_time = turnaround_time / limit;
    printf("Average Waiting Time:%.2lf\n", average_waiting_time);
    printf("Average Turnaround Time:%.2lf", average_turnaround_time);
    return 0;
}
