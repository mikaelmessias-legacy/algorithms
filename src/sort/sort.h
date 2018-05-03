/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#ifndef SORT_H
#define SORT_H

#include "vector.h"

/**
 ** SORT ALGORITHMS
 */

/**
 * @brief Sort a vector with the Bubble Sort algorithm.
 * @param v The vector to be sorted.
 * @param n The size of the vector.
 */
void bubble_sort(Type *v, int n);

/**
 * @brief Sort a vector with the Selection Sort algorithm.
 * @param v The vector to be sorted.
 * @param n The size of the vector.
 */
void selection_sort(Type *v, int n);

/**
 * @brief Sort a vector with the Insertion Sort algorithm.
 * @param v The vector to be sorted.
 * @param n The size of the vector.
 */
void insertion_sort(Type *v, int n);

/**
 * @brief Sort a vector with the Shell Sort algorithm.
 * @param v The vector to be sorted.
 * @param n The size of the vector.
 */
void shell_sort(Type *v, int n);

/**
 * @brief Sort a vector with the Quick Sort algorithm.
 * @param v The vector to be sorted.
 * @param n The size of the vector.
 */
void quick_sort(Type *v, int n);

/**
 * @brief Sort a vector with the Heap Sort algorithm.
 * @param v The vector to be sorted.
 * @param n The size of the vector.
 */
void heap_sort(Type *v, int n);

/**
 * @brief Sort a vector with the Merge Sort algorithm.
 * @param v The vector to be sorted.
 * @param n The size of the vector.
 */
void merge_sort(Type *v, int n);

#endif /* SORT_H */
