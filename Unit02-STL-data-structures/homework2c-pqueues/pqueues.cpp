#include <string>
using std::string, std::getline, std::stoi, std::stod;

#include <sstream>
using std::stringstream;

#include <iostream>
using std::cout, std::cin, std::cerr, std::endl;

#include <stack>
using std::stack;

#include <queue>

#include <iomanip>

#include "input.h"

#include <functional>

std::string input(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}

std::string pad_priority (int number) {
    std::ostringstream padded;
    padded << std::setw(2) <<std::setfill('0') << number;
    return padded.str();
}

int main(int argc, char const* argv[]) {
    // create que:
    std::priority_queue<std::string, std::vector<std::string>, std::less<std::string> > people;


    // start a loop so that it asks What do you want to do?

    while (true){
        string operation = input("What do you want to do? ");
        if (operation == "") {
            break;
        }

        if (operation == "add") {
            string name = input("Name: ");
            string priority = pad_priority(stoi(input("Priority: ")));
            //add name and priority to que...
            people.push(priority + " - " + name);

        }

        else if (operation == "take") {
            if (people.size() == 0) {
                cout << "There are no more people in line" << endl;
            }
            else {
                cout << people.top() << std::endl;
                people.pop();
            }
        }
        else {
            cout << operation << " isn't a valid operation" << endl;
        }

    }

    return 0;
}
