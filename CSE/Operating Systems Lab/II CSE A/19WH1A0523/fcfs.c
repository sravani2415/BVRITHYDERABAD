#include <stdio.h>
int main(){
int n,bt[20],wt[20],tat[20],i,j;
int avwt=0;
int avat=0;
int processes[n];

printf("Enter Total Number Of Processes:");
scanf("%d",&n);
printf("Enter the order of Processes in the format 1,2,3,4....n:");
for(i=0;i<n;i++){
           scanf("%d",&processes[i]);
}
for(i=0;i<n;i++){
           printf("Enter the Burst Time of Processes %d:",processes[i]);
           scanf("%d",&bt[i]);
}
wt[0]=0;
for(i=1;i<n;i++){
           wt[i]=0;
           for(j=0;j<i;j++)
                      wt[i]+=bt[j];
}
printf("\n Process no.\t Burst Time\t Waiting Time\t Turnaround Time\t" );
for(i=0;i<n;i++){
           tat[i]=bt[i]+wt[i];
           avwt+=wt[i];
           avat+=tat[i];
           printf("\n \t%d\t\t%d\t\t%d\t\t%d\t\t" ,processes[i],bt[i],wt[i],tat[i]);

}
avwt/=i;
avat/=i;
printf("\nAverage Waiting Time :%d",avwt);
printf("\nAverage Turnaround Time :%d",avat);
return 0;
}


