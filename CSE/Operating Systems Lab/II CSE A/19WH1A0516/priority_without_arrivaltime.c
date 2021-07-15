#include<stdio.h>
int main()
{
    int n,i,j;
    float avg_wt,avg_tat;
    
    printf("Enter number of processes 1,2,3,...n:");
    scanf("%d",&n);
    int bt[n],p[n],wt[n],tat[n], pr[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time and priority for p[%d]:",i+1);
        scanf("%d %d",&bt[i], &pr[i]);
        p[i]=i+1;          
    }
    int temp;
    for(i=0;i<n-1;i++)
   {
     for(j=0;j<n-i-1;j++)
      {
        if(pr[j]>pr[j+1])
          {
            temp = pr[j];
            pr[j] = pr[j+1];
            pr[j+1] = temp;
             
            temp=bt[j];
            bt[j]=bt[j+1];
            bt[j+1]=temp;
            
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
           }
        }
    }
    int total = 0;
    wt[0]=0;           
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];    
        total+=tat[i];
        printf("\np[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     
    printf("\n\nAverage Waiting Time=%.2f",avg_wt);
    printf("\nAverage Turnaround Time=%.2f\n",avg_tat);
    return 0;
}
