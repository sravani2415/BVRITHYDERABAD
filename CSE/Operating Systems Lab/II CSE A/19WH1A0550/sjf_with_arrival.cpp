#include<stdio.h>
int main(){
    int n,i,j;
    float avg_wt,avg_tat;
    int tot_wt=0,tot_tat=0;
    printf("Enter number of processes :");
    scanf("%d",&n);
    int bt[n],p[n],wt[n],tat[n],at[n];
    for(i=0;i<n;i++){
        printf("Enter the arrival time and burst time for p[%d]:",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        p[i] = i+1;
    }
    int temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(at[j] > at[j+1]){
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = bt[j];
                at[j] = at[j+1];
                bt[j+1] = temp;
                 
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                }
        }
    }
    int ex=0,min,k=1;
    for(j=0;j<n;j++){
        ex = ex + bt[j];
        min = bt[k];
        for(i=k;i<n;i++){
            if(ex>=at[i] && bt[i]<min){
                temp = p[k];
                p[k] = p[i];
                p[i] = temp;
 
                temp = at[k];
                at[k] = at[i];
                at[i] = temp;
  
                temp = bt[k];
                bt[k] = bt[i];
                bt[i] = temp;
            }
        }
        k++;
    }
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i] = 0;
        for(j=0;j<i;j++){
            wt[i] += bt[j];
        }
    }
    for(i=0;i<n;i++){
        wt[i] = wt[i] - at[i];
        tat[i] = bt[i] + wt[i];
        tot_wt += wt[i];
        tot_tat += tat[i];
    }
    printf("\nProcess        Burst Time        Waiting Time        Turnaround Time");
    for(i=0;i<n;i++){
        printf("\n  p[%d]            %d                   %d                    %d",p[i],bt[i],wt[i],tat[i]);
    }
    avg_wt =(float) tot_wt/n;
    avg_tat =(float) tot_tat/n;
    printf("\nAverage Waiting Time=%.2f",avg_wt);
    printf("\nAverage Turnaround Time=%.2f",avg_tat);
}
