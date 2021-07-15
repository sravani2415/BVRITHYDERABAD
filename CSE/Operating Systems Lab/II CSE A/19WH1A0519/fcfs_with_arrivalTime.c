#include<stdio.h>

int main(){
	printf("enter number of processes : ");
	int n, sum = 0;
	float tot_wt = 0, tot_tat = 0;
	scanf("%d", &n);
	int burstTimes[n], arrivalTimes[n], waitingTimes[n], ta_times[n], completionTimes[n];
	printf("Enter arrival and burst times of each process\n");
	for (int i = 0; i < n; i++){
		printf("Arrival time and burst time of p[%d] : ", i + 1);
		scanf("%d %d", &arrivalTimes[i], &burstTimes[i]);
	}

	for (int i = 0; i < n; i++) {
		sum += burstTimes[i];
		completionTimes[i] += sum;
	}

	for (int i = 0; i < n; i++ ) {
		ta_times[i] = completionTimes[i] - arrivalTimes[i];
	        tot_tat += ta_times[i];
	}
	for (int i = 0; i < n; i++) {
		waitingTimes[i] = ta_times[i] - burstTimes[i];
		tot_wt += waitingTimes[i];
	}
	printf("\nProcess \tArrival time \t Burst time \t Waiting time \t Turn around time\n");
	for (int i = 0; i < n ; i++ ) {
		printf("   %d \t\t  %d  \t\t    %d \t\t      %d \t\t   %d\n", i + 1, arrivalTimes[i], burstTimes[i], waitingTimes[i], ta_times[i]);
	}
	printf("\n\nAverage waiting time : %f", tot_wt / n);
	printf("\nAverage turn around time : %f", tot_tat / n);
}	




