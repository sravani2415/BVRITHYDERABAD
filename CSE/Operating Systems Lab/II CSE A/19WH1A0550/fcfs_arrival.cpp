#include <stdio.h>  
int wt[10],bt[10],at[10],tat[10],n;  
float awt,atat;  
void input(){  
        printf("Enter Number of processes:");  
        scanf("%d",&n);  
        int i;  
        for(i=0;i<n;i++)  
        {  
          printf("Enter Arrival time,Burst Time of process p(%d):",i+1);  
          scanf("%d%d",&at[i],&bt[i]);         
                   
        }  
 }  
 void calculate(){  
    wt[0]=0;  
    atat=tat[0]=bt[0];  
    int btt=bt[0];  
    int i;  
    for(i=1;i<n;i++){  
      wt[i]=btt-at[i];  
      btt+=bt[i];        
      awt+=wt[i];     
      tat[i]= wt[i]+bt[i];   
      atat+=tat[i];    
    }  
    atat/=n;  
    awt/=n;       
 }  
 void display(){  
     int i;  
    printf("process no\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");  
    for(i=0;i<n;i++)  
    {  
    printf("%3d\t%15d\t%15d\t%15d\t%16d\n",i+1,at[i],bt[i],wt[i],tat[i]);          
    }    
    printf("Average Waiting Time: %f\nAverage Turn Around Time:%f",awt,atat);  
 }    
 int main(){  
         
       input();  
       calculate();  
       display();   
          
 }
