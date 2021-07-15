#include<stdio.h>

int resources;
int n;

int main() {
    printf("Enter no. of resources : ");
    scanf("%d", &resources);

    int allocation_of_resources[resources];
    printf("Enter total allocation of resources : ");
    for(int i = 0 ; i < resources ; i++) {
        scanf("%d", &allocation_of_resources[i]);
    }

    printf("Enter no. of processes : ");
    scanf("%d", &n);

    int max_allocation[n][resources], allocation[n][resources], need_matrix[n][resources];
    int available[resources];

    printf("Enter initial allocation matrix : ");
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < resources ; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter max allocation matrix : ");
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < resources ; j++) {
            scanf("%d", &max_allocation[i][j]);
        }
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < resources ; j++) {
            need_matrix[i][j] = max_allocation[i][j] - allocation[i][j];
        }
    }

    printf("Enter available resources : ");
    for(int i = 0 ; i < resources ; i++) {
        scanf("%d", &available[i]);
    }

    int work[resources], finish[n];
    for(int i = 0 ; i < resources ; i ++) {
        work[i] = available[i];
    }

    for(int i = 0 ; i < n ; i ++) {
        finish[i] = 0;
    }

    int safeSeq[n], count = 0;

    _Bool found;
    while (count < n) {
        found = 0;
        for (int i = 0 ; i < n ;i++) {
            if (finish[i] == 0) {
                int j;
                for(j = 0 ; j < resources; j++) {
                    if (need_matrix[i][j] > work[j])
                        break;
                }
                if (j == resources) {
                    for(int k = 0 ; k < resources ; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("System is not in safe state\n");
        }
    }

    if (found == 1){
        printf("\nSystem is in safe state\nSafe sequence: \n");
        for(int i = 0 ; i < n ; i++) {
            printf("%d ", safeSeq[i]);
        }
        printf("\n");
    }

    return 0;
}


