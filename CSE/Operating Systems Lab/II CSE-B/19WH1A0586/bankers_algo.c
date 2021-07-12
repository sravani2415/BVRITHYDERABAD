#include<stdio.h>
int main()
{
	int p, r , i, j, k;
	printf("Enter total number of processes:\n");	
	scanf("%d", &p);
	printf("Enter total number of resourses:\n");
	scanf("%d", &r);
	int allocate[p][r], max_need[p][r], rem_need[p][r], available[r];
	printf("Enter allocation instances:\n");
	for(i = 0; i < p; i++)
	{
		for(j = 0; j < r; j++)
			scanf("%d", &allocate[i][j]);
	}
	printf("Enter maximum instances:\n");
	for(i = 0; i < p; i++)
	{
		for(j = 0; j  < r; j++)
			scanf("%d", &max_need[i][j]);
	}
	printf("Enter available resources:\n");
	for(i = 0; i < r; i++)
		scanf("%d", &available[i]);
	for(i = 0; i < p; i++)
	{
		for(j = 0; j < r; j++)
			rem_need[i][j] = max_need[i][j] - allocate[i][j];
	}
	int f[p], res[p], index = 0;
	for(i = 0; i < p; i++)
		f[i] = 0;
	int x = 0;
	for(k = 0; k < p; k++)
	{
		for(i = 0; i < p; i++)
		{
			if(f[i] == 0)
			{
				int flag = 0;
				for(j = 0; j < r; j++)
				{
					if(rem_need[i][j] > available[j])
					{
						flag = 1;
						break;
					}
				}
				if(flag == 0)
				{
					res[index++] = i;
					for(x = 0; x < r; x++)
						available[x] += allocate[i][x];
					f[i] = 1;
				}
			}
		}
	}
	printf("Safe sequence\n");
	printf("<");
	for(i = 0; i < p; i++)
		printf("p%d->", res[i]);
	printf(">\n");
	return 0;
}
