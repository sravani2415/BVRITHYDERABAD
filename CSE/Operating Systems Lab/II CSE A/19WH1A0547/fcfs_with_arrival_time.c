#include<stdio.h>

int waiting_time(int n,int arrival_time[],int burst_time[],int wait_time[]);
int turn_around_time(int n,int burst_time[],int wait_time[],int turn_around[]);
int avg_time(int n,int wait_time[],int turn_around[]);
int i;

int main(){
        int n;
        printf("Enter number of processes:");
        scanf("%d",&n);
        int proc[n],arrival_time[n],burst_time[n],wait_time[n],turn_around[n];
        printf("Enter the order of Processes in terms of 1,2,3,....n :");
        for(i=0;i<n;i++){
                scanf("%d",&proc[i]);
        }
        for(i=0;i<n;i++){
                printf("Enter the burst time and arrival time for process %d :",proc[i]);
                scanf("%d %d",&burst_time[i],&arrival_time[i]);
        }
        waiting_time(n,arrival_time,burst_time,wait_time);
        turn_around_time(n,burst_time,wait_time,turn_around);
        printf("Process no.\tArrival time\tBurst time\tWaiting time\tTurn around time\n");
        for(i=0;i<n;i++){
                printf("   p[%d]\t\t   %d\t\t   %d\t\t   %d\t\t   %d\n",proc[i],arrival_time[i],burst_time[i],wait_time[i],turn_around[i]);
        }
        avg_time(n,wait_time,turn_around);
        return 0;
}
int waiting_time(int n,int arrival_time[],int burst_time[],int wait_time[]){
        wait_time[0]=0;
        for(i=1;i<=n;i++){
                wait_time[i]=wait_time[i-1]+burst_time[i-1];
        }
        for(i=0;i<n;i++){
                wait_time[i]=wait_time[i]-arrival_time[i];
        }
        return 0;
}
int turn_around_time(int n,int burst_time[],int wait_time[],int turn_around[]){
        for(i=0;i<n;i++){
                turn_around[i]=burst_time[i]+wait_time[i];
        }
        return 0;
}
int avg_time(int n,int wait_time[],int turn_around[]){
        int wait_sum=0,turn_around_sum=0;
        for(i=0;i<n;i++){
                wait_sum+=wait_time[i];
                turn_around_sum+=turn_around[i];
        }
        printf("Average waiting time = %.2f\n",((float)wait_sum/(float)n));
        printf("Average turn around time = %.2f\n",((float)turn_around_sum/(float)n));
        return 0;
}
