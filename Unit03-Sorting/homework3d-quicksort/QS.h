#pragma once

#include <vector>

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    // implement medianOfThree here
    int median = (left + right)/2;
    std::vector<int> index;
    index.push_back(left);
    index.push_back(median);
    index.push_back(right);

    std::vector<int> values;
    values.push_back(array[left]);
    values.push_back(array[median]);
    values.push_back(array[right]);
    if (values[0] > values[1]) {
        std::swap(values[0], values[1]);
        std::swap(index[0], index[1]);
    }
    if (values[0] > values[2]) {
        std::swap(values[0], values[2]);
        std::swap(index[0], index[2]);
    }
    if (values[1] > values[2]) {
        std::swap(values[1], values[2]);
        std::swap(index[1], index[2]);
    }
    return index[1];
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    // implement partition here
}

template<class T>
void sort(std::vector<T>& array) {
    // implement sort here
    // hint: you'll probably want to make a recursive sort_helper function
}


