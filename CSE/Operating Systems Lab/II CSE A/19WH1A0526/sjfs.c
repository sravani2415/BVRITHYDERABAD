#include<stdio.h>
int main(){
        int n,b_t[10],w_t[10],ta_t[10],i,j,a[10],pos,temp,total=0;
        float sum_wt=0,sum_tat=0,avg_wt=0,avg_tat=0;
        printf("Enter number of processes:");
        scanf("%d",&n);
        printf("\nEnter the order of processes in terms of 1,2,3....:");
        for(i=0;i<n;i++){
                scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++){
                printf("Enter the burst time of process %d:",a[i]);
                scanf("%d",&b_t[i]);
        }
        for(i=0;i<n;i++)
	{
        	pos=i;
        	for(j=i+1;j<n;j++)
        	{
            	if(b_t[j]<b_t[pos])
                	pos=j;
        	}
	       	temp=b_t[i];
        	b_t[i]=b_t[pos];
       	        b_t[pos]=temp;
		temp=a[i];
	       	a[i]=a[pos];
		a[pos]=temp;
	}
	w_t[0]=0;         
       	for(i=1;i<n;i++)
    	{
	       	w_t[i]=0;
        	for(j=0;j<i;j++)
            	w_t[i]+=b_t[j];
  
        	total+=w_t[i];
	}

  
    	avg_wt=(float)total/n;      
    	total=0;
	printf("\nProcesst    Burst Time    Waiting Time     Turnaround Time");
    	for(i=0;i<n;i++)
    	{
        	ta_t[i]=b_t[i]+w_t[i];   
        	total+=ta_t[i];
        	printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",a[i],b_t[i],w_t[i],ta_t[i]);
    	}
  
    	avg_tat=(float)total/n;    
        printf("\nAverage Waiting Time=%.1f",avg_wt);
	printf("\nAverage Turnaround Time=%.1f",avg_tat);
}	


    


