/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#include <stdio.h>
#include "sort.h"

/**
 * @brief Chooses a pivot and places it in its correct position in the sorted
 * vector, moves the smallest elements to the left of the pivot and the largest
 * ones to the right.
 * @param v The vector.
 * @param l The smallest position.
 * @param r The largest position.
 * @return
 */
static int quick_partition(Type *v, int l, int r) {
    Type x = v[r];

    // Index of smaller element.
    int i = (l - 1), j;

    for(j = l; j <= r - 1; j++) {
        // If current element is smaller than or equal to pivot.
        if(v[j] <= x) {
            i++;
            vector_swap(v, i, j);
        }
    }

    vector_swap(v, i + 1, r);

    return (i + 1);
}

static void quick_split(Type *v, int l, int r) {
    int p;

    if(l < r) {
        // p is the partitioning index, v[p] is now at right place.
        p = quick_partition(v, l, r);

        quick_split(v, l, p - 1);
        quick_split(v, p + 1, r);
    }
}

void quick_sort(Type *v, int n) {
    quick_split(v, 0, n - 1);
}
