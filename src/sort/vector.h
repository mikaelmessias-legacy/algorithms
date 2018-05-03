/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

typedef int Type;


/**
 ** VECTOR
 */

/**
 * @brief Create a vector and generate random values to be stored inside it.
 * @param n The size of the vector.
 * @return A vector allocated with n random values.
 */
Type* vector_create(int n);

/**
 * @brief Print the vector formatted.
 * @param v The vector.
 * @param n The size of the vector.
 */
void vector_print(Type *v, int n);

/**
 * @brief Check if the vector is sorted.
 * @param v The vector.
 * @param n The size of the vector.
 * @return The value 0 if sorted or 1 if not sorted.
 */
int vector_isSorted(Type *v, int n);

/**
 * @brief Swap two elements from a vector.
 * @param v The vector.
 * @param a The first element position.
 * @param b The second element position.
 **/
void vector_swap(Type *v, int a, int b);


/**
 * @brief Free the vector from memory.
 * @param v The vector.
 * @return Null element.
 */
Type* vector_free(Type *v);

#endif /* VECTOR_H */
