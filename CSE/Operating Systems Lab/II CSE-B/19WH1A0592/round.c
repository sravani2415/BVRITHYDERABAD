#include<stdio.h>
 int main()
{
      int i, limit, sum = 0, x, c = 0, time_quantum;
      int wait_time = 0, tat = 0, a_time[10], b_time[10], temp[10];
      float average_wait_time, average_tat;
      printf("Enter Total Number of Processes:");
      scanf("%d", &limit);
      x = limit;
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
 
            printf("Arrival Time:");
 
            scanf("%d", &a_time[i]);
 
            printf("Burst Time:");
 
            scanf("%d", &b_time[i]);
 
            temp[i] = b_time[i];
      }
 
      printf("\nEnter Time Quantum:");
      scanf("%d", &time_quantum);
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time");
      for(sum = 0, i = 0; x != 0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  sum = sum + temp[i];
                  temp[i] = 0;
                  c = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  sum = sum + time_quantum;
            }
            if(temp[i] == 0 && c == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, b_time[i], sum - a_time[i], sum - a_time[i] - b_time[i]);
                  wait_time = wait_time + sum - a_time[i] - b_time[i];
                  tat = tat + sum - a_time[i];
                  c = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(a_time[i + 1] <= sum)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
 
      average_wait_time = wait_time * 1.0 / limit;
      average_tat = tat * 1.0 / limit;
      printf("\nAverage Waiting Time:%f", average_wait_time);
      printf("\nAvg Turnaround Time:%f", average_tat);
      return 0;
}