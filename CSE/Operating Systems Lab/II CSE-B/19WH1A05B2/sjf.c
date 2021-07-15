#include<stdio.h>
int main()
{
	int pn[10],at[10],bt[10],wt[10];
	int n,t,btime,k=1,min,i;
	float wavg;
	printf("Enter number of processes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter process name, Arrival time & Burst time\n");
		scanf("%d%d%d",&pn[i],&at[i],&bt[i]);
	}
	for(int j=0;j<n;j++)
	{
		btime=btime+bt[j];
		min=bt[k];
		for(i=k;i<n;i++)
		{
			if (btime>=at[i] && bt[i]<min)
			{
				t=pn[k];
				pn[k]=pn[i];
				pn[i]=t;
				t=at[k];
				at[k]=at[i];
				at[i]=t;
				t=bt[k];
				bt[k]=bt[i];
				bt[i]=t;
			}
		}
		k++;
	}
	wt[0] = 0;
	int sum=0,wsum=0;
	for(i=1;i<n;i++)
	{
		sum=sum+bt[i-1];
		wt[i]=sum-at[i];
		wsum=wsum+wt[i];
	}
	wavg=(wsum/n);
	printf("\nProcess\t Burst\t Arrival\t Waiting\t" );
	for(i=0;i<n;i++)
	{
		printf("\n p%d\t %d\t %d\t\t %d\t",pn[i],bt[i],at[i],wt[i]);
	}
	printf("\n\nAVERAGE WAITING TIME : %.1f\n",wavg);
	return 0;
}
