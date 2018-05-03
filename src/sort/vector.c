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

    Type *v = calloc(n, sizeof(Type));

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

Type* vector_create_ascending(int n) {
    int i, j;

    Type *v = calloc(n, sizeof(Type));

    if(v != NULL) {
        srand(time((void*) v));

        for(i = 0; i < n; i++) {
            Type x = rand() % n;

            int k = 0;

            while(x > v[k] && k < i) {
                k++;
            }

            j = i;

            while(j > k) {
                v[j] = v[j - 1];
                j--;
            }

            v[j] = x;
        }

        return v;
    }

    return NULL;
}

Type* vector_create_descending(int n) {
    int i, j;

    Type *v = calloc(n, sizeof(Type));

    if(v != NULL) {
        srand(time((void*) v));

        for(i = 0; i < n; i++) {
            Type x = rand() % n;

            int k = n - 1;

            int elements = 0;

            while(x > v[k] && k > (k - i)) {
                k--;
            }

            j = n - i - 1;

            while(j < k) {
                v[j] = v[j + 1];
                j++;
            }

            v[j] = x;
        }

        return v;
    }

    return NULL;
}

void vector_print(Type *v, int n) {
    if(v == NULL) {
        return;
    }

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

int vector_isSorted(Type *v, int n) {
    if(v == NULL) {
        return -1;
    }

    int i;

    for(i = 1; i < n; i++) {
        if(v[i - 1] > v[i]) {
            return 0;
        }
    }

    return 1;
}

Type* vector_free(Type *v) {
    if(v != NULL) {
        free(v);
    }

    return NULL;
}

void vector_swap(Type *v, int a, int b) {
    Type x = v[a];
    v[a] = v[b];
    v[b] = x;
}
