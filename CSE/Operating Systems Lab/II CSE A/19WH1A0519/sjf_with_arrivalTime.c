#include<stdio.h>

int main() {
	int n, temp, tt = 0,min, d, i, j;
	float atat = 0, awt = 0, stat = 0, swt = 0;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	int arrival[10], burst[10], tat[10], et[10], wt[10];
	for (i = 0; i < n; i++) {
		printf("enter arrival and burst times of p[%d]: ", i+1);
		scanf("%d%d", &arrival[i], &burst[i]);
	}
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (burst[i] > burst[j]) {
				temp = arrival[i];
				arrival[i] = arrival[j];
				arrival[j] = temp;
				temp = burst[i];
				burst[i] = burst[j];
				burst[j] = temp;
			}
		}
	}
	min = arrival[0];
	for (i = 0; i < n; i++) {
		if (min > arrival[i]) {
			min = arrival[i];
			d = i;
		}
	}
	tt = min;
	et[d] = tt + burst[d];
	tt = et[d];
	for (i = 0; i < n; i++) {
		if (arrival[i] != min) {
			et[i] = burst[i] + tt;
			tt = et[i];
		}
	}
	for (i = 0; i < n; i++) {
		tat[i] = et[i] - arrival[i];
		stat = stat + tat[i];
		wt[i] = tat[i] - burst[i];
		swt = swt + wt[i];
	}
	atat = stat / n;
	awt = swt / n;
	printf("Process  Arrival time  Burst Time     Waiting Time  Turn Around Time\n");
	for (i = 0; i < n; i++) {
		printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arrival[i], burst[i], wt[i], tat[i]);
	}
	printf("\naverage waiting time = %f", awt);
	printf("\naverage turn around time = %f\n", atat);
}


