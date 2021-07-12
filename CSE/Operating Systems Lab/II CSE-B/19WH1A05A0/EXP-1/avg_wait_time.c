#include<stdio.h>
int main()
{
	int arr[20], exe[20], n, wait_time = 0, i;
	float avg_time;
	scanf("%d", &n);
	int s[n];
	s[0] = 0;
	printf("Arrival\n");
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("Execution\n");
	for(i = 0; i < n; i++)
		scanf("%d", &exe[i]);
	for(i = 1; i < n; i++)
		s[i] = s[i - 1] + exe[i - 1];
	for(i = 1; i < n; i ++)
		wait_time += s[i] - arr[i];
	avg_time = (float)wait_time / n;
	printf("average time %f\n", avg_time);
}
	