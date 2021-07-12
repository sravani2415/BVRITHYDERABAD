#include<stdio.h>

void wait(int *S){
	while(*S <= 0);
	{
		*S--;
	}
}

void signal(int *S){
	*S++;
}

void philosopher(int n){
	int i;
	int chopstick[n];
	for(i = 0 ; i < n ; i++)
		chopstick[i] = 1;
	
	i = 0;
	do{
		wait(&chopstick[i]);
		wait(&chopstick[(i + 1) % n]);
		printf("Process %d thinking\n",i + 1);
		signal(&chopstick[i]);
		signal(&chopstick[(i + 1) % n]);
		printf("Process %d eating\n",i + 1);
		i = ((i + 1) % n);
	}while(1);
}
int main(){
	int n;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	philosopher(n);
	return 0;

}
