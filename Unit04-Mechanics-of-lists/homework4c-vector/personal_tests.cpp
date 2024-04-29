#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Vector.h"
template<class T>
void print(const Vector<T>& vector) {
    for (int i = 0; i < vector.size(); i++){
        std::cout << vector.operator[](i) << ", ";
    }
}
int main () {
    std::cout << "--- Test 1 output ---\n" << std::endl;

    Vector<std::size_t> vector;

    vector.push_back(1);
    vector.push_back(2);
    print(vector);
    std::cout << std::endl;

    vector.push_back(3);
    vector.push_back(4);
    print(vector);
    std::cout << std::endl;

    vector.push_back(5);
    vector.push_back(6);
    print(vector);
    std::cout << std::endl;
};