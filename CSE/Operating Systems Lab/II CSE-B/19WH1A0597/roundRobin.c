#include<stdio.h>
int main()
{  
    int i, n, count=0, y, time_quanta, arrival_time[10], burst_time[10], t[10];
	float wait_time_= 0.0, tat_= 0.0, sum = 0.0;   
    float avg_wait_time, avg_tat;  
    printf(" Enter number of process: ");  
    scanf("%d", &n);  
    y = n; 
	for(i=0;i<n;i++)  
	{  
	printf("\nEnter the Arrival and Burst time of the P%d\n", i+1);  
	printf("Arrival time: "); 
	scanf("%d", &arrival_time[i]);  
	printf("Burst time: "); 
	scanf("%d", &burst_time[i]);  
	t[i] = burst_time[i];
	} 
	printf("\nEnter Time Quanta: ");  
	scanf("%d", &time_quanta);  
	printf("\nProcess \t Burst Time \t Turn Around Time \t Waiting Time ");  
	for(sum=0,i=0;y!=0; )  
	{  
		if(t[i] <= time_quanta && t[i] > 0)
		{  
    		sum = sum + t[i];  
    		t[i] = 0;  
    		count=1;  
    	}     
    	else if(t[i] > 0)  
    	{  
        	t[i] = t[i] - time_quanta;  
        	sum = sum + time_quanta;    
    	}  
    	if(t[i]==0 && count==1)  
    	{  
        	y--;
        	printf("\nP%d \t\t %d\t\t\t %d\t\t %d", i+1, burst_time[i], sum - arrival_time[i], sum - arrival_time[i] - burst_time[i]);  
        	wait_time_ = wait_time_ + sum - arrival_time[i] - burst_time[i];  
        	tat_ = tat_ +sum - arrival_time[i];  
        	count =0;     
    	}  
    	if(i == n-1)  
    	{  
        	i=0;  
    	}  
    	else if(arrival_time[i+1] <= sum)  
    	{  
        	i++;  
    	}  
    	else  
    	{  
       		i=0;  
    	}  
	}  
	avg_wait_time = wait_time_ / n;  
	avg_tat = tat_ / n;  
	printf("\n\nAverage Turn Around Time: \t%0.3f", avg_wait_time);  
	printf("\nAverage Waiting Time: \t%0.3f", avg_tat); 
	return 0;
}
