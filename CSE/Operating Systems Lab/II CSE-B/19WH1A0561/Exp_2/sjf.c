#include<stdio.h>
int main()
{
    int bt[20],p[20],arr[20],wt[20],i,j,n,total=0,pos,temp;
    float avg_wt;
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("\n Enter the arrival time: \n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&arr[i]);        
    }
    
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);       
    }
   //sorting of burst times
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;            
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        total+=wt[i];
    }
    avg_wt=(float)total/n; 
    printf("Average waiting time : %f\n",avg_wt);
}
