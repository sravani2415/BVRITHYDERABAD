#include<stdio.h>
int main(){
	int n, i, j, prior, sum;
	float avg_w=0, avg_t=0;
	printf("Enter No.of Processes: ");
	scanf("%d", &n);
	int priority[n], bt[n], wt[n], tat[n];
	for(i = 0; i <= n-1; i++){
		printf("Enter Priority and BurstTime of process (%d): ", i+1);
		scanf("%d%d", &priority[i],&bt[i]);
	}
    for(i = 0; i < n; i++){
    	prior = priority[i];
    	sum = 0;
    	if(prior == 1)
    	    wt[i] = 0;
    	else{
    		for(j = 0; j < n; j++){
    			if(priority[j] < prior)
    			     sum += bt[j];
			}
			wt[i] = sum;
		}
		tat[i] = bt[i] + wt[i];
		avg_w += wt[i];
		avg_t += tat[i];
	}
	printf("Process     Burst time     Priority     Waiting time    Turnaround time\n");
	for(i = 0; i < n; i++){
		printf(" p%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], priority[i], wt[i], tat[i]);
	}
	
	printf("Average waiting Time = %.2f\n", (avg_w / n));
	printf("Average Turn around Time = %.2f", (avg_t / n));
}
