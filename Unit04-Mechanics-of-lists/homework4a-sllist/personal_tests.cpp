#include <cstring>
#include <initializer_list>
#include <iostream>
#include <string>
#include "SLList.h"

int main()
{
    SLList<int> list;
    std::cout << "Size should be 0: " << list.size() << std::endl;
    list.push_back(7);
    list.push_back(8);
    std::cout << "Size should be 2: " << list.size() << std::endl;
    list.clear();
    std::cout << "Size should be 0: " << list.size() << std::endl;

    list.push_back(10);
    list.push_back(100);
    list.push_back(1000);
    std::cout << list.front() << std::endl;

    list.pop_back();
    std::cout << list.size() << std::endl;
    list.clear();
    std::cout << list.size() << std::endl;

    std::cout << "done" << std::endl;
}