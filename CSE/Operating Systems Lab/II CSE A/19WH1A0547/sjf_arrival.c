#include<stdio.h>
int main(){
	int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
	int bt[10],temp,j,at[10],wt[10],tt[10],ta=0,sum=0;
	float wavg=0,tavg=0,tsum=0,wsum=0;
	int swap(int *a,int *b);
	printf("Enter the No. of processes :");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the burst time and arrival time of process p[%d] :",i+1);
		scanf(" %d %d",&bt[i],&at[i]);}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(at[i]<at[j]){
				swap(&p[j],&p[i]);
				swap(&at[j],&at[i]);
				swap(&bt[j],&bt[i]);}}}
	for(j=0;j<n;j++){
		btime=btime+bt[j];
		min=bt[k];
		for(i=k;i<n;i++){
			if (btime>=at[i] && bt[i]<min){
				swap(&p[k],&p[i]);
				swap(&at[k],&at[i]);
				swap(&bt[k],&bt[i]);}}
		k++;}
	wt[0]=0;
	for(i=1;i<n;i++){
		sum=sum+bt[i-1];
		wt[i]=sum-at[i];
		wsum=wsum+wt[i];}
	wavg=(wsum/n);
	for(i=0;i<n;i++){
		ta=ta+bt[i];
		tt[i]=ta-at[i];
		tsum=tsum+tt[i];}
	tavg=(tsum/n);
	printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
	for(i=0;i<n;i++){
		printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],bt[i],at[i],wt[i],tt[i]);}
	printf("\n\nAVERAGE WAITING TIME : %f",wavg);
	printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
	return 0;}
int swap(int *a,int *b){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
        return 0;}
