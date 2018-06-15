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
#include <string.h>

#include "sort.h"

#define TYPES 3
#define SIZES 37
#define TESTS 10

static double runtime[SIZES][TESTS];

int sizes[] = {10, 20, 30, 40, 50, 60, 70, 80, 90,
               100, 200, 300, 400, 500, 600, 700, 800, 900,
               1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000,
               10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000,
               100000};

Type *v;
int i, j;
char filename[100];
clock_t begin_t;

#define EXECUTE(SIMPLE_NAME, FUNCTION_NAME, CREATE, VECTOR_STATUS)        \
    strcpy(filename, "benchmark/");                                     \
    strcat(filename, #SIMPLE_NAME);                                          \
    strcat(filename, "/");                                              \
    strcat(filename, #FUNCTION_NAME);                                   \
    strcat(filename, "_");                                              \
    strcat(filename, #VECTOR_STATUS);                                   \
    strcat(filename, ".csv");                                           \
                                                \
    for(i = 0; i < SIZES; i++) {                                        \
        printf("\n> Line 41: Size: %d\n", sizes[i]);                    \
                                                                        \
        for(j = 0; j < TESTS; j++) {                                    \
            printf("> Line 44: Test %d\n", j);                          \
                                                                        \
            v = CREATE(sizes[i]);                                       \
                                                                        \
            begin_t = clock();                                          \
            FUNCTION_NAME(v, sizes[i]);                                 \
                                                                        \
            runtime[i][j] = (((double) clock() - begin_t) * 1000) /     \
                CLOCKS_PER_SEC;                                         \
        }                                                               \
        if(!vector_isSorted(v, i)) {                                    \
            printf("> Line 54: Array isn't sorted\n");                  \
            v = vector_free(v);                                         \
            exit(1);                                                    \
        }                                                               \
        vector_print(v, sizes[i]);                                      \
        v = vector_free(v);                                             \
    }                                                                   \
    printf("\n> Line 60: Running times saved sucessufully on %s\n",     \
           filename);                                                   \
    save_csv(filename);

void save_csv(char filename[40]);

int main(){
    EXECUTE(bubble, bubble_sort, vector_create, random);
    EXECUTE(bubble, bubble_sort, vector_create_ascending, ascending);
    EXECUTE(bubble, bubble_sort, vector_create_descending, descending);

    EXECUTE(selection, selection_sort, vector_create, random);
    EXECUTE(selection, selection_sort, vector_create_ascending, ascending);
    EXECUTE(selection, selection_sort, vector_create_descending, descending);

    EXECUTE(insertion, insertion_sort, vector_create, random);
    EXECUTE(insertion, insertion_sort, vector_create_ascending, ascending);
    EXECUTE(insertion, insertion_sort, vector_create_descending, descending);

    EXECUTE(shell, shell_sort, vector_create, random);
    EXECUTE(shell, shell_sort, vector_create_ascending, ascending);
    EXECUTE(shell, shell_sort, vector_create_descending, descending);

    EXECUTE(quick, quick_sort, vector_create, random);
    EXECUTE(quick, quick_sort, vector_create_ascending, ascending);
    EXECUTE(quick, quick_sort, vector_create_descending, descending);

    EXECUTE(heap, heap_sort, vector_create, random);
    EXECUTE(heap, heap_sort, vector_create_ascending, ascending);
    EXECUTE(heap, heap_sort, vector_create_descending, descending);

    EXECUTE(merge, merge_sort, vector_create, random);
    EXECUTE(merge, merge_sort, vector_create_ascending, ascending);
    EXECUTE(merge, merge_sort, vector_create_descending, descending);

    return 0;
}

void save_csv(char *filename) {
    FILE *fp = fopen(filename,"w+");

    int i, j;

    printf("\n> Line 105: This content will be write in the file:\n\n");

    for(i = 0; i < SIZES; i++) {
        for(j = 0; j < TESTS; j++) {
            printf("Size: %d\tTest: %d\tTime: %.4f\n", sizes[i], j+1, \
                   runtime[i][j]);
        }
    }

    fprintf(fp,"\nEntrada, Teste 1, Teste 2, Teste 3, Teste 4, Teste 5" \
            ", Teste 6, teste 7, Teste 8, Teste 9, Teste 10\n");

    for(i = 0; i < SIZES; i++) {
        fprintf(fp,"%d, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f, %.4f," \
                "%.4f, %.4f\n", sizes[i], runtime[i][0], runtime[i][1], \
                runtime[i][2], runtime[i][3], runtime[i][4], runtime[i][5], \
                runtime[i][6],runtime[i][7], runtime[i][8], runtime[i][9]);
    }

    fclose(fp);
}
