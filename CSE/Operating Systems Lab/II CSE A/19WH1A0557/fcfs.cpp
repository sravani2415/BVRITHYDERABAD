#include <stdio.h> 

int main(){ 
    int n_proc; 
	printf("Enter the number of processes: "); 
	scanf("%d", &n_proc); 
	int proc[n_proc], burst_time[n_proc], waiting_time[n_proc] = {0}, turnaround_time[n_proc]; 
	printf("\nEnter the order of processes in terms of 1,2,3,4,...n: "); 
	for(int i = 0; i < n_proc; i++){
	    scanf("%d", &proc[i]); } 
	for(int i = 0; i < n_proc; i++){
		printf("Enter the burst time of the process %d: ", proc[i]); 
		scanf("%d", &burst_time[i]); } 
	for(int i = 0; i < n_proc; i++){
		if(i == 0) turnaround_time[i] = burst_time[i]; 
		if(i > 0) turnaround_time[i] = burst_time[i] + turnaround_time[i - 1]; 
		if(i < n_proc - 1) waiting_time[i + 1] += (burst_time[i] + waiting_time[i]); } 
		float wait_sum = 0, turn_sum = 0; 
		printf("Process no.\tburst time\twaiting time\tturnaround time\n"); 
		for(int i = 0; i < n_proc; i++){ 
		wait_sum += waiting_time[i]; 
		turn_sum += turnaround_time[i]; 
		printf("\t%d\t\t%d\t\t%d\t\t%d\n", proc[i], burst_time[i], waiting_time[i], turnaround_time[i]); } 
		printf("Average Waiting time = %.2f\n", wait_sum/n_proc); 
		printf("Average Turn around time = %.2f",turn_sum/n_proc); 
		return 0; }
