#include<stdio.h>
int main()
{
   int n;
   printf("Enter no.of processors: \n");
   scanf("%d", &n);
   int at[n], bt[n];
   
   // taking the arrival and burst times from the user
  
   for(int i = 0; i < n;i++)
   {
       printf("Enter arrival and burst times of processor %d: ", i + 1);
       scanf("%d %d", &at[i], &bt[i]);
   }
   
   // arrange the arrival times in order if in case not in order. 
   
   for(int i = 0; i < n - 1; i++)
   {
      for(int j = 0; j < n - i - 1; j++)
      {
         if(at[j] > at[j + 1])
         {
           int temp = at[j]; 
           at[j] = at[j + 1];
           at[j + 1] = temp;
           
           temp = bt[j];
           bt[j] = bt[j + 1];
           bt[j + 1] = temp;
         }
      }
   }
   
   for(int i = 1; i < n - 1; i++)
   {
      for(int j = 1; j < n - i - 1; j++)
      {
         if(bt[j] > bt[j + 1])
         {
            int temp = bt[j];
            bt[j] = bt[j + 1];
            bt[j + 1] = temp;
            
            temp = at[i];
            at[i] = at[i + 1];
            at[i + 1] = temp;
         }
      }
   }
   
   int temparr[n - 1];
   temparr[0] = bt[0];
   for(int i = 1; i < n - 1; i++)
   {
      temparr[i] = temparr[i - 1] + bt[i];
   }
   
   int sum = 0;
   for(int i = 0; i < n; i++)
   {
      sum = sum + (temparr[i] - at[i + 1]);
   }
   printf("Average waiting time: %f \n", (float)(sum / n));
   return 0;  
}
            
