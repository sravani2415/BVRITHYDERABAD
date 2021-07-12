#include<stdio.h>
#include<stdlib.h>

int mutex = 1, empty = 3, full = 0, item = 0;
int wait(int s)
{
	return (--s);
}

int signal(int s)
{
	return (++s);
}

void producer()
{
	mutex = wait(mutex);
	full  = signal(full);
	empty = wait(empty);
	item++;
	printf("producer produces the item: %d\n", item);
	mutex = signal(mutex);
}

void consumer()
{
	mutex = wait(mutex);
	full  = wait(full);
	empty = signal(empty);
	printf("consumer consumes the item: %d\n", item);
	item--;
	mutex = signal(mutex);
}
int main()
{
	int n;	
	printf("select\n1 - producer\n2 - consumer\n3 -exit\n");
	while(1)
	{
		printf("enter your choice\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: 	if((mutex == 1) && (empty != 0))
					producer();
				else
					printf("Buffer is full\n");
				break;
			case 2: 	if((mutex == 1) && (full != 0))
					consumer();
				else
					printf("Buffer is empty\n");
				break;
			case 3: exit(0);
				break;
		}
	}
}
