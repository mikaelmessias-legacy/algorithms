#include <stdio.h>
#include "sort.h"

/* @brief Prints an entire array.
 * @param v[] The array to be printed.
 * @param n The maximum array size.
 */
void printa(int v[], int n);

int main() {
    int v[] = {8, 7, 2, 9, 1};
    int lenght = sizeof v / sizeof v[0];

    printf("Original:\n");
    printa(v, lenght);

    bubble_sort(v, lenght);

    printf("\nBubble Sort:\n");
    printa(v, lenght);

    return 0;
}

void printa(int v[], int n) {
    int i;

    for(i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
}
