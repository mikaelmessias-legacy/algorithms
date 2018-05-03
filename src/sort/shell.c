/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#include <stdio.h>
#include "sort.h"

void shell_sort(Type *v, int n) {
    int i, j;

    // Stores the leap between the elements to be compared.
    int h = 1;

    // Initial leap is calculated.
    do h = h * 3 + 1; while(h < n);

    do {
        // This line is here to prevent the h leap to
        // start bigger than the vector size.
        h /= 3;

        for(i = h; i < n; i++) {
            // Stores the i-th element.
            Type x = v[i];
            j = i;

            while(v[j - h] > x && j >= h) {
                // Pushes bigger elements one position to the right
                v[j] = v[j - h];
                j -= h;
            }

            // Inserts the i-th element in its appropriate position
            v[j] = x;
        }
    } while(h != 1);
}
