#include <iostream>
using std::cout, std::cerr, std::endl;

#include <fstream>
using std::ifstream, std::ofstream;

#include <string>
using std::string, std::getline;

#include <sstream>
using std::istringstream;

int test_files(int argc, char const* argv[]) {
    // First arg is input file, second arg is output file,
    if (argc < 2) {
        cerr << "This program needs an input file!" << endl;
        exit(1);
    }

    ifstream infile(argv[1]);
    if (!infile.is_open()) {
        cerr << "Unable to open file for reading: " << argv[1] << endl;
        exit(2);
    }
    return 0;
}

int main(int argc, char const* argv[]) {

    test_files(argc, argv);

    ifstream infile(argv[1]);

    string line;
    string winner;
    int length = 0;
    while (getline(infile, line)) {
        istringstream iss(line);
        string word;
        int count = 0;
//        cout << line;
//        cout << iss;

        while (iss >> word) {
            count ++;
//            cout << count << "--count loop 1--" << endl;
        }

        if (count > length) {
            winner = line;
            length = count;
//            cout << winner << "--winner--" << endl;
//            cout << length << "--length loop 2--" << endl;
        }

    }

    cout << winner << endl;

    infile.close();
    return 0;
}
