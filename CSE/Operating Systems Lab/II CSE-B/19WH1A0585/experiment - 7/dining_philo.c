#include<stdio.h>

void signal(int *s)
{
	*s++;
}

void wait(int *s)
{
	while(*s <= 0)
	{
		*s--;
	}
}

void philosopher(int n)
{
	int chopstick[n];
	for(int i = 0; i < n; i++)
	{
		chopstick[i] = 1;
	}
	int i = 0;
	do {
		wait(&chopstick[i]);
		wait(&chopstick[(i + 1) % n]);
		printf("process %d thinking\n", i + 1);
		signal(&chopstick[i]);
		signal(&chopstick[(i + 1) % n]);
		printf("process %d eating\n", i + 1);
		i = ((i + 1) % n);
	} while(1);
}

int main()
{
	int n;
	printf("Enter no.of processes: \n");
	scanf("%d", &n);
	philosopher(n);
	return 0;
}
