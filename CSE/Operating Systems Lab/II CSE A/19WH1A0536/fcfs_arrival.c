//FCFS with arrival time

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
	int at[n], bt[n];
	for (int i = 0; i < n; i++){
		printf("Enter the arrival burst time of %d:",ord[i]);
		scanf("%d %d",&at[i],  &bt[i]);
	}
	int wt[n], tt[n], fwt[n];
	float sum_wt = 0.0;
	float sum_tt = 0.0;
	printf ("Process \t Arrival time \t Burst Time\tWaiting Time\tFinal Waiting time\tTurn Around Time ");
	for(int i = 0; i < n; i++){
		if(i == 0)
			wt[i] = 0;
		else{
			wt[i] = wt[i-1] + bt[i-1];
			fwt[i] =wt[i] - at[i];
		}
		
		tt[i] = bt[i] + fwt[i];
		
		sum_wt += fwt[i];
		sum_tt += tt[i];

		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t %d \t\t %d", ord[i],at[i],bt[i],wt[i],fwt[i],tt[i]);
	}
	
	printf("\nAvg Waiting : %.2f ", sum_wt/n);
	printf("\nAvg Turnaround : %.2f ", sum_tt/n);
	return 0;

}
