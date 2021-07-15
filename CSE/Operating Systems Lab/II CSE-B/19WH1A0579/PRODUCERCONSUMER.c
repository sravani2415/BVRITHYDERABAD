#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty = 10, x = 0;

int wait(int S){
    while(S<=0);   
    return --S;
}

int signal(int S){
    return ++S;
}
void producer()
{
	empty = wait(empty);
	mutex = wait(mutex);
	mutex = signal(mutex);
    full = signal(full);
    //printf("\n%d",empty);
	x++;
	printf("\nProducer producesitem %d",x);
}
void consumer()
{
    
	full = wait(full);
    mutex = wait(mutex);
    mutex = signal(mutex);
    empty = signal(empty);
    printf("\nConsumer consumes item %d",x);
	x--;
}

int main()
{
	int n;
	printf("\n1. Press 1 for Producer"
		"\n2. Press 2 for Consumer"
		"\n3. Press 3 for Exit");

    while(1){

		printf("\nEnter your choice:");
		scanf("%d", &n);

		switch (n) {
		    
		
		case 1:

			if ((mutex == 1)&& (empty != 0)) {
				    producer();
			}

			else {
				printf("Buffer is full!");
			}
			break;

		case 2:

			if ((mutex == 1)&& (full != 0)) {
				consumer();
			}

			
			else {
				printf("Buffer is empty!");
			}
			break;

		case 3:
			exit(0);
			break;
		
	    }
    }
}
