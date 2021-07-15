#include <stdio.h>

int main(){
	int n, i, j;
	float avg_w, avg_t;
	printf("Enter no.of process: ");
	scanf("%d", &n);
	int p[n], b[n], w[n], t[n];
	printf("Enter process order: ");
	for(i = 0; i < n; i++)
	    scanf("%d", &p[i]);
	    
	// inputting Burst time
	
	for(i = 0; i < n; i++){
	    printf("Enter burst time of %d: ", p[i]);
		scanf("%d", &b[i]);
	} 
	
	
	w[0] = 0;
	t[0] = b[0];
	avg_w = w[0];
	avg_t = t[0];
	 
	for(i = 1; i < n; i++){
		w[i] = w[i-1] + b[i-1];
		t[i] = t[i-1] + b[i];
		avg_w += w[i];
		avg_t += t[i];
	} 
	
	printf("Process     Burst time     Waiting time    Turnaround time\n");
	for(i = 0; i < n; i++){
	printf(" p[%d]\t\t%d\t\t%d\t\t%d\n", p[i], b[i], w[i], t[i]);
	}
	 
	printf("Average waiting Time = %.2f\n", (avg_w / n));
	printf("Average Turn around Time = %.2f", (avg_t / n));
}































