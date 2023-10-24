#include <iostream>
using std::cout, std::cerr, std::endl;

#include <fstream>
using std::ifstream, std::ofstream;

#include <string>
using std::string, std::getline;

#include <sstream>
using std::istringstream;


int main(int argc, char const* argv[]) {
    // First arg is input file, second arg is output file,
    if (argc < 3) {
        cerr << "This program needs an input file, and output file!" << endl;
        exit(1);
    }

    ifstream infile(argv[1]);
    if (!infile.is_open()) {
        cerr << "Unable to open file for reading: " << argv[1] << endl;
        exit(2);
    }

    ofstream outfile(argv[2]);
    if (!outfile.is_open()) {
        cerr << "Unable to open file for writing: " << argv[2] << endl;
        exit(3);
    }

    string line;
    while (getline(infile, line)) {
        // Process each line here
        istringstream iss(line);
        string word;
        string first;
        string last;
        float points = 1;
        int count = 0;

        while (iss >> word) {
            if (count >= 2) {
                points *= stof(word);
            }
            else if (count == 0) {
                first = word + ": ";
            }
            else {
                last = word + ", ";
            }
            count ++;
        }
        outfile << last << first << points << endl;

    }


    infile.close();
    outfile.close();

    return 0;
}
