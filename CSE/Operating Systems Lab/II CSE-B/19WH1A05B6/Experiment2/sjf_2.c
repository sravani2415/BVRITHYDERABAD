#include<stdio.h>
int main()
{
	int p[10],ar[10],br[10],wt[10],sum=0,wsum=0;
	int i,j,temp,n,btime,k=1,min;
	float avgw=0;
	printf("Enter no.of processes: \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter process name,arrival time and brust time \n");
		scanf("%d%d%d",&p[i],&ar[i],&br[i]);
		
	}
		
	for(j=0;j<n;j++)
	{
		btime=btime+br[j];
		min=br[k];
		for(i=k;i<n;i++)
		{
			if(btime>=ar[i] && br[i]<min)
			{
				temp=p[k];
				p[k]=p[i];
				p[i]=temp;
				temp=ar[k];
				ar[k]=ar[i];
				ar[i]=temp;
				temp=br[k];
				br[k]=br[i];
				br[i]=temp;
			}
		}
		k++;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		sum=sum+br[i-1];
		wt[i]=sum-ar[i];
		wsum=wsum+wt[i];
	}
	avgw=(wsum/n);
	printf("\nprocess\tBrust\tArrival\twaiting\n");
	for(i=0;i<n;i++)
		printf("\np%d\t%d\t%d\t%d\t",p[i],br[i],ar[i],wt[i]);
	printf("\nAverage waiting time : %f\n",avgw);
	return 0;
}
