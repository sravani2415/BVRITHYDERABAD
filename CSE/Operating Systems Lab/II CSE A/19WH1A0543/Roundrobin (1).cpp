#include<stdio.h>     
int main(){   
    int i, num, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avg_wt, avg_tat;  
    printf("enter number of process: ");  
    scanf("%d", &num);  
    y = num; 
    
    for(i=0; i<num; i++){  
        printf("Enter the Arrival and Burst time of the Process[%d]: ", i+1);  
        scanf("%d", &at[i]);     
        scanf("%d", &bt[i]);  
        temp[i] = bt[i];   
    }   
    printf("Enter the Time Quantum for the process: ");  
    scanf("%d", &quant);    
    printf("Process     Burst time     Waiting time    Turnaround time\n");  
    for(sum=0, i = 0; y!=0; )  {  
        if(temp[i] <= quant && temp[i] > 0){  
            sum = sum + temp[i];  
            temp[i] = 0;  
            count=1;  
        }     
        else if(temp[i] > 0)  {  
            temp[i] = temp[i] - quant;  
            sum = sum + quant;    
        }  
        if(temp[i]==0 && count==1)  {  
            y--;   
            printf(" p[%d]\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
            wt = wt+sum-at[i]-bt[i];  
            tat = tat+sum-at[i];  
            count =0;     
        }  
        if(i==num-1)  
            i=0;  
        else if(at[i+1]<=sum)  
            i++;  
        else  
            i=0;   
    }  
  
avg_wt = wt * 1.0/num;  
avg_tat = tat * 1.0/num;  
printf("\n Average Turn Around Time: %.2f", avg_wt);  
printf("\n Average Waiting Time: %.2f", avg_tat);    
}