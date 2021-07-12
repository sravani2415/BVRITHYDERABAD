#include<stdio.h>
int main()
{
	int pn[10],bt[10],prior[10],wt[10];
	int n,i,j,t,pos,tat[10],total,wsum;
	float wAvg,tatAvg;
	printf("Enter No of Processes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Process : ");
		scanf("%d",&pn[i]);
		printf("Priority : ");
		scanf("%d",&prior[i]);
		printf("Burst Time : ");
		scanf("%d",&bt[i]);
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(prior[j]>=prior[pos])
				pos=j;
		}
		t=prior[i];
		prior[i]=prior[pos];
		prior[pos]=t;
		t=bt[i];
        bt[i]=bt[pos];
        bt[pos]=t;
        t=pn[i];
        pn[i]=pn[pos];
        pn[pos]=t;
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
	wAvg = (float)wsum/n;
	total=0;
	printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
	{
        tat[i]=bt[i]+wt[i];     
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",pn[i],bt[i],wt[i],tat[i]);
	}
	tatAvg=(float)total/n;
	printf("\n\nAverage Waiting Time=%f",wAvg);
    printf("\nAverage Turnaround Time=%f\n",tatAvg);
	return 0;
}