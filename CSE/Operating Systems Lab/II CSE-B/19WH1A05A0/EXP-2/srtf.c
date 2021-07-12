#include <stdio.h>
int main()
{
    int at[10],bt[10],temp[10],wt1[10],tt1[10];
    int i,min,c=0,time,n;
    int wt = 0,tt = 0,end;

    printf("\nEnter the Total Number of Processes:\t");
    scanf("%d", &n);
    printf("\nEnter Details of %d Processes\n", n);
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time:\t");
        scanf("%d", &at[i]);
        printf("Enter Burst Time:\t");   
        scanf("%d", &bt[i]); 
        temp[i] = bt[i];
    }
    bt[9] = 9999;
    for(time = 0; c != n; time++){
        min = 9;
        for(i = 0;i<n; i++){
            if(at[i] <= time && bt[i] < bt[min] && bt[i] > 0)
                min = i;
        }
        bt[min]--;
        if(bt[min] == 0){
            c++;
            end = time + 1;
            wt = wt + end - at[min] - temp[min];
            tt = tt + end - at[min];
            wt1[min] = end - at[min] - temp[min];
            tt1[min] = end -at[min];
        }
    }
    printf("\nprocess burst_time    waiting_time      turnaround_time\n");
    for(int i = 0;i<n;i++){
        printf(" p[%d]        %d             %d              %d \n" ,i,temp[i],wt1[i],tt1[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", wt/(float)n);
    printf("Average Turnaround Time: %.2f\n", tt/(float)n); 
    return 0;
}