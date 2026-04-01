#include <stdio.h>

int main() {
    int n, i, j, temp;
    int requests[50];
    int head, direction;
    int total_movement = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter the disk requests:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (1 for high, 0 for low): ");
    scanf("%d", &direction);

    // Sort requests (simple bubble sort)
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(requests[j] > requests[j + 1]) {
                temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    printf("\nSeek Sequence: %d", head);

    int index;
    // Find position where head would be in sorted array
    for(i = 0; i < n; i++) {
        if(head < requests[i]) {
            index = i;
            break;
        }
    }

    // If direction is towards higher values
    if(direction == 1) {
        // Move right
        for(i = index; i < n; i++) {
            total_movement += (requests[i] - head);
            head = requests[i];
            printf(" -> %d", head);
        }

        // Then move left
        for(i = index - 1; i >= 0; i--) {
            total_movement += (head - requests[i]);
            head = requests[i];
            printf(" -> %d", head);
        }
    }
    // If direction is towards lower values
    else {
        // Move left
        for(i = index - 1; i >= 0; i--) {
            total_movement += (head - requests[i]);
            head = requests[i];
            printf(" -> %d", head);
        }

        // Then move right
        for(i = index; i < n; i++) {
            total_movement += (requests[i] - head);
            head = requests[i];
            printf(" -> %d", head);
        }
    }

    printf("\n\nTotal Head Movement: %d\n", total_movement);

    return 0;
}
