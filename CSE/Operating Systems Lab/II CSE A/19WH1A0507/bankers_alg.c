#include <stdio.h>

int main(){
    int processes, resources, i, j;
    printf("Enter no. of resources: ");
    scanf("%d", &resources);
    int available[resources]; //allocated will be converted to available
    printf("Enter total allocation of resources: ");
    for (i = 0; i < resources; i++)
        scanf("%d", &available[i]);
    printf("Enter no. of processes: ");
    scanf("%d", &processes);
    int init_alloc[processes][resources], max_alloc[processes][resources], need_mat[processes][resources];
    int flag, safe_seq[processes], visited[processes];
    printf("Enter initial allocation matrix ");
    for (i = 0; i < processes; i++){
        visited[i] = 0;
        for (j = 0; j < resources; j++)
            scanf("%d", &init_alloc[i][j]);
    }
    printf("Enter max allocation matrix ");
    for (i = 0; i < processes; i++){
        for (j = 0; j < resources; j++)
            scanf("%d", &max_alloc[i][j]);

    }
    printf("Need matrix is\n");
    for (i = 0; i < processes; i++){
        for (j = 0; j < resources; j++){
            need_mat[i][j] = max_alloc[i][j] - init_alloc[i][j];
            printf("%d ", need_mat[i][j]);
        }
        printf("\n");
    }
    printf("Available resources are\n");
    for (i = 0; i < processes; i++){
        for(j = 0; j < resources; j++)
            available[j] -= init_alloc[i][j];
    }
    for (i = 0; i < resources; i++)
        printf("%d ", available[i]);
    int index = 0;
    for (i = 0; i < processes; i++){
        for (j = 0; j < processes; j++){
            if (visited[j] == 0){
                int flag = 1;
                for (int k = 0; k < resources; k++){
                    if (need_mat[j][k] > available[k]){
                        flag = 0;
                        break;
                    }
                }
                if (flag){
                    safe_seq[index++] = j + 1;
                    visited[j] = 1;
                    for (int a = 0; a < resources; a++)
                        available[a] += init_alloc[j][a];
                    printf("\nWork of process %d is done and after releasing initial allocations, free resources are: ", j + 1);
                    for (int b = 0; b < resources; b++)
                        printf("%d ", available[b]);

                }
            }
        }
    }
    printf("\nSystem is in safe state and the safe sequence is: ");
    for (i = 0; i < processes; i++)
        printf("%d ", safe_seq[i]);
}
