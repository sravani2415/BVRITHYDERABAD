#include<stdio.h>
int main()
{
	int pr,i;
	float avg,x;
	int st[10],AT[10],Wt[10],ET[10],p[10];
	Wt[0]=0;
	printf("Enter the number of processes\n");
	scanf("%d",&pr);
	printf("             Process\tarr_time  exe_time\n");
	for(i=0;i<pr;i++)
	{
		printf("Enter details:");
		scanf("%d        %d         %d",&p[i],&AT[i],&ET[i]);
	}
	for(i=0;i<pr;i++)
	{
		if(i==0)
			st[i] = 0;
		else
			st[i] = ET[i-1] + st[i-1];	
	}
	x = Wt[0];
	for(i=0;i<pr;i++)
	{
		Wt[i]=st[i]-AT[i];
		x+=Wt[i];
	}
	avg = x/pr ;
	printf("...OUTPUT...\n");
	printf("Process\tarr_time exe_time service_time\n");
	for(i=0;i<pr;i++)
	{
		printf("%d\t%d\t  %d\t  %d\n",p[i],AT[i],ET[i],st[i]);
	}
	printf("Average of waiting time = %f\n",avg);
	return 0;
}		