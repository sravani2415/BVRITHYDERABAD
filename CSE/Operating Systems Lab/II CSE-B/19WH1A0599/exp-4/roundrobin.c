#include<stdio.h>
main()
{
int i,j,n,burst_time[10],waiting_time[10],turnaround_time[10],time,ct[10],max;
float awt=0,att=0,temp=0;
printf("Enter the no of processes -- ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter Burst Time for process %d -- ", i+1);
scanf("%d",&burst_time[i]);
ct[i]=burst_time[i];
}
printf("\nEnter the size of time quantum -- ");
scanf("%d",&time);
max=burst_time[0];
for(i=1;i<n;i++)
if(max<burst_time[i])
max=burst_time[i];
for(j=0;j<(max/time)+1;j++)
for(i=0;i<n;i++)
if(burst_time[i]!=0)
if(burst_time[i]<=time) {
turnaround_time[i]=temp+burst_time[i];
temp=temp+burst_time[i];
burst_time[i]=0;
}
else {
burst_time[i]=burst_time[i]-time;
temp=temp+time;
}
for(i=0;i<n;i++){
waiting_time[i]=turnaround_time[i]-
ct[i]; 
awt+=waiting_time[i];
}

printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\n");
for(i=0;i<n;i++)
printf("\t%d \t %d \t\t %d \n",i+1,ct[i],waiting_time[i]);

printf("\nThe Average Waiting time is -- %f ",awt/n);


getch();
}

