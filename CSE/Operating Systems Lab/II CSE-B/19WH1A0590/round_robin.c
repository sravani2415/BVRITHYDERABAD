#include<stdio.h>
int main()
{
    int sum=0,count=0,i,n,y,quant,at[10],bt[10],wt=0,tat=0,t[10];
    float awt=0,atat=0;
    printf("enter the number of process\n");
    scanf("%d",&n);
    y=n;
    printf("enter the arrival time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    printf("enter the burst time\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        t[i]=bt[i];
    }
    printf("enter the time quantum\n");
    scanf("%d",&quant);
    printf("process\t arrival time\t burst time\t waiting time\t turn around time\t");
    for(sum=0,i=0;y!=0;)
    {
        if(t[i] <= quant && t[i] > 0 )
        {
            sum=sum+t[i];
            t[i]=0;
            count=1;
        }
        else if(t[i] > 0)
        {
            t[i]=t[i]-quant;
            sum=sum+quant;
        }
        if(t[i]==0 && count==1)
        {
            y--;
            printf("\np[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],sum-at[i]-bt[i],sum-at[i]);
            wt=wt+sum-at[i]-bt[i];
            tat=tat+sum-at[i];
            count=0;
        }
        if(i==n-1)
        {
            i=0;
        }
        else if(at[i+1] <= sum)
        {
            i++;
        }
        else
            i=0;
    }
    awt=wt/n;
    atat=tat/n;
    printf("Average waiting time : %f\n",awt);
    printf("Average turn around time : %f\n",atat);
    return 0;
}
