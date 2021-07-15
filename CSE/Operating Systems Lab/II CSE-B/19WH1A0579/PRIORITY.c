#include<stdio.h>
int main(){
    int n,temp,sum = 0,position;
    printf("enter the number of processes \n");
    scanf("%d",&n);
    int bt[n],priority[n],tt[n],wt[n],p[n];
    float wavg,tavg;
    
    for(int i = 0; i< n; i++){
        printf("enter the priority and burst time of the process %d\n",i+1);
        scanf("%d%d",&priority[i],&bt[i]);
        p[i] = i+1;
    }
    for(int i = 0; i< n; i++){
        position = i;
        for(int j = i+1 ; j < n; j++){
            if(priority[j] < priority[position])
                position = j;
        }
        temp = priority[i];
        priority[i] = priority[position];
        priority[position] = temp;
        temp = bt[i];
        bt[i] = bt[position];
        bt[position] = temp;
        temp = p[i];
        p[i] = p[position];
        p[position] = temp;
    }
    wt[0] = 0;
    for(int i = 1; i < n; i++){
        wt[i] = 0;
        for(int j = 0; j < i; j ++){
            wt[i] = wt[i] + bt[j]; 
        }sum = sum + wt[i];
    }wavg = sum / n;
    printf("average waiting time = %f\n",wavg);
    sum = 0;
    for(int i = 0; i < n; i++){
        tt[i] = bt[i] + wt[i];
        sum += tt[i];
    }
    tavg = sum/n;
    printf("average turnoaroud time = %f\n",tavg);
    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
    
    for(int i = 0; i < n; i++)
      {
            
        printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", p[i], bt[i], wt[i], tt[i]);
      }
    

    
}
