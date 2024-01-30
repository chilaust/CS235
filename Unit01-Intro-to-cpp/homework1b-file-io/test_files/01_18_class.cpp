//
// Created by Austin Child on 1/18/24.
//

//File Input:
//Read data from a file you must include the input file steam
#include <fstream>
#include <iostream>
int main(int argc, char *argv[])
    std::ifstream inFile;
    inFile.open("myfile.txt");
    //read from file to variable
    inFile >> myVar;


    //Make sure the open worked
    if ( !inFile.is_open() ) {
        exit(1);
    }

    //read the entire file
    while( !infile.eof()) {
        //code to read data
    }


