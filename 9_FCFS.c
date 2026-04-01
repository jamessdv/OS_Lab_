#include <stdio.h>

int main() {
    int n, i;
    int requests[50];
    int head, total_movement = 0;

    // Input number of requests
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    // Input request sequence
    printf("Enter the disk requests:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    // Input initial head position
    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);

    // FCFS logic
    for(i = 0; i < n; i++) {
        int movement = requests[i] - head;

        if(movement < 0)
            movement = -movement;   // absolute value

        total_movement += movement;
        head = requests[i];

        printf(" -> %d", head);
    }

    printf("\n\nTotal Head Movement: %d\n", total_movement);

    return 0;
}
