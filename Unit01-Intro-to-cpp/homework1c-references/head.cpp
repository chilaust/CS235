#include <iostream>
#include <string>
#include <fstream>


//Write a head program in head.cpp.
//
//The head program should read the first n lines of either a file or standard input
//If n isn't provided, print 10 lines
//If no file is provided, read the lines from standard input (cin)
//There are four possible scenarios for command-line arguments:
//No arguments: the program should read 10 lines from standard input.
//1 argument that is an input file: the program should attempt to read 10 lines from the file.
//1 argument that is a number of lines n: the program should read that number of lines from standard input.
//-NOTE: Empty lines ("") count as valid input. The program should accept them the same way it accepts non-empty lines.
//2 arguments: the program should read n lines from the file.
//If the input file does not exist, the program should print an error message and exit
//If more lines are requested than the input file has, the program should just print as many lines as the file has and no extras.
//Follow the formatting demonstrated in the example

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
    bool lines = false;
    bool file = false;
    std::string inputFileName;
    if (argc > 1) {

        if (argv[1][0] == '-') { // 1 or 2 inputs and first is number
            numLines = -1 * std::stoi(argv[1]);
            lines = true;
        } else {
            inputFileName = argv[1]; // 1 or 2 inputs input and it is file name
            file = true;
        }
        if (argc > 2) {
            if (lines) { //already found line count
                inputFileName = argv[2];
                file = true;
            } else {
                inputFileName = argv[1];
                file = true;

                if (argv[2][0] == '-') {
                    numLines = -1 * std::stoi(argv[2]);
                    lines = true;
                }
            }
        }
    }

    std::ifstream infile(inputFileName);
    if (!infile.is_open() && file) {
        std::cerr << "ERROR: can't open "  << inputFileName << std::endl;
        exit(1);
    }

    read_lines(inputFileName.empty() ? std::cin : infile, numLines);
    if (infile.is_open()) {
        infile.close();
    }

    return 0;
}


