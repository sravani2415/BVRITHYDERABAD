#include <stdio.h>
int main() {
    int m, n,i,j,k,p;
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int available[m];
    printf("Enter total allocation of resources: ");

    for (i = 0; i < m; i++)
        scanf("%d", &available[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int max[n][m];
    int allocation[n][m];
    int need[n][m];

    printf("Enter the number of resources allocated by each process: ");

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    }

    printf("Enter the max need of each process: ");

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            available[j] -= allocation[i][j];
        }
    }

    int visited[n];

    for (i = 0; i < n; i++) {
            visited[i] = 0;
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    }

    //check if a process can be allocated with the avail resources
    int safe_seq[n];
    int ind = 0;

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (visited[i] == 0) {
                int flag = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        flag = 0;
                        break;
                    }
                }

                if (flag) {
                    safe_seq[ind++] = i + 1;
                    visited[i] = 1;
                    // update available
                    for (j = 0; j < m; j++)
                        available[j] += allocation[i][j];
                    printf("\nProcess %d is done and after releasing, free resources are: ", i+1);
                    for (p = 0; p < m; p++)
                        printf("%d ", available[p]);
                }
            }
        }
    }
    printf("\nSystem is in safe state and the safe sequence is: ");
    for (i = 0; i < n; i++)
        printf("%d ", safe_seq[i]);
}
