#include<stdio.h>
int main()
{
	int memory_size = 20;
	int page_size, no_of_page;
	int p[100];
	int frame_no, offset;
	int logical_address, physical_address;
	int i;
	int choice = 0;
	printf("Your memory size is %d\n",memory_size);
	printf("\nEnter page size: ");
	scanf("%d",&page_size);
	no_of_page = memory_size / page_size;
	for(i=0;i<no_of_page;i++)
	{
		printf("\nEnter the frame of page %d: ",i+1);
		scanf("%d",&p[i]);
	}
	do
	{
		printf("\nEnter a logical address:");
		scanf("%d",&logical_address);
		frame_no = logical_address / page_size;
		offset = logical_address % page_size;
		physical_address = (p[frame_no] * page_size) + offset;
		printf("\nPhysical address is: %d\n", physical_address);
		printf("\nDo you want to continue(1/0)?: ");
		scanf("%d",&choice);
	} while(choice == 1);
return 0;
}
