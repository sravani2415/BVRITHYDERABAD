#include<stdio.h>
int main(){
    int n;
    printf("enter the number of processes \n");
    scanf("%d",&n);
    int p[n],at[n],bt[n],wt[n],temp;
    for(int i = 0; i< n; i++){
        p[i] = i+1;
        printf("enter the arrival and burst time of process %d\n",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            if(at[i] < at[j]){
                temp = at[j];
                at[j] = at[i];
                at[i] = temp;
                temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
    int btime = 0,min , k = 1;
    for(int i = 0; i < n; i++){
        btime = btime + bt[i];
        min = bt[k];
        for(int j = k; j < n; j++){
            if(btime >= at[j] && bt[j] < min){
                temp = at[j];
                at[j] = at[k];
                at[k] = temp;
                temp = bt[j];
                bt[j] = bt[k];
                bt[k] = temp;
                temp = p[j];
                p[j] = p[k];
                p[k] = temp;
            }
        }k++;
    }
    wt[0] = 0;
    int sum = 0;
    float wsum = 0,wavg = 0;
    for(int i = 1; i< n; i++ ){
        sum += bt[i - 1];
        wt[i] = sum - at[i];
        wsum += wt[i];
    }
    wavg = wsum/n;
    printf("%f",wavg);
    printf("\nProcess\t Burst\t Arrival\t Waiting" );
    for(int i=0;i<n;i++)
    {
        printf("\n p%d\t %d\t %d\t\t %d",p[i],bt[i],at[i],wt[i]);
    }
 
    
    
    
    
    
    
    
}
