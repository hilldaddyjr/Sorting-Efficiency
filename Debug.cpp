#include "Debug.h"
#include <cstdio>
#include <iostream>

#define stdlength 12
int main() {

    int array [stdlength];

    for(int i = 0; i < stdlength; i++) {
        array[i] = rand() % 10;
    }

    for(int i = 0; i < stdlength; i++) {
        std::cout << array[i] <<  ", ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Before Sorting:";
    std::cout << Sort::isSorted(&array, stdlength, sizeof(int), Debug::compare) << std::endl;

    //Sorting Function here
    Sort::BogoSort(&array, stdlength, sizeof(int), Debug::compare);
   
    std::cout << "After Sorting:";
    std::cout << Sort::isSorted(&array, stdlength, sizeof(int), Debug::compare) << std::endl;
    std::cout << std::endl;

    for(int i = 0; i < stdlength; i++) {
        std::cout << array[i] <<  ", ";
    }
    std::cout << std::endl;

    int x;
    std::cin >> x;

}

int Debug::compare(const void * x, const void * y) {
    //std::cout << *(const int *) x - *(const int *) y;
    return *(const int *) x - *(const int *) y;
}