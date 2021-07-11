#include <stdio.h>
int main() 
{
      int at[10], bt[10], temp[10];
      int i, n,smallest, count = 0, time, limit;
      double wt = 0,  end;
      float avgwt;
      printf("Enter the Total Number of Processes:");
      scanf("%d", &limit);
      for(i = 0; i < limit; i++)
      {
      		printf("enter arrival time& Burst time\n");
      		scanf("%d %d",&at[i],&bt[i]);
            temp[i] = bt[i];
      }
      bt[9] = 9999;  
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0)
                  {
                        smallest = i;
                  }
            }
            bt[smallest]--;
            if(bt[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wt = wt + end - at[smallest] - temp[smallest];
            }
      }
      avgwt = wt / limit;
      printf("Average Waiting Time:%fn", avgwt);
      return 0;
}
