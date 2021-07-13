#include<stdio.h>
#include<stdlib.h>

int mutex = 1 , empty = 4 , full = 0 , item = 0;

int wait(int S){
		return --S;
	
}


int signal(int S){
	return ++S;
}


void producer(){
	mutex = wait(mutex);
	full = signal(full);
	empty = wait(empty);
	item++;
	printf("Producer producing the item : %d\n",item);
	mutex = signal(mutex);
}

void consumer(){
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);
	printf("Consumer consuming the item : %d\n",item);
	item--;
	mutex = signal(mutex);
}

int main(){
	int n;
	printf("Select your choice:\n");
	printf("1.Producer\n2.Consumer\n3.Exit\n");
	while(1){
		printf("Enter your choice:\n");
		scanf("%d",&n);
		switch(n){
			case 1 :if((mutex == 1) && (empty != 0))
						producer();
					else
						printf("Buffer is Full\n");
					break;
			case 2 :if((mutex == 1) && (full != 0))
						consumer();
					else
						printf("Buffer is Empty\n");
					break;
			case 3 :exit(0);
					break;
					
			
		}
	}
}
