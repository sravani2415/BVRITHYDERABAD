#include<stdio.h>
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp;
	float avg_wt,avg_tat;
    printf("Enter total number of processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	printf("Enter Burst Time and Priority of process %d : ",i+1);
        scanf("%d %d",&bt[i],&pr[i]);
        p[i]=i+1;
    }
    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(pr[j]<pr[pos]){
                pos=j;
            }
        }
        swap(&pr[i],&pr[pos]);
        swap(&bt[i],&bt[pos]);
        swap(&p[i],&p[pos]);
    }
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++){
            wt[i]+=bt[j];
        }
        total+=wt[i];
    }
    avg_wt=total/n;
    total=0;
    printf("Process no.  \tBurst Time  \tWaiting Time  \tTurnaround Time");
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t  %d",p[i],bt[i],wt[i],tat[i]);
    }
    avg_tat=total/n;
    printf("\nAverage Waiting Time=%.2f\n",avg_wt);
    printf("Average Turnaround Time=%.2f\n",avg_tat);
	return 0;
}