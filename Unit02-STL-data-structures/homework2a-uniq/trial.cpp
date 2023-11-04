#include <iostream>
#include <string>
#include <set>

int main() {
    std::set<std::string> uniqueLines;
    std::string line;

    // Read lines from stdin
    while (std::getline(std::cin, line)) {
        uniqueLines.insert(line);
    }

    // Output unique lines in the order they appear
    for (const std::string& uniqueLine : uniqueLines) {
        std::cout << uniqueLine << std::endl;
    }

    return 0;
}
//
// Created by Austin Child on 11/4/23.
//
