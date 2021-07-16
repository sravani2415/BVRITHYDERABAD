#include<stdio.h>
void waiting_time(int processes[],int n,int bt[],int wt[]){
    wt[0] = 0;
    for(int i = 1;i < n;i++){
        wt[i] = bt[i-1] + wt[i-1];
    }
}

void turn_around_time(int processes[],int n,int bt[],int wt[],int tat[]){
    for(int i = 0;i < n;i++){
        tat[i] = bt[i] + wt[i];
    }
}

void average_time(int processes[],int n,int bt[]){
    int wt[n],tat[n],total_wt = 0,total_tat = 0;
    waiting_time(processes,n,bt,wt);
    turn_around_time(processes,n,bt,wt,tat);
    printf("Processes   Burst time   Waiting time   Turn around time\n");
    for(int i = 0;i < n;i++){
        total_wt += wt[i];
        total_tat += tat[i];
        printf("     %d",processes[i]);
        printf("   \t%d",bt[i]);
        printf("    \t\t%d",wt[i]);
        printf("   \t\t%d\n",tat[i]);
    }
    float s = (float)total_wt / (float)n;
    float t = (float)total_tat / (float)n;
    printf("Average waiting time = %.2f\n",s);
    printf("Average turn around time = %.2f\n",t);
}

int main(){
    int num,i;
    printf("Enter the number of processes:");
    scanf("%d",&num);
    int processes[num],burst_time[num];
    int n = sizeof(processes) / sizeof(processes[0]);
    printf("Enter the order of processes in terms of 1,2,3,4...n: ");
    for(i = 0;i < num;i++){
        scanf("%d",&processes[i]);
    }
    for(i = 0;i < num;i++){
        printf("Enter the burst time of the process %d:",processes[i]);
        scanf("%d",&burst_time[i]);
    }
    average_time(processes,n,burst_time);
    return 0;
}
