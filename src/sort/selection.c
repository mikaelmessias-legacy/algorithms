/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#include <stdio.h>
#include "sort.h"

void selection_sort(Type *v, int n) {
    int i, j, smaller;

    for(i = 0; i < n-1; i++) {
        smaller = i;

        for(j = i + 1; j < n; j++) {
            // Searches if the smaller index stores an element larger
            // than those one position head until n.
            // in v[smaller].
            if(v[j] < v[smaller]) {
                smaller = j;
            }
        }

        // If there is no element smaller than the smaller position,
        // prevents unnecessarily call for function vector_swap.
        if(smaller != i) {
            vector_swap(v, smaller, i);
        }
    }
}
