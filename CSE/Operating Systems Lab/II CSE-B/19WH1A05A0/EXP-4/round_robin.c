#include<stdio.h>
 
int main()
{
      int i, n, total = 0, k, c = 0, time_quantum;
      int wt = 0, tat = 0, at[10], bt[10], temp[10];
      float avg_wt, avg_tat;
      printf("Enter Total Number of Processes\n");
      scanf("%d", &n);
      k = n;
      for(i = 0; i < n; i++)
      {
            printf("Enter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &at[i]); 
            printf("Burst Time:\t"); 
            scanf("%d", &bt[i]); 
            temp[i] = bt[i];
      }
 
      printf("\nEnter Time Quantum:\t");
      scanf("%d", &time_quantum);
      printf("\nProcess \t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; k != 0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  c = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && c == 1)
            {
                  k--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, bt[i], total - at[i], total - at[i] - bt[i]);
                  wt = wt + total - at[i] - bt[i];
                  tat = tat + total - at[i];
                  c = 0;
            }
            if(i == n - 1)
            {
                  i = 0;
            }
            else if(at[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
 
      avg_wt = wt  /(float)n;
      avg_tat = tat  /(float)n;
      printf("\nAverage Waiting Time:%.2f", avg_wt);
      printf("\nAverage Turnaround Time:%.2f\n", avg_tat);
      return 0;
}