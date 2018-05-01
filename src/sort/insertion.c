/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#include <stdio.h>
#include "sort.h"

void insertion_sort(Type *v, int n) {
    int i, j;

    // Stores the i-th element.
    Type x;

    for(i = 1; i < n; i++) {
        x = v[i];
        j = i - 1;

        // Searches for elements smaller than the i-th element.
        while(j >= 0 && x < v[j]) {
            v[j + 1] = v[j];
            j--;
        }

        // The i-th element is allocated in its appropriate position.
        v[j + 1] = x;
    }
}
