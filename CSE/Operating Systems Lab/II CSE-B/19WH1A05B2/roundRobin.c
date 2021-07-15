#include<stdio.h> 
int main() 
{
	int wt=0,tat=0,pn[10],at[10],bt[10],rt[10];
	int i,sum=0,count=0,n,t[10],y,quant;
	float avg_wt,avg_tat;
	printf("Enter Total Process:\t "); 
	scanf("%d",&n);
	y = n;
	for(int i=0;i<n;i++)
	{
		printf("Enter process name,Arrival Time & Burst time ");
		scanf("%d%d%d",&pn[i],&at[i],&bt[i]);
		t[i]=bt[i];
	}
	printf("Enter Time Quantum:");
	scanf("%d",&quant);
	printf("\nProcess Name\tBurst Time\t TAT\tWaiting Time ");
	for(sum=0, i = 0; y!=0; )
	{
		if(t[i] <= quant && t[i] > 0)
		{
			sum += t[i];
			t[i] = 0;
			count=1;
		}
		else if(t[i] > 0)
		{
			t[i] = t[i] - quant;
			sum += quant;
		}
		if(t[i]==0 && count==1)
		{
			y--;
			printf("\nP[%d]\t\t%d\t\t%d\t\t%d", pn[i], bt[i], sum-at[i], sum-at[i]-bt[i]);
			wt = wt+sum-at[i]-bt[i];
			tat = tat+sum-at[i];
			count =0;
		}
		if(i==n-1)
		{
			i=0;
		}
		else if(at[i+1]<=sum)
		{
			i++;
		}
		else
		{
			i=0;
		}
	}
	avg_wt = wt * 1.0/n;
	avg_tat = tat * 1.0/n;
	printf("\nAverage Turn Around Time: %.2f\n", avg_wt);
	printf("Average Waiting Time: %.2f\n", avg_tat);
	return 0;
}   

