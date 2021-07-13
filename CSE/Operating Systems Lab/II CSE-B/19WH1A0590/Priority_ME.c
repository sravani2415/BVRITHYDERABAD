#include<stdio.h>
int main()
{
    int n,t;
    float awt=0,atat=0;
    printf("enter the number of processes\n");
    scanf("%d",&n);
    int pri[n],bt[n],wt[n],p[n],i,j;
    printf("enter the priority time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pri[i]);
        p[i]=i+1;
    }
    printf("enter the burst time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(pri[j] < pri[j+1])
            {
                t=pri[j];
                pri[j]=pri[j+1];
                pri[j+1]=t;

                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;

                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;



            }
        }
    }
    printf("process\t priority\t burst time\t waiting time\n");
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];

    }
    for(i=0;i<n;i++)
    {
        printf("p%d\t\t%d\t\t%d\t\t%d\n",p[i],pri[i],bt[i],wt[i]);
    }
    for(i=0;i<n;i++)
    {
        awt+=wt[i];
        atat+=wt[i]+bt[i];
    }
    awt=awt/n;
    atat=atat/n;
    printf("average wait time=%f",awt);
    printf("average tat=%f",atat);
    return 0;
}
