#include<stdio.h>

int main() {
	int num;
	printf("enter number of processes: ");
	scanf("%d", &num);

	int burstTimes[num], waitingTimes[num], turnAround_times[num];
	printf("\nenter burst times : \n");
	for (int i = 0; i < num; i++) {
		printf("process %d : ", i + 1);
		scanf("%d", &burstTimes[i]);
	}

	waitingTimes[0] = 0 ;
	for (int i = 1; i < num; i++) {
		waitingTimes[i] = 0;
		for (int j = 0; j < i; j++) {
			waitingTimes[i] += burstTimes[j];
		}
	}
	int tot_wt = 0;
        int tot_tat = 0;
	printf("\nProcess\t Burst Time\t Waiting Time \t Turnaround time");
	for (int i =0; i < num; i++ ) {
		turnAround_times[i] = burstTimes[i] + waitingTimes[i];
		tot_wt += waitingTimes[i];
		tot_tat += turnAround_times[i];
		printf("\n  %d\t\t%d \t\t %d \t\t %d", i + 1, burstTimes[i], waitingTimes[i], turnAround_times[i]);
	}

	int avg_wt = tot_wt / num;
	int avg_tat = tot_tat / num;
	printf("\n\nAverage Waiting time : %d", avg_wt);
	printf("\nAverage turnaround time : %d", avg_tat);
}	

