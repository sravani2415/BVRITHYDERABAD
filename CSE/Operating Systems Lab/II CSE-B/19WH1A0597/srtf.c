#include <stdio.h>
int main()
{
    int arrival_time[10], burst_time[10], t[10], wait_time[10], tat[10];
    int i, small, count=0, time, n;
    float _wait_time_ = 0, _tat_ = 0, end;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    printf("\nEnter Details of %d Processes", n);
    for(i=0;i <n;i++)
    {
        printf("\nEnter Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst Time: ");   
        scanf("%d", &burst_time[i]); 
        t[i] = burst_time[i];
    }
    burst_time[9] = 9999;
    for(time=0;count!=n;time++)
	{
        small = 9;
        for(i=0;i<n;i++)
		{
            if(arrival_time[i] <= time && burst_time[i] < burst_time[small] && burst_time[i] > 0)
                small = i;
        }
        burst_time[small]--;
        if(burst_time[small] == 0)
		{
            count++;
            end = time + 1;
            _wait_time_ = _wait_time_ + end - arrival_time[small] - t[small];
            _tat_ = _tat_ + end - arrival_time[small];
            wait_time[small] = end - arrival_time[small] - t[small];
            tat[small] = end -arrival_time[small];
        }
    }
    printf("\nProcess  Burst Time    Waiting Time      Turnaround Time\n");
    for(i=0;i<n;i++)
	{
        printf(" P%d        %d             %d             		%d\n" ,i+1, t[i], wait_time[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %0.3f\n", _wait_time_/n);
    printf("Average Turnaround Time: %0.3f\n", _tat_/n);
    return 0;
}
