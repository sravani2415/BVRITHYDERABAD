//FCFS without arrival time

#include<stdio.h>

int main(){
	int i;
	int n;
	printf("Enter the number of inputs:");
	scanf("%d",&n);
	
	int ord[n];
	printf("Enter the order of inputs:");
	for(int i = 0; i < n; i++)
		scanf("%d",&ord[i]);
	int bt[i];
	for (int i = 0; i < n; i++){
		printf("Enter the burst time of %d:",ord[i]);
		scanf("%d",&bt[i]);
	}
	int wt[i], tt[i];
	float sum_wt = 0.0;
	float sum_tt = 0.0;
	printf ("Process \t Burst Time\tWaiting Time\tTurn Around Time ");
	for(int i = 0; i < n; i++){
		if (i == 0)
			wt[i] = 0;
		else
			wt[i] = wt[i-1] + bt[i-1];
		
		tt[i] = bt[i] + wt[i];
		
		sum_wt += wt[i];
		sum_tt += tt[i];

		printf("\n  %d  \t\t  %d \t\t   %d \t\t %d", ord[i],bt[i],wt[i],tt[i]);
	}
	
	printf("\nAvg Waiting : %.2f ", sum_wt/n);
	printf("\nAvg Turnaround : %.2f ", sum_tt/n);
	return 0;

}
