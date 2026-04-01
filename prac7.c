#include <stdio.h>

int main() {
    int n, m, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], req[n][m], avail[m];
    int finish[n];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &req[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int count = 0;

    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int flag = 1;

                for(j = 0; j < m; j++) {
                    if(req[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }

                if(flag == 1) {
                    for(j = 0; j < m; j++) {
                        avail[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    found = 1;
                    count++;
                    printf("Process %d executed\n", i);
                }
            }
        }

        if(found == 0) {
            break;
        }
    }

    //checking for deadlock
    int deadlock = 0;
    for(i = 0; i < n; i++) {
        if(finish[i] == 0) {
            deadlock = 1;
            printf("Process %d is in deadlock\n", i);
        }
    }

    if(deadlock == 0) {
        printf("\nNo Deadlock detected.\n");
    } else {
        printf("\nDeadlock detected.\n");
    }

    return 0;
}