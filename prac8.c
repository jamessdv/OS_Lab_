#include <stdio.h>

int main() {
    int f, p, i, j, k, page_faults = 0, current = 0;
    int frames[10], pages[30], found;

    printf("Enter no. of frames: ");
    scanf("%d", &f);
    
    for(i = 0; i < f; i++) frames[i] = -1;

    printf("Enter no. of pages: ");
    scanf("%d", &p);

    printf("Enter the pages in sequence: ");
    for(i = 0; i < p; i++) {
        scanf("%d", &pages[i]);
    }

    printf("\nRef String | Frames\n");
    for(i = 0; i < p; i++) {
        found = 0;

	for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frames[current] = pages[i];    
            current = (current + 1) % f;   
            page_faults++;
            
            printf("%d\t   | ", pages[i]);
            for(k = 0; k < f; k++) {
                if(frames[k] != -1) printf("%d ", frames[k]);
                else printf("- ");
            }
            printf("\n");
        } else {
            printf("%d\t   | Hit\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}