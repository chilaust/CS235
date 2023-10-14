#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

#include <string>
using std::string;

/*
 * You can assume the user always provides valid inputs
e.g. the test will not enter lizard when the program expects a number
You won't be asked to divide or mod by zero
Support add, subtract, multiply, divide, and mod (modulus) operations
Each of these operations takes a left operand and right operand
The program should exit when given an empty operation
Follow the formatting demonstrated in the example
Example

operation: add
left operand: 1
right operand: 2
3
operation: add
left operand: 5
right operand: -7
-2
operation: asdf
asdf isn't a valid operation
operation:
 */

std::string input(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}

int main(int argc, char const* argv[]) {




    string operation = input("operation: ");
    while (!operation.empty())
    {




        if (operation == "add")
        {
            int left = stoi(input("left operand: "));
            int right = stoi(input("right operand: "));
            cout << left+right << endl;
        }

        else if (operation == "subtract")
        {
            int left = stoi(input("left operand: "));
            int right = stoi(input("right operand: "));
            cout << left-right << endl;
        }

        else if (operation == "multiply")
        {
            int left = stoi(input("left operand: "));
            int right = stoi(input("right operand: "));
            cout << left*right << endl;
        }

        else if (operation == "divide")
        {
            int left = stoi(input("left operand: "));
            int right = stoi(input("right operand: "));
            cout << left/right << endl;
        }

        else if (operation == "mod")
        {
            int left = stoi(input("left operand: "));
            int right = stoi(input("right operand: "));
            cout << left%right << endl;
        }

        else
        {
            cout << operation << " isn't a valid operation" << endl;
        }
        operation = input("operation: ");


    }
            return 0;



    return 0;
}
