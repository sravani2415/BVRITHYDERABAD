// Banker's Algorithm
#include <stdio.h>
int main()
{
	int re, pr;
    printf("Enter number of resources & processes : ");
    scanf("%d%d", &re, &pr);
    int avail[re];
    int initial_alloc[pr][re];
    int max_alloc[pr][re];
    int need[pr][re];
    

    printf("\nEnter total allocation of resources:\n");
    for (int i = 0; i < re ; i++) {
        scanf("%d", &avail[i]);
    }
    printf("\nEnter initial allocation matrix:\n");
    for (int i = 0; i < pr; i++) {
        for (int j = 0; j < re; j++) {
            scanf("%d", &initial_alloc[i][j]);
        }
    }
    printf("\nEnter maximum allocation matrix:\n");
    for (int i = 0; i < pr; i++) {
        for (int j = 0; j < re; j++) {
            scanf("%d", &max_alloc[i][j] );
        }
    }

    int visited[pr];
    for (int i = 0; i < pr; i++) {
        visited[i] = 0;
        for (int j = 0; j < re; j++) {
            need[i][j] = max_alloc[i][j] - initial_alloc[i][j];
        }
    }

    for (int i = 0; i < pr; i++) {
        for (int j = 0; j < re; j++) {
            avail[j] -= initial_alloc[i][j];
        }
    }
    int safe_seq[pr];
    int ind = 0;

    printf("One safe sequence: ");
    for (int k = 0; k < pr; k++) {
        for (int i = 0; i < pr; i++) {
            if (visited[i] == 0) {
                int flag = 1;
                for (int j = 0; j < re; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }

                if (flag) {
                    safe_seq[ind++] = i + 1;
                    visited[i] = 1;
                    for (int j = 0; j < re; j++)
                        avail[j] += initial_alloc[i][j];
                    printf("\nWork of processs %d is done available sources: ", i+1);
                    for(i = 0; i < re; i++)
                        printf("%d ", avail[i]);
            }
        }
        
    }
}
printf("\nSystem is in safe state and the safe sequence is: ");
for (int i = 0; i < pr; i++)
    printf("%d ", safe_seq[i]);
}
