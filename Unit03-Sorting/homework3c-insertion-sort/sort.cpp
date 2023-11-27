#include <iostream>
#include <string>
#include <fstream>
#include <vector>


int main(int argc, char const* argv[]) {
    std::vector <std::string> list;

    if (argc > 1) {
        std::ifstream input_file(argv[1]);
        if (!input_file.is_open()) {
            std::cerr << "Unable to open the file: " << argv[1] << std::endl;
            return 1;
        }
        std::string line;
        while (std::getline(input_file, line)) {
        list.push_back(line);
        }
    }
    else {
        std::string line;
        while (std::getline(std::cin, line)) {
            list.push_back(line);
        }
    }


    int length = list.size();


    //search algorithm
    int loop = 1;

    while (loop < length) {
        int next_pos = loop;
        std::string next_val = list[next_pos];
        while (next_pos > 0 && next_val < list[next_pos - 1]) {
            list[next_pos] = list[next_pos - 1];
            next_pos = next_pos - 1;
        }
        list[next_pos] = next_val;
        loop++;
    }

    for (const auto &element : list) {
        std::cout << element << std::endl;
    }
}