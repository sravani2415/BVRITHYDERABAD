#include<stdio.h>
int waiting_time(int n,int burst_time[],int wait_time[]);
int turn_around_time(int n,int burst_time[],int wait_time[],int turn_around[]);
int avg_time(int n,int wait_time[],int turn_around[]);
int main(){
        int i,n;
        printf("Enter the number of processes:");
        scanf("%d",&n);
        int proc[n],burst_time[n],wait_time[n],turn_around[n];
        printf("Enter the order of processes:");
        for(i=0;i<n;i++){
                scanf("%d",&proc[i]);
        }
        for(i=0;i<n;i++){
                printf("Enter the burst time of the process %d:",proc[i]);
                scanf("%d",&burst_time[i]);
        }
        waiting_time(n,burst_time,wait_time);
        turn_around_time(n,burst_time,wait_time,turn_around);
        printf("Process no.\tburst time\twaiting time\tturnaround time\n");
        for(i=0;i<n;i++){
               printf("   p[%d]\t\t   %d\t\t   %d\t\t   %d\n",proc[i],burst_time[i],wait_time[i],turn_around[i]);
        }
        avg_time(n,wait_time,turn_around);
        return 0;
}
int waiting_time(int n,int burst_time[],int wait_time[]){
        int i;
        wait_time[0]=0;
        for(i=1;i<n;i++){
                wait_time[i]=wait_time[i-1]+burst_time[i-1];
        }
        return 0;
}
int turn_around_time(int n,int burst_time[],int wait_time[],int turn_around[]){
        int i;
        for(i=0;i<n;i++){
                turn_around[i]=burst_time[i]+wait_time[i];
        }
        return 0;
}
int avg_time(int n,int wait_time[],int turn_around[]){
        int i,waiting_time_sum=0,turn_around_sum=0;
        for(i=0;i<n;i++){
                waiting_time_sum += wait_time[i];
                turn_around_sum += turn_around[i];
        }
        printf("Average Waiting time = %.2f\n",((float)waiting_time_sum/(float)n));
        printf("Average Turn around time = %.2f\n",((float)turn_around_sum/(float)n));
        return 0;
}