#include<stdio.h>
int main(){
    int wt=0,tat=0,at[10],bt[10],temp[10],i,x,n,total=0,counter=0,time_quantum;
    float avg_wt,avg_tat;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    x=n;
    for(i=0;i<n;i++){
	printf("Enter arrival time and burst time of process %d:",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        temp[i]=bt[i];
    }
    printf("Enter time quantum:");
    scanf("%d",&time_quantum);
    printf("\nProcess    Burst Time    Waiting Time    Turnaround Time");
    for(total=0, i=0; x!= 0;){
        if(temp[i] <= time_quantum && temp[i] > 0){
            total += temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if(temp[i] > 0){
            temp[i] = temp[i] - time_quantum;
            total = total + time_quantum;
        }
        if(temp[i] == 0 && counter == 1){
            x--;
            printf("\nP[%d]\t\t %d\t\t  %d\t\t\t%d",i+1,bt[i],total-at[i]-bt[i],total-at[i]);
            wt = wt+ total - at[i] - bt[i];
	    tat = tat + total -at[i];
            counter = 0;
	}
        if(i == n-1)
            i=0;
        else if(at[i+1]<=total)
            i++;
        else
	    i=0;
    }
    avg_wt=wt*1.0/n;
    avg_tat=tat*1.0/n;
    printf("\nAverage Waiting Time:%.2f",avg_wt);
    printf("\nAverage Turnaround Time:%.2f",avg_tat);
    return 0;
}
    
