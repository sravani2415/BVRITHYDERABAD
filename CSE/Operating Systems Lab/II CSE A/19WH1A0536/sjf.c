//SJF without arrival time

#include<stdio.h>

int main(){
        int i;
        int n;
	int bt[n];
        printf("Enter the number of inputs:");
        scanf("%d",&n);

	for(i = 0; i < n; i++){
		printf("Enter the burst time of p%d : ",i);
		scanf("%d",&bt[i]);
	}
	//int bt[n];
	int temp, j;
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n-i-1; j++){
			if (bt[j] > bt[j+1]){
				swap(&bt[j], &bt[j+1]);
			}
		}
	}
	int wt[n], tt[n];
	float sum_wt = 0.0;
	float sum_tt = 0.0;

	printf("Process\tBurst Time\tWaiting Time\tTurnaround Time");
	for(i = 0; i < n; i++){
		if (i == 0)
			wt[i] = 0;
		else
			wt[i] = wt[i-1] + bt[i-1];

		tt[i] = bt[i]+wt[i];

		sum_wt += wt[i];
		sum_tt += tt[i];

		printf("\np%d\t\t%d\t\t%d\t\t%d",i,bt[i],wt[i],tt[i]);

	}

	printf("\nAvg waiting : %.2f",sum_wt/n);
	printf("\nAvg Turnaround : %.2f",sum_tt/n);
		return 0;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

