#include<stdio.h>
int main()
{
	int a[10][10], b[100], i, j, n, x, base, size, segment_no, offset;
	printf("Enter the segment count: \n");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("Enter %d size: \n", i+1);
		scanf("%d", &size);
		a[i][0] = size;
		printf("Enter the base address: \n");
		scanf("%d", &base);
		a[i][1] = base;
		for(j=0;j<size;j++)
		{
			x = 0;
			scanf("%d", &x);
			base++;
			b[base] = x;
		}
	}
	printf("Enter the segment number and offset value: \n");
	scanf("%d%d", &segment_no, &offset);
	if(offset < a[segment_no][0])
	{
		int abs = a[segment_no][1] + offset;
		printf("The offset is less than %d\n", a[segment_no][0]);
		printf("\n%d + %d = %d\n", a[segment_no][1], offset, abs);
		printf("The element %d is at %d\n", b[abs+1], abs);
	}
	else
	{
		printf("ERROR IN LOCATING");
	}
	return 0;
}
