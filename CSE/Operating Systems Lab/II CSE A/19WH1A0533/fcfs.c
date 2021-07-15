#include<stdio.h>

int main()
{
    int n,burstt[20],waitingt[20],turnaroundt[20],averagewt=0,averageturnaroundt=0,i,j,processes[n];
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
    printf("Enter order of processes in format 1,2,3,.....,n");
        for(i=0;i<n;i++)
           scanf("%d",&processes[i]);


    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&burstt[i]);
    }

    waitingt[0]=0;


    for(i=1;i<n;i++)
    {
        waitingt[i]=0;
        for(j=0;j<i;j++)
            waitingt[i]+=burstt[j];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++)
    {
        turnaroundt[i]=burstt[i]+waitingt[i];
        averagewt+=waitingt[i];
        averageturnaroundt+=turnaroundt[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,burstt[i],waitingt[i],turnaroundt[i]);
    }

    averagewt/=i;
    averageturnaroundt/=i;
    printf("\n\nAverage Waiting Time:%d",averagewt);
    printf("\nAverage Turnaround Time:%d",averageturnaroundt);

    return 0;
}
