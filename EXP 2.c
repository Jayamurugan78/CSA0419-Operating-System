#include <stdio.h>

int main() {
int num_frames = 3; // number of page frames
int page_sequence[] = {4, 1, 2, 4, 3, 2, 1, 5}; // page reference sequence
int page_frames[num_frames]; // array to store current page frames
int page_faults = 0; // variable to store number of page faults
int i, j, k;

// initialize all page frames to -1 to indicate that they are empty
for (i = 0; i < num_frames; i++) {
    page_frames[i] = -1;
}

// iterate through the page reference sequence
for (i = 0; i < sizeof(page_sequence)/sizeof(page_sequence[0]); i++) {
    int page = page_sequence[i];
    int page_found = 0;

    // check if the current page is already in one of the page frames
    for (j = 0; j < num_frames; j++) {
        if (page_frames[j] == page) {
            page_found = 1;
            break;
        }
    }

    // if the page is not in any of the page frames, replace the oldest page
    if (!page_found) {
        int oldest_page_index = 0;

        // find the index of the oldest page
        for (j = 0; j < num_frames; j++) {
            if (page_frames[j] == -1) {
                oldest_page_index = j;
                break;
            }

            if (page_frames[j] < page_frames[oldest_page_index]) {
                oldest_page_index = j;
            }
        }

        // replace the oldest page with the current page
        page_frames[oldest_page_index] = page;
        page_faults++;
    }

    // print the current state of the page frames
    printf("Page Frames: ");
    for (j = 0; j < num_frames; j++) {
        if (page_frames[j] == -1) {
            printf("-");
        } else {
            printf("%d", page_frames[j]);
        }
    }

    // print whether a page fault occurred or not
    if (page_found) {
        printf("\tPage %d: Hit", page);
    } else {
        printf("\tPage %d: Fault", page);
    }

    printf("\n");
}

// print the total number of page faults
printf("Number of Page Faults: %d\n", page_faults);

return 0;
}
