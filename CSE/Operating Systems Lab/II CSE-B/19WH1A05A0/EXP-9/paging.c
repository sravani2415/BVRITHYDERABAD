#include<stdio.h>
int main()
{
	int msize, psize, pages, p[100], frameno, offset;
	int logadd, phyadd, i, choice = 0;
	printf("Enter Memory size: ", msize);
	scanf("%d", &msize);
	printf("\nEnter page size: ");
	scanf("%d", &psize);
	pages = msize / psize;
	for(i =0; i < pages; i++)
	{
		printf("\nEnter the frame of page%d: ", i + 1);
		scanf("%d", &p[i]);
	}
	do
	{
		printf("\nEnter a logical address: ");
		scanf("%d", &logadd);
		frameno = logadd / psize;
		offset = logadd % psize;
		phyadd = (p[frameno] * psize) + offset;
		printf("\nPhysical address is:%d",phyadd);
		printf("\nDo you want to continue(1/0)?: ");
		scanf("%d",&choice);
	}while(choice == 1);
	return 0;
}