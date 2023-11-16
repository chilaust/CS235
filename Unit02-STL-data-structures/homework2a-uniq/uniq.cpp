#include <iostream>
#include <string>
#include <list>
#include <fstream>




//Write a program in uniq.cpp that reads lines from a text input and outputs unique lines only.
//
//Read lines from a file if a filename is provided as a command-line argument, otherwise read lines from stdin
//Output unique lines in the order they appear in the input
//        Do not output a line more than once

void read_lines(std::istream &input) {
    std::list <std::string> lines;
    std::string indicator = "no";
    std::string line;
    while(std::getline(input, line)){
        for (std::string word: lines) {
            if (word == line) {
                indicator = "yes";
                break;
            }
        }
        if (indicator != "yes") {
            lines.push_back(line);
            std::cout << line << std::endl;
        }
        indicator = "no";
    }
}


int main(int argc, char const* argv[]) {

    std::string input_file;

    if (argc > 1) {
        input_file = argv[1];
        std::ifstream infile(input_file);
        read_lines(infile);
        if (infile.is_open()) {
            infile.close();
        }
    }
    else {
        read_lines(std::cin);
    }

    return 0;
}
