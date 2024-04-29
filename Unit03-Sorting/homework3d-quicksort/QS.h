#pragma once

#include <vector>

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    // implement medianOfThree here
    int median = (left + right) / 2;

    if(array[left] > array[right]){
        std::swap(array[left],array[right]);
    }

    if(array[left] > array[median]){
        std::swap(array[left],array[median]);
    }

    if(array[median] > array[right]){
        std::swap(array[median],array[right]);
    }

    return median;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    int pivotIndex = medianOfThree(array, left, right);

    std::swap (array[left],array[pivotIndex]);
    int up = left + 1;
    int down = right;

    do {
        while ((array[up] <= array[left]) && (up < right)) {
            up++;
        }
        while ((array[down] > array[left]) && (down > left)) {
            down--;
        }
        if (up < down) {
            std::swap(array[up], array[down]);
        }
    } while (up < down);

    std::swap(array[left],array[down]);

    return down;
}

template<class T>
void helper(std::vector<T>& array, int left, int right) {
    if (right - left >= 1) {
        int pivotIndex = partition(array, left, right);
        helper(array, left, pivotIndex - 1);
        helper(array, pivotIndex + 1, right);
    }
}

template<class T>
void sort(std::vector<T>& array) {
    int left = 0;
    int right = array.size() - 1;
    helper(array, left, right);
}