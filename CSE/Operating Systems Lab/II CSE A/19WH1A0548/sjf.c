#include<stdio.h>
 int main()
{
    int burst_time[20],p[20],wait_time[20],tat[20],i,j,n,total=0,pos,temp;
    float total_wt,total_tat;
    printf("Enter number of process:");
    scanf("%d",&n);

    printf("nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&burst_time[i]);
        p[i]=i+1;
    }


    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }

        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wait_time[0]=0;


    for(i=1;i<n;i++)
    {
        wait_time[i]=0;
        for(j=0;j<i;j++)
            wait_time[i]+=burst_time[j];

        total+=wait_time[i];
    }

    total_wt=(float)total/n;
    total=0;

    printf("\nProcess\t\tBurst Time\t Waiting Time\t Turnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=burst_time[i]+wait_time[i];
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t %d\t\t\t%d",p[i],burst_time[i],wait_time[i],tat[i]);
    }

    total_tat=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",total_wt);
    printf("\nAverage Turnaround Time=%f\n",total_tat);
}