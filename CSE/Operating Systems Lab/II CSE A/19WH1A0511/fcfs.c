#include<stdio.h>
int main(){
	int n,b_t[10],w_t[10],ta_t[10],i,j,a[10];
	float sum_wt=0,sum_tat=0,avg_wt=0,avg_tat=0;
	printf("Enter number of processes");
	scanf("%d",&n);
	printf("\nEnter the order of processes in terms of 1,2,3....");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		printf("Enter the burst time of process %d:",a[i]);
		scanf("%d",&b_t[i]);
	}
	w_t[0]=0;
	for(i=1;i<n;i++){
		w_t[i]=0;
		for(j=0;j<i;j++){
			w_t[i]+=b_t[j];
		}
	}
	printf("Process number\t\tburst time\twaiting time\tturnaround time \n");
	for(i=0;i<n;i++){
		ta_t[i]=b_t[i]+w_t[i];
		sum_wt += w_t[i];
		sum_tat +=ta_t[i];
		printf("\t%d\t\t%d\t\t%d\t\t%d\n",a[i],b_t[i],w_t[i],ta_t[i]);
	}

	avg_wt = sum_wt/n;
	avg_tat = sum_tat/n;
	printf("Average Waiting time=%.2f\n",avg_wt);
	printf("Average Turnaround time = %.2f",avg_tat);
}
