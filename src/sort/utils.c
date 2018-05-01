/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

Type* vector_create(int n) {
    int i;

    Type *v = malloc(n * sizeof(Type));

    if(v == NULL) {
        return NULL;
    }
    else {
        srand(time((void*) v));

        for(i = 0; i < n; i++) {
            v[i] = rand() % n;
        }
    }

    return v;
}

void vector_print(Type *v, int n) {
    int i;

    printf("[");

    for(i = 0; i < n; i++) {
        printf("%d", v[i]);
        if(i < n-1) {
            printf(", ");
        }
    }

    printf("]\n");

}
