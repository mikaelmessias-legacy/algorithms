/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#ifndef SORT_H
#define SORT_H

/**
 * @brief Sort an vector with the Bubble Sort algorithm.
 * @param v[] The vector to be sorted.
 * @param n The size of the vector.
 */
void bubble_sort(int v[], int n);

/**
 * @brief Sort an vector with the Selection Sort algorithm.
 * @param v[] The vector to be sorted.
 * @param n The size of the vector.
 */
void selection_sort(int v[], int n);

/**
 * @brief Sort an vector with the Insertion Sort algorithm.
 * @param v[] The vector to be sorted.
 * @param n The size of the vector.
 */
void insertion_sort(int v[], int n);

/**
 * @brief Sort an vector with the Shell Sort algorithm.
 * @param v[] The vector to be sorted.
 * @param n The size of the vector.
 */
void shell_sort(int v[], int n);

/**
 * @brief Sort an vector with the Quick Sort algorithm.
 * @param v[] The vector to be sorted.
 * @param n The size of the vector.
 */
void quick_sort(int v[], int n);

/**
 * @brief Sort an vector with the Heap Sort algorithm.
 * @param v[] The vector to be sorted.
 * @param n The size of the vector.
 */
void heap_sort(int v[], int n);

/**
 * @brief Sort an vector with the Merge Sort algorithm.
 * @param v[] The vector to be sorted.
 * @param n The size of the vector.
 */
void merge_sort(int v[], int n);


#endif /* SORT_H */
