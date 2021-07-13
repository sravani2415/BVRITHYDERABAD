// Banker's Algorithm
#include <stdio.h>
int main()
{
	int n, m, i, j, k;
	n = 5; // Number of processes
	m = 3; // Number of resources
	int alloc[5][3],max[5][3],avail[3];
	int f[n], ans[n], ind = 0;
	printf("Enter elements of allocation matrix\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("Enter elements of maximum matrix\n");
	for(int i=0;i<n;i++)
        {
                for(int j=0;j<m;j++)
                {
                        scanf("%d",&max[i][j]);
                }
        }
	printf("Enter Available resources\n");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
	}
	for (k = 0; k < n; k++)
	{
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	int y = 0;
	for (k = 0; k < 5; k++)
	{
		for (i = 0; i < n; i++)
		{
			if (f[i] == 0)
			{
				int flag = 0;
				for (j = 0; j < m; j++)
				{
					if (need[i][j] > avail[j])
					{
						flag = 1;
						break;
					}
				}
				if(flag == 0)
				{
					ans[ind++] = i;
					for (y = 0; y < m; y++)
					{
						avail[y] += alloc[i][y];
					}
					f[i] = 1;
				}
			}
		}
	}
	printf("SAFE Sequence\n");
	for (i=0;i<n-1;i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d\n", ans[n - 1]);
	return (0);
}

