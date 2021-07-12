#include<stdio.h>
#define max 30
int main()
{
    int n,i,at[max],bt[max],wt[max],tat[max],t[max];
    float awt=0,atat=0;
    printf("enter the number of process\n");
    scanf("%d",&n);
    printf("enter the arrival time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    printf("enter the burst time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    t[i]=0;
    printf("\nprocess\t arrival time\t burst time\t waiting time\t turn around time\t");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        t[i+1]=t[i]+bt[i];
        wt[i]=t[i]-at[i];
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("Average waiting time = %f\n",awt);
    printf("Average turn around time = %f\n",atat);
}
