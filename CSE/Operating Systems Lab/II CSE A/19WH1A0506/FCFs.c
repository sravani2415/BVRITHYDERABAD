#include<stdio.h>
void get_waiting_time(int processes[],int n,int bt[],int wt[]){
    wt[0] = 0;
    for(int i = 1;i < n;i++){
        wt[i] = bt[i-1] + wt[i-1];
    }
}
void get_turnaround_time(int processes[],int n,int bt[],int wt[],int tat[]){
    for(int i = 0;i<n;i++){
        tat[i] = bt[i] + wt[i];
    }
}
void find_avg_time(int processes[],int n,int bt[]){
    int wt[n],tat[n],total_wt=0,total_tat=0;
    get_waiting_time(processes,n,bt,wt);
    get_turnaround_time(processes,n,bt,wt,tat);
    printf("Processes    Burst time    Waiting time    Turn around time\n");
    for(int i=0;i<n;i++){
        total_wt += wt[i];
        total_tat += tat[i];
        printf("    %d",(i+1));
        printf("            %d",bt[i]);
        printf("	        %d",wt[i]);
        printf("	           %d\n",tat[i]);
    }
    float s = (float)total_wt / (float)n;
    float t = (float)total_tat / (float)n;
    printf("Average waiting time = %.2f",s);
    printf("\n");
    printf("Average turn around time = %.2f",t);
}
int main(){
    int num;
    printf("Enter the number of processes:");
    scanf("%d",&num);
    printf("\n");
    int processes[num],burst_time[num];
    int n = sizeof processes / sizeof processes[0];
    printf("Enter the order of processes in terms of 1,2,3,4...n: ");
    for(int i=0;i<num;i++){
        scanf("%d",&processes[i]);
    }
    for(int i=0;i<num;i++){
        printf("Enter the burst time of the process %d:",processes[i]);
        scanf("%d",&burst_time[i]);
    }
    find_avg_time(processes,n,burst_time);
    return 0;
}
