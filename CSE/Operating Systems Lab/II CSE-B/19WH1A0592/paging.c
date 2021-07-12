#include<stdio.h>
int  main()
{
	int memory_size=15;
	int pagesize,no_ofpage;
	int p[100];
	int frameno,offset;
	int logical_add,physical_add;
	int i;
	int choice=0;
	printf("\nYour memory_size is %d",memory_size);
	printf("\nEnter page size:");
	scanf("%d",&pagesize);

	no_ofpage=memory_size/pagesize;

	for(i=0;i<no_ofpage;i++)
	{
		printf("\nEnter the frame of page%d:",i+1);
		scanf("%d",&p[i]);
	}
	do
	{
		printf("\nEnter the logical address:");
		scanf("%d",&logical_add);
		frameno = logical_add/pagesize;
		offset = logical_add%pagesize;
		physical_add = (p[frameno]*pagesize)+offset;
		printf("\nPhysical address is %d",physical_add);
		printf("\nDo you want to continue(1/0):");
		scanf("%d",&choice);
	}
	while(choice==1);
	return 0;
}