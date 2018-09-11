#include "Sort.h"

void Sort::InsertionSort(void * base, size_t nmemb, size_t size, int (*compare)(const void *, const void *)) {

char * temp = new char[size];

    for(size_t i = 0; i < nmemb; i++) {
        for(size_t j = i; j > 0; j--) {
            void * ele1 = (void*) ((char*) base + j * size);
            void * ele2 = (void*) ((char*) base + (j - 1) * size);

            if((*compare)(ele1, ele2) < 0) {
                memcpy(temp, ele1, size);
                memcpy(ele1, ele2, size);
                memcpy(ele2, temp, size);
            }
        }
    }
    delete[] temp;
}

void Sort::SelectionSort(void * base, size_t nmemb, size_t size, int (*compare)(const void *, const void *)) {

    char * temp = new char[size];

    for(size_t i = 0; i < nmemb - 1; i++) {
        for(size_t j = i + 1; j < nmemb; j++) {
            void * ele1 = (void*) ((char*) base + i * size);
            void * ele2 = (void*) ((char*) base + j * size);

            if((*compare)(ele1, ele2) >= 0) {
                memcpy(temp, ele1, size);
                memcpy(ele1, ele2, size);
                memcpy(ele2, temp, size);
            }
        }
    }
    delete[] temp;
}