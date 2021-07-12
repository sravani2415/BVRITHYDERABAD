#include<stdio.h>
int main()
{
    int burst_time[10],arrival[10],wait_time[10],p[10];
	int n,i,j,k=1,temp,min,bt,total;
	float avg_wait; 
	avg_wait = total = 0;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter arrival time and burst time for process %d ",i);
		scanf("%d %d",&arrival[i],&burst_time[i]);
		p[i] = i + 1;
	}
	for(j=0;j<n;j++)
    {
    	bt = bt + burst_time[j];
    	min = burst_time[k];
    	for(i=k;i<n;i++)
    	{
    		if(bt >= arrival[i] && burst_time[i] < min)
    		{
    			temp = p[k];
    			p[k] = p[i];
    			p[i] = temp;
    			temp = arrival[k];
    			arrival[k] = arrival[i];
    			arrival[i] = temp;
    			temp = burst_time[k];
    			burst_time[k] = burst_time[i];
    			burst_time[i] = temp;	
			}
		}
		k++;
    }
    wait_time[0] = 0;
	for(i=0;i<n;i++)
	{
		total += burst_time[i-1];
		wait_time[i] = total - arrival[i];
		avg_wait += wait_time[i];
	}
    printf("Process\tArrival\tBurst\tWaiting");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t%d\t%d\t%d",p[i],arrival[i],burst_time[i],wait_time[i]);
	}
    printf("\n Average waiting time = %f",avg_wait/n);
    return 0;
}
