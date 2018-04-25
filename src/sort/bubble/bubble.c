#include <stdio.h>
#include "../sort.h"

void bubble_sort(int v[], int n) {
    int i, j;

    // Stores the i-th element.
    int x;

    for(i = 0; i < n - 1; i++) {
        for(j = 1; j < n; j++) {
            // For each iteration, compares two contiguous positions and
            // change them if the rightmost element is larger.
            if(v[j] < v[j - 1]) {
                x = v[j];
                v[j] = v[j - 1];
                v[j - 1] = x;
            }
        }
    }
}
