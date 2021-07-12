#include<stdio.h>
#define size 30
int main()
{
	int i,j,n,bt[size],wt[size],pr[size],tat[size],pos,t;
	float awt = 0, atat = 0;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	printf("Enter the burst time:\n");
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d",&bt[i]);
	}
	printf("Enter the priority:\n");
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d",&pr[i]);
	}
	for(i = 0 ; i < n ; i++)
	{
		pos = i;
		for(j = i + 1 ; j < n ; j++)
		{
			if(pr[j] < pr[pos])
			{
				pos = j;
			}
		}
		t = pr[i];
		pr[i] = pr[pos];
		pr[pos] = t;
		
		t = bt[i];
		bt[i] = bt[pos];
		bt[pos] = t;
	}
	wt[0] = 0;
	printf("Process\tBurse time\tPriority\tWaiting time\tTurn around time\n");
	for(i = 0 ; i < n; i++)
	{
		wt[i] = 0;
		tat[i] = 0;
		for(j = 0 ; j < i ; j++)
		{
			wt[i] += bt[j];
		}
		tat[i] = wt[i] + bt[i];
		awt = awt + wt[i];
		atat = atat +tat[i];
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i + 1,bt[i],pr[i],wt[i],tat[i]);
 	}
 	awt = awt/n;
 	atat = atat/n;
 	printf("AVERAGE WAITING TIME:%f\n",awt);
 	printf("AVERAGE TURN AROUND TIME:%f",atat);
 	return 0;
}
