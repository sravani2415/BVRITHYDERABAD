#include <stdio.h>
int main(){
    int at[10],bt[10],temp[10],wt1[10],tat1[10],p[20];
    int i,small,count=0,time,n;
    int wt = 0,tt = 0,end;

    printf("\nEnter the Total Number of Processes:");
    scanf("%d", &n);
    printf("\nEnter Arrival Time and Burst Time:");
    for(i = 0; i < n; i++)
    {
        printf("p%d:",i+1);
        scanf("%d%d", &at[i],&bt[i]);
        p[i]=i+1;
        temp[i] = bt[i];
    }
    bt[9] = 9999;
    for(time = 0; count != n; time++){
        small = 9;
        for(i = 0;i<n; i++){
            if(at[i] <= time && bt[i] < bt[small] && bt[i] > 0)
                small = i;
        }
        bt[small]--;
        if(bt[small] == 0){
            count++;
            end = time + 1;
            wt = wt + end - at[small] - temp[small];
            tt = tt + end - at[small];
            wt1[small] = end - at[small] - temp[small];
            tat1[small] = end -at[small];
        }
    }
    printf("\nprocess\t    burst_time\t    \twaiting_time      \tturnaround_time\n");
    for(int i = 0;i<n;i++){
    	printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",i,temp[i],wt1[i],tat1[i]);
    }
    printf("\nAverage Waiting Time: %d\n", wt/n);
    printf("Average Turnaround Time: %d\n", tt/n);

    return 0;
}
