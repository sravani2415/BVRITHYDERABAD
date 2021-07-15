#include<stdio.h>
 int main(){
    int n,Bt[20],Wt[20],Tat[20],Avwt=0,Avtat=0,i,j,P[n];
    printf("Enter  number of processes:");
    scanf("%d",&n);
    printf("\nEnter Process  order\n");
    for(i=0;i<n;i++) 
        scanf("%d",&P[i]);
  //Burst time  
	for(i = 0; i < n; i++){
	    printf("Enter burst time of %d: ", P[i]);
		scanf("%d", &Bt[i]);
	} 
 Wt[0]=0;  
 for(i=1;i<n;i++){
        Wt[i]=0;
        for(j=0;j<i;j++)
            Wt[i]+=Bt[j];
    }
printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
 for(i=0;i<n;i++) {
        Tat[i]=Bt[i]+Wt[i];
        Avwt+=Wt[i];
        Avtat+=Tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,Bt[i],Wt[i],Tat[i]);
    }
Avwt/=i;
    Avtat/=i;
    printf("\n\nAverage Waiting Time:%d",Avwt);
    printf("\nAverage Turnaround Time:%d",Avtat);
 
    return 0;
}