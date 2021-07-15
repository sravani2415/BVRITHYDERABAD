#include<stdio.h>
int main(){
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter burst time and priority of process %d:",i+1);
        scanf("%d %d",&bt[i],&pr[i]);
        p[i] = i+1;
    }
    for(i=0;i<n;i++){
        pos=i;
        for(j=i;j<n;j++){
            if(pr[j]<pr[pos])
                pos=j;
        }
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++){
           wt[i]+=bt[j];
        }
        total+=wt[i];
    }
    avg_wt=(float)total/n;
    total=0;
    printf("\nProcess   Burst Time   Waiting Time   Turnaround Time");
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    avg_tat=(float)total/n;
    printf("\nAverage Waiting Time=%.2fms\n",avg_wt);
    printf("Average Turnaround Time=%.2fms",avg_tat);
    return 0;
}
