#include<stdio.h>

void wait(int *s){
	*s--;
}

void signal(int *s){
	*s++;
}

void dining(int n)
{

	int chopstick[n], i;
	for(i = 0; i < n; i++)
		chopstick[i] = 1;
	for (i = 0; i < n; i++){
		wait( &chopstick[i]);
		wait( &chopstick[(i + 1) % n]);
		printf("Process %d Eating\n", i + 1);
		signal( &chopstick[i]);
		signal( &chopstick[(i + 1) % n]);
		printf("Process %d Thinking\n", i + 1);
    }
}

int main(){
	int n;
	printf("Enter number of processes: ");
	scanf("%d", &n);
	dining(n);
}
