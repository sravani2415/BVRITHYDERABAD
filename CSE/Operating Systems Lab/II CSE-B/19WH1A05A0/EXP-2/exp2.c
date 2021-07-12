#include<stdio.h>
int main()
{
	int n, i, j, bt, k = 1, min, t;
	printf("enter no. of processes\n");
	scanf("%d", &n);
	int p[n], a[n], b[n], w[n];
	printf("enter arrival and burst time\n");
	for( i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		p[i] = i + 1;
	}
	for(j = 0; j < n; j++)
	{
		bt = bt + b[j];
		min = b[k];
		for(i = k; i < n; i++)
		{
			if(bt >= a[i] && b[i] < min)
			{
				t = p[k];
				p[k] = p[i];
				p[i] = t;
				t  = a[k];
				a[k] = a[i];
				a[i] = t;
				t = b[k];
				b[k] = b[i];
				b[i] = t;
			}
		}
		k++;
	}
	w[0] = 0;
	int sum = 0, wsum = 0;
	for(i = 1; i < n; i++)
	{
		sum += b[i -1];
		w[i] = sum - a[i];
		wsum += w[i];
	}
	float avg_w = wsum /(float) n;
	printf("\nProcess\tArrival\tBurst\tWaiting\n");
	for(i = 0; i < n; i++)
		printf("p%d\t%d\t%d\t%d\t\n", p[i], a[i], b[i], w[i]);
	printf("Average waiting time is %f\n", avg_w);
	return 0;
}

	