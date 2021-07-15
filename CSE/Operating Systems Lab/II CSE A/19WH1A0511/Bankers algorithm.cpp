# include<stdio.h>
int main()
{
	int i;
	int avail[nr];
	printf("Enter total allocation of resources: ";)
	for(i=0;i<nr;i++){
		scanf("%d",&avail[i]);
	}
	printf("Enter no.of processes: ");
	scanf("%d",&pr);
	int initial[pr][nr],max_alloc[pr][nr],needm[pr][nr];
	
	printf("Enter initial allocation matrix: ");
	for(i=0;i<pr;i++){
		for(j=0;j<nr;j++)
		    scanf("%d",&initial[i][j])
	}
	printf("Enter the max need of each process: ");
	for(i=0;i<pr;i++){
		for(j=0;j<nr;j++)
		   scanf("%d",&max_allocm[i][j]);
	}
	
	for(int i=0;i<pr;i++){
		for(int j=0;j<nr;j++){
			avail[j] -=initial[i][j];
		}
	}
	int visited[pr];
	for(int i=0;i<pr;i++){
		
	}
	
}
