#include "VectorSet.h"
#include <iostream>


int main() {
    VectorSet<int> s1;

    auto a = s1.insert(1); // Returns true
    auto b = s1.insert(2); // Returns true
    auto c = s1.insert(3); // Returns true
    auto d = s1.insert(3); // Returns false

    auto e = s1.size();// Returns 3

    auto f = s1.contains(1); // Returns true

    auto g = s1.remove(1);

    auto h = s1.size(); // Returns 2
    auto i = s1.empty(); // Returns false
    s1.clear();
    auto j = s1.size(); // Returns 0
    std::cout << a<<std::endl<<b<<std::endl<<c<<std::endl<<d<<std::endl<<e<<std::endl<<f<<std::endl<<g<<std::endl<<h<<std::endl<<i<<std::endl<<j<<std::endl;
}
//
// Created by Austin Child on 11/16/23.
//
