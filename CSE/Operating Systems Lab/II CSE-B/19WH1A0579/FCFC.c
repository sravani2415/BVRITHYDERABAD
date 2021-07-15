#include<stdio.h>
int main(){
    int p;//p is number of processes
    printf("ENTER THE NUMBER OF PROCESSES\n");
    scanf("%d",&p);
    int at[p],et[p],st[p],wt[p];//arrival time, execution time, service time, waiting time
    float sum = 0;
    for(int i=0; i<p; i++){
        printf("ENTER THE ARRIVAL AND EXECUTION TIME OF PROCESS %d\n",i+1);
        scanf("%d%d",&at[i],&et[i]);
    }
    st[0] = wt[0] =  0;

    for(int i = 1; i< p; i++){
        st[i] = st[i - 1] + et[i - 1];
        wt[i] = st[i] - at[i];
        sum += wt[i];
    }
    printf("\nAVERAGE WAITING TIME = %.2f\n",sum/p);
}