#include <stdio.h>

int main() {
    int n, i, j;
    int requests[50];
    int visited[50] = {0};
    int head, total_movement = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk requests:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);

    for(i = 0; i < n; i++) {
        int min = 100000, index = -1;

        // Find closest unvisited request
        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                int distance = requests[j] - head;
                if(distance < 0)
                    distance = -distance;

                if(distance < min) {
                    min = distance;
                    index = j;
                }
            }
        }

        // Mark as visited
        visited[index] = 1;

        // Move head
        total_movement += min;
        head = requests[index];

        printf(" -> %d", head);
    }

    printf("\n\nTotal Head Movement: %d\n", total_movement);

    return 0;
}
