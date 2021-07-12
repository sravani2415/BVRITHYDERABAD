#include<stdio.h>

int main()
{
  int n;
  float total = 0;
  printf("Enter the total no.of processors: \n");
  scanf("%d", &n);
  int arr_time[n], exe_time[n], ser_time[n], wait_time[n];
  ser_time[0] = 0;
  for(int i = 0; i < n; i++)
  {
      printf("Enter arrival time for processor P%d : ", i);
      scanf("%d", &arr_time[i]);
  }
  for(int i = 0; i < n; i++)
  {
      printf("Enter execution time for processor P%d : ", i);
      scanf("%d", &exe_time[i]);
  }
  for(int i = 1; i < n; i++)
  {
     ser_time[i] = ser_time[i - 1] + exe_time[i - 1];
  }
  for(int i = 0; i < n; i++)
  {
    total += (ser_time[i] - arr_time[i]);
  }
  printf("The average time: %f\n", total/n);
  return 0;
} 



