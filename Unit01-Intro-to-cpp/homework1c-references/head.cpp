#include <iostream>
#include <string>
#include <fstream>


void read_lines(std::istream &input, int n) {
    std::string line;
    int count = 0;

    while (std::getline(input, line) && count < n) {
        std::cout << line <<std::endl;
        count++;
    }
}

int main(int argc, char const* argv[]) {
    int numLines = 10;
    int value = 1;
    std::string inputFileName;
    if (argc > 1 && argv[1][0] == '-') { // 1 or 2 inputs and first is number
        numLines = -1 * std::stoi(argv[1]);
        value = 0;
    } else {
        inputFileName = argv[1]; // 1 or 2 inputs input and it is file name
    }
    if (argc > 2) {
        if (value == 0) { //already found line count
            inputFileName = argv[2];
        } else {
            inputFileName = argv[1];
            if (argv[2][0] == '-') {
                numLines = -1 * std::stoi(argv[2]);
            }
        }
    }

    std::ifstream infile(inputFileName);
    if (!infile.is_open()) {
        std::cerr << "ERROR: can't open " << inputFileName << std::endl;
        exit(1);
    }

    read_lines(inputFileName.empty() ? std::cin : infile, numLines);
    if (infile.is_open()) {
        infile.close();
    }

    return 0;
}


