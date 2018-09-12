#include "Sort.h"

bool Sort::isSorted(void * base, size_t nmemb, size_t size, int (*compare)(const void *, const void *)) {
    
    void * ele1;
    void * ele2;

    for(size_t i = 0; i < nmemb - 1; i++) {

        ele1 = (void*) ((char*) base + i * size);
        ele2 = (void*) ((char*) base + (i + 1) * size);

        if((*compare)(ele1, ele2) > 0) {
            return false;
        }
    }
    return true;
}

void Sort::BogoSort(void * base, size_t nmemb, size_t size, int (*compare)(const void *, const void *)) {

    void * ele1;
    void * ele2;

    if(isSorted(base, nmemb, size, compare)) {
        return;
    }

    char * temp = new char[size];

    while(true) {

        for(size_t i = 0; i < nmemb; i++) {

            ele1 = (void*) ((char*) base + i * size);
            ele2 = (void*) ((char*) base + (rand() % nmemb) * size);

                memcpy(temp, ele1, size);
                memcpy(ele1, ele2, size);               
                memcpy(ele2, temp, size);

        }

        if(isSorted(base, nmemb, size, compare)) {
            break;
        }          
    }
    delete[] temp;
}

void Sort::BubbleSort(void * base, size_t nmemb, size_t size, int (*compare)(const void *, const void *)) {

    void * ele1;
    void * ele2;
    char * temp = new char[size];
    bool swapped = true;

    for(size_t i = 0; i < nmemb - 1; i++) {
        for(size_t j = 0; j < nmemb - i - 1; j++) {

            ele1 = (void*) ((char*) base + j * size);
            ele2 = (void*) ((char*) base + (j + 1) * size);

            if((*compare)(ele1, ele2) > 0) {
                swapped = true;
                memcpy(temp, ele1, size);
                memcpy(ele1, ele2, size);               
                memcpy(ele2, temp, size);
            }
        }
        if(!swapped) {
            return;
        }
        swapped = false;
    }
    delete[] temp;
}

void Sort::InsertionSort(void * base, size_t nmemb, size_t size, int (*compare)(const void *, const void *)) {

    void * ele1;
    void * ele2; 
    char * temp = new char[size];

    for(size_t i = 0; i < nmemb; i++) {
        for(size_t j = i; j > 0; j--) {
            ele1 = (void*) ((char*) base + j * size);
            ele2 = (void*) ((char*) base + (j - 1) * size);

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

    void * ele1;
    void * ele2; 
    char * temp = new char[size];

    for(size_t i = 0; i < nmemb - 1; i++) {
        for(size_t j = i + 1; j < nmemb; j++) {
            ele1 = (void*) ((char*) base + i * size);
            ele2 = (void*) ((char*) base + j * size);

            if((*compare)(ele1, ele2) > 0) {
                memcpy(temp, ele1, size);
                memcpy(ele1, ele2, size);
                memcpy(ele2, temp, size);
            }
        }
    }
    delete[] temp;
}