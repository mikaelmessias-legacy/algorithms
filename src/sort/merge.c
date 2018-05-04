/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

static void merge(Type *v, int l, int m, int r) {
    int i = l;
    int j = m;
    int k = 0;

    // Temporary vector
    Type *w = malloc ((r - l) * sizeof(Type));

    // Copies smaller elements to the left side and largest to the right side
    // of the w vector.
    while(i < m && j < r) {
        if(v[i] <= v[j]) {
            w[k++] = v[i++];
        }
        else {
            w[k++] = v[j++];
        }
    }

    // Copies the remaining elements until it reaches the middle of the original
    // vector.
    while(i < m) {
        w[k++] = v[i++];
    }

    // Copies the remaining elements until it reaches the end of the original
    // vector.
    while(j < r) {
        w[k++] = v[j++];
    }

    // Copies the sorted elements of the temporary vector back to the original
    // vector.
    for (i = l; i < r; i++) {
        v[i] = w[i - l];
    }

   w = vector_free(w);
}

static void mergesort(Type *v, int l, int r) {
    if(l < r - 1) {
        int m = (l + r) / 2;

        // Sort first and second halves
        mergesort(v, l, m);
        mergesort(v, m, r);

        // Merge the halves keeping them sorted
        merge(v, l, m, r);
    }
}

void merge_sort(Type *v, int n) {
    mergesort(v, 0, n);
}
