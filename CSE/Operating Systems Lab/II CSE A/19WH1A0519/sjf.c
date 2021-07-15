#include<stdio.h>

int main() {
	int num;
	float avg_wt, avg_tat;
	printf("enter number of processes : ");
	scanf("%d", &num);
	int burstTimes[num], turnAround_times[num], waitingTimes[num], processes[num];
	printf("\nEnter Burst Times:\n");
	for (int i = 0; i < num; i++){
		printf("Process %d : ", i + 1);
		scanf("%d", &burstTimes[i]);
		processes[i] = i + 1;
	}

        int pos, temp;
	for (int i = 0; i < num; i++){
		pos = i;
		for (int j = i + 1; j < num; j++){
			if (burstTimes[j] < burstTimes[pos]) {
				pos = j;
			}
		}
		temp = burstTimes[i];              //swapping
		burstTimes[i] = burstTimes[pos];
		burstTimes[pos] = temp;

		temp = processes[i];
		processes[i] = processes[pos];
		processes[pos] = temp;
	}

	waitingTimes[0] = 0;	//first process has zero waiting time
	int total_wt = 0;
	for (int i = 1; i < num; i++) {
		waitingTimes[i] = 0;
		for (int j = 0; j < i; j++){
			waitingTimes[i] += burstTimes[j];
		}
		total_wt += waitingTimes[i];
	}

	avg_wt = (float) total_wt / num;  //avergae waiting time;

	int total_tat = 0;

	printf("\nProcess\t Burst Time\t Waiting Times\t Turnaround Time");
	for (int i = 0; i < num; i++) {
		turnAround_times[i] = burstTimes[i] + waitingTimes[i];
		total_tat += turnAround_times[i];
		printf("\n   %d\t\t%d\t\t %d\t\t %d", processes[i], burstTimes[i], waitingTimes[i], turnAround_times[i]);
	}

	avg_tat = (float) total_tat / num;   //avg turn around time

	printf("\n\nAverage waiting time: %f", avg_wt);
	printf("\nAverage turnaround time: %f", avg_tat);
}



