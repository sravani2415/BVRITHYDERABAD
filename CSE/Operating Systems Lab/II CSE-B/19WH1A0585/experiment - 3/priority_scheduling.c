#include<stdio.h>

int main()
{
    int n;
    printf("Enter total no.of processors: \n");
    scanf("%d", &n);
    
    int exe_t[n], p[n];
    
    // taking inputs from the user.

    for(int i = 0; i < n; i++)
    {
       printf("Enter execution time and priority of the processor %d: ", i + 1);
       scanf("%d %d", &exe_t[i], &p[i]);
    }

    // sorting such that highest priority element is at the top.
 
    for(int i = 0; i < n - 1; i++)
    {
       for(int j = 0; j < n - i - 1; j++)
       {
          if (p[j] < p[j + 1])
          {
             int temp = p[j];
             p[j] = p[j + 1];
             p[j + 1] = temp;
 
             temp = exe_t[j];
             exe_t[j] = exe_t[j + 1];
             exe_t[j + 1] = temp;
          }
       }
    }
    
   int temp_arr[n + 1];
   
   temp_arr[0] = 0;
   for(int i = 1; i < n + 1; i++)
   {
      temp_arr[i] = temp_arr[i - 1] + exe_t[i - 1];
   }

   float sum = 0.0; 
   for(int i = 0; i < n; i++)
   {
      sum += temp_arr[i];
   }
   printf("Average waiting time: %f \n", sum / n);
   
   float count = 0.0;
   for(int i = 1; i < n + 1; i++)
   {
      count += temp_arr[i];
   }
   printf("Average turn around time: %f\n", count / n);
   return 0;
} 
          
