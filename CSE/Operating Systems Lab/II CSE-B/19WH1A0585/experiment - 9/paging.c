#include<stdio.h>

#define MAX 50

int main(){

	int msize = MAX;

	int pagesize, nofpage;

	int p[100];

	int framenum, offset,logadd, phyadd;
	int choice = 0;

	printf("Memory Size: %d\n",msize);

	printf("Enter size of the page : ");

	scanf("%d",&pagesize);

	nofpage = msize / pagesize;

	int i;

	for(i=0;i<nofpage;i++){

		printf("\nEnter the frame of page%d:",i+1);

		scanf("%d",&p[i]);

	}

	do

	{

		printf("\nEnter a logical address:");

		scanf("%d",&logadd);

		framenum = logadd/pagesize;

		offset = logadd % pagesize;

		phyadd=(p[framenum]*pagesize)+offset;

		printf("\nPhysical address is:%d",phyadd);

		printf("\nDo you want to continue(1/0)?:");

		scanf("%d",&choice);

		}while(choice==1);
}


