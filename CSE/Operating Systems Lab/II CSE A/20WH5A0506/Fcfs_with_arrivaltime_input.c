#include<stdio.h>
int main(){
    int bt[20],wt[20],tat[20],p[20],at[20],i,j,n,temp;
    float sum_wt=0,sum_tat=0,avg_wt=0,avg_tat=0;
    printf("Enter number of processes : ");
    scanf("%d",&n);
    printf("Enter the order of processes in terms of 1,2,3,4,...n: ");
    for(i = 0;i < n;i++){
        scanf("%d",&p[i]);
    }
    for(i=0;i<n;i++){
        printf("Enter the burst time and arrival time of the process %d:",p[i]);
        scanf("%d %d",&bt[i],&at[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(at[j]>at[j+1]){
                temp = p[j+1];
                p[j+1]=p[j];
                p[j] = temp;
                temp = at[j+1];
                at[j+1]=at[j];
                at[j] = temp;
                temp = p[j+1];
                bt[j+1]=bt[j];
                bt[j] = temp;
            }
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i] = 0;
        for(j=0;j<i;j++){
            wt[i] += bt[j];
        }
    }
    printf("Process    Arrival Time    Burst Time    Waiting Time     TurnAround Time");
    for(i=0;i<n;i++){
        wt[i]=wt[i] - at[i];
        tat[i] = bt[i] + wt[i];
        sum_wt += wt[i];
        sum_tat += tat[i];
        printf("\n p[%d]\t\t%d\t\t%d\t\t%d\t\t%d",p[i],at[i],bt[i],wt[i],tat[i]);
    }
    avg_wt = sum_wt/n;
    avg_tat = sum_tat/n;
    printf("\nAverage Waiting Time=%.2f\n",avg_wt);
    printf("\nAverage Turnaround Time=%.2f\n",avg_tat);
    return 0;;
}
