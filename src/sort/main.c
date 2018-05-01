/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#include <stdio.h>
#include "sort.h"

int main() {
    int v[] = {8, 7, 2, 9, 1};
    int lenght = sizeof v / sizeof v[0];

    printf("Original:\t");
    vector_print(v, lenght);

    bubble_sort(v, lenght);

    printf("Bubble Sort:\t");
    vector_print(v, lenght);

    return 0;
}
