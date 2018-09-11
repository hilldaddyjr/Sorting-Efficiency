#ifndef SORT_H
#define SORT_H

#include <cstdio>
#include <algorithm>

namespace Sort {
   
    void InsertionSort(void * base, size_t nmemb, size_t size, int (*compare)(const void *, const void *));

    void SelectionSort(void * base, size_t nmemb, size_t size, int (*compare)(const void *, const void *));
};

#endif