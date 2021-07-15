#include<stdio.h>
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
	int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
	int bt[10],temp,j,at[10],wt[10],tt[10],ta=0,sum=0;
	float wavg=0,tavg=0,tsum=0,wsum=0;
	printf("Enter the No. of processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the burst time and arrival time of %d process : ",i+1);
		scanf(" %d %d",&bt[i],&at[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(at[i]<at[j]){
				swap(&p[i],&p[j]);
				swap(&at[i],&at[j]);
				swap(&bt[i],&bt[j]);
			}
		}
	}
	for(j=0;j<n;j++){
		btime=btime+bt[j];
		min=bt[k];
		for(i=k;i<n;i++){
			if (btime>=at[i] && bt[i]<min){
				swap(&p[i],&p[k]);
				swap(&at[i],&at[k]);
				swap(&bt[i],&bt[k]);
			}
		}
		k++;
	}
	wt[0]=0;
	for(i=1;i<n;i++){
		sum=sum+bt[i-1];
		wt[i]=sum-at[i];
		wsum=wsum+wt[i];
	}
 	wavg=(wsum/n);
	for(i=0;i<n;i++){
		ta=ta+bt[i];
		tt[i]=ta-at[i];
		tsum=tsum+tt[i];
	}
	tavg=(tsum/n);
	printf("Process no.\tBurst Time\tArrival time\tWaiting time\tTurn-around time\n");
	for(i=0;i<n;i++){
	printf("   p[%d]\t\t   %d\t\t   %d\t\t   %d\t\t   %d\n",p[i],bt[i],at[i],wt[i],tt[i]);
	}
	printf("\nAverage waiting time = %.2f",wavg);
	printf("\nAverage turnaround time = %.2f",tavg);
	return 0;
}