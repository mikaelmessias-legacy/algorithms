/****************************************************************************
 * Copyright 2018 Mikael Messias <mikaelmessias@outlook.com>
 *
 * You can do whatever you want with this code, as long as you include the
 * original copyright and license notice in any copy of the software/source.
 * Furthermore, please read the LICENSE file for more information.
 ***************************************************************************/

#include <stdio.h>
#include "sort.h"

static void heap_siftDown(Type *v, int start, int end) {
    int root = start;

    while((root * 2 + 1) <= end) {
        // Points to the left child
        int child = root * 2 + 1;

        // If the child has a sibling and the child's value is less than
        // its sibling's, then point to the right child.
        if((child + 1) <= end && v[child] < v[child + 1]) {
            child += 1;
        }

        // Out of max-heap order.
        if(v[root] < v[child]) {
            vector_swap(v, root, child);

            // Repeat to continue sift down the child now.
            root = child;
        }
        else {
            return;
        }
    }
}

static void heapify(Type *v, int n) {
    // The last parent node.
    int start = (n - 2) / 2;

    // Sift down the node at index start to the proper place such that all
    // nodes below the start index are in heap order.
    while(start >= 0) {
        heap_siftDown(v, start, n - 1);
        start -= 1;
    }
}

void heap_sort(Type *v, int n) {
    // First place a in max-heap order
    heapify(v, n);

    int end = n - 1;

    while(end > 0) {
        // Swap the maximum value of the heap with the last element.
        vector_swap(v, end, 0);

        // Decrements the size of the heap so that the previous max value
        // will stay in its proper place.
        end -= 1;

        // Put the heap back in max-heap order.
        heap_siftDown(v, 0, end);
    }
}
