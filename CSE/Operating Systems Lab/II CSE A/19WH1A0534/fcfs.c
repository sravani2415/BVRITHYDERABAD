/* First Come First Serve Scheduling - Lab Task 1*/
#include<stdio.h>
int main()
{
    int n,bt[20],wt[20],tat[20],i,j,p[20];
    float sum_wt=0,sum_tat = 0,avwt=0,avtat=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);

    printf("\nEnter the order of processes in terms of 1,2,3,4,...n: ");
    for(i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }

    for(i=0;i<n;i++)
    {
    	printf("Enter the burst time of process %d:", p[i]);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }

    printf("Process no\tburst time\twaiting time\tturnaround time\n");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        sum_wt +=wt[i];
        sum_tat +=tat[i];
        printf("\t%d\t%d\t\t%d\t\t\%d\n",p[i],bt[i],wt[i],tat[i]);
    }

    avwt =sum_wt/n;
    avtat = sum_tat/n;
    printf("Average Waiting time=%.2f\n",avwt);
    printf("Average Turnaround time=%.2f",avtat);

    return 0;
}
