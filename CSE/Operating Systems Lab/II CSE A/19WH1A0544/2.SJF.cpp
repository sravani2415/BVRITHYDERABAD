#include <stdio.h>

void swap(int, int);
void bubbleSort(int b[], int);
void process_order(int p[], int b[], int);

int main(){
	int n, i, j;
	float avg_w, avg_t;
	printf("Enter no.of process: ");
	scanf("%d", &n);
	int p[n], b[n], w[n], t[n];
	   
	// inputting Burst time
	for(i = 0; i < n; i++){
	    printf("Enter burst time of p[%d]: ", i+1);
		scanf("%d", &b[i]);
	}
	 
	process_order(p, b, n);
	bubbleSort(b, n);
    
	
	w[0] = 0;
	t[0] = b[0];
	avg_w = w[0];
	avg_t = t[0];
	 
	for(i = 1; i < n; i++){
		w[i] = w[i-1] + b[i-1];
		t[i] = t[i-1] + b[i];
		avg_w += w[i];
		avg_t += t[i];
	} 
	
	printf("Process      Burst time     Waiting time    Turnaround time\n");
	for(i = 0; i < n; i++){
	printf("p[%d]\t\t%d\t\t%d\t\t%d\n", i+1, b[i], w[i], t[i]);
	}
	 
	printf("Average waiting Time = %.2f\n", (avg_w / n));
	printf("Average Turn around Time = %.2f", (avg_t / n));	
}

void process_order(int p[], int b[], int n){
	
}

void swap(int *num1, int *num2) {
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}
