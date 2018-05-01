/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#include <stdio.h>
#include "sort.h"

void bubble_sort(Type *v, int n) {
    int i, j;

    // Stores the i-th element.
    int x;

    for(i = 0; i < n - 1; i++) {
        for(j = 1; j < n; j++) {
            // For each iteration, compares two contiguous positions and
            // swap them if the rightmost element is larger.
            if(v[j] < v[j - 1]) {
                x = v[j];
                v[j] = v[j - 1];
                v[j - 1] = x;
            }
        }
    }
}
