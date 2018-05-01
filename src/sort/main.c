/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#include <stdio.h>
#include "sort.h"

#define N 10

int main() {
    Type *v = vector_create(N);

    printf("Original:\n");
    vector_print(v, N);

    bubble_sort(v, N);

    printf("\nBubble Sort:\n");
    vector_print(v, N);

    v = vector_free(v);

    return 0;
}
