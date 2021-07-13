#include<stdio.h>
int main()
{
	int pn[10],bt[10],pr[10],wt[10],n,i,j,temp,pos,tat[10],total,wsum;
	float avg_wt,avg_tat;
	printf("Enter No of Processes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter process name,Priority and Burst Time\n");
		scanf("%d%d%d",&pn[i],&pr[i],&bt[i]);
	}
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(pr[j]>pr[pos])
				pos=j;
		}
		temp=pr[i];
		pr[i]=pr[pos];
		pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=pn[i];
        pn[i]=pn[pos];
        pn[pos]=temp;
	}
	wt[0]=0;
	wsum = 0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
		{
			wt[i]+=bt[j];
		}
		wsum += wt[i];

	}
	avg_wt = (float)wsum/n;
	total=0;
	printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
        for(i=0;i<n;i++)
	{
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",pn[i],bt[i],wt[i],tat[i]);
	}
	avg_tat=total/n;
	printf("\n\nAverage Waiting Time=%f",avg_wt);
        printf("\nAverage Turnaround Time=%f\n",avg_tat);
	return 0;
}
