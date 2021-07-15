#include<stdio.h>

int main() {
	int bt[10], p[10], tat[10], wt[10], pr[10];
	int i, j, n, tot = 0, pos, avg_wt, avg_tat, tmp;
	printf("Enter number of processes: ");
	scanf("%d", &n);

	printf("\nEnter burst times and priorties\n");
	for (i = 0; i < n; i++) {
		printf("\nP[%d] burst time and priority: ", i + 1);
		scanf("%d%d", &bt[i], &pr[i]);
		p[i] = i + 1;
	}

	for (i = 0; i < n; i++) {
		pos = i;
 		for (j = i + 1; j < n; j++) {
			if (pr[j] < pr[pos])
				pos = j;
		}
		tmp = pr[i];
                pr[i] = pr[pos];
                pr[pos] = tmp;

                tmp = bt[i];
                bt[i] = bt[pos];
                bt[pos] = tmp;

		tmp = p[i];
		p[i] = p[pos];
		p[pos] = tmp;
	}
	wt[0] = 0;
	for (i = 1; i < n; i++) {
		wt[i] = 0;
		for (j = 0; j < i; j++) {
			wt[i] += bt[j];
		}
		tot += wt[i];
	}
	avg_wt = tot / n;
	tot = 0;
	printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
	for (i = 0; i < n;i++) {
		tat[i] = bt[i] + wt[i];
		tot += tat[i];
		printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i], bt[i], wt[i], tat[i]);
	}
	avg_tat = tot/n;
	printf("\n\nAvg waiting time = %d", avg_wt);
	printf("\nAvg turn around time = %d", avg_tat);
	return 0;
}	

