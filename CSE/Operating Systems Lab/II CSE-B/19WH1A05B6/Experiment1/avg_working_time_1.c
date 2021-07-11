
#include<stdio.h>
int main()
{
	int n;
	int total_worktime =0;
	printf("Number of processes:\n");
	scanf("%d",&n);
	int i=0;
	int arr[n];
	int exc[n];
	int ser[n];
	float avg_worktime;
	ser[0]=0;
	printf("Enter the arrival times:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the exceution times:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&exc[i]);
	}
	for(i=1;i<n;i++)
	{	
		ser[i]=ser[i-1]+exc[i-1];	
	}
	
	for(i=1;i<n;i++)
	{	
		total_worktime =total_worktime+(ser[i]-arr[i]);	
	}
	avg_worktime=(float)total_worktime/n;
	printf("%f",avg_worktime);
}
