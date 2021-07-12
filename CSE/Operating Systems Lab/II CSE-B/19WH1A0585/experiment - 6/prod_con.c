#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
int mutex = 1, empty = SIZE, full = 0, item = 0;



void producer()
{
	--mutex;
	++full;
	--empty;
	printf("producer produces: %d\n", ++item);
	++mutex;
}

void consumer()
{
	--mutex;
	--full;
	++empty;
	printf("consumer consumes: %d\n", item--);
	++mutex;
}


int main()
{
	int n;
	printf("1.producer  2.consumer  3. exit\n");
	while(1)
	{
		scanf("%d", &n);
		switch(n)
		{
			case 1: if((mutex == 1) && (empty != 0))
					producer();
				else
					printf("buffer is full\n");
				break;
			case 2: if((mutex == 1) && (full != 0))
					consumer();
				else
					printf("buffer is empty\n");
				break;
			case 3: exit(0);
				break;
		}
	}
	return 0;
}
