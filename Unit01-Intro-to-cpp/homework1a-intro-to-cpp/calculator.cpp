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

    int a;
    int b;


//    cin >> operation; ... ask why this does not work
    while (true)
    {
        cout << "operation: ";
        string operation;
        getline(cin, operation);

        if (operation.empty())
        {break;
        }

        if (operation == "add")
        {
            cout << "left operand: ";
            string a;
            getline(cin, a);
            cout << "right operand: ";
            string b;
            getline(cin, b);
            cout << a+b << endl;}

        else if (operation == "subtract")
        {
            cout << "left operand: ";
            string a;
            getline(cin, a);
            cout << "right operand: ";
            string b;
            getline(cin, b);
            cout << a-b << endl;
        }

        else if (operation == "multiply")
        {
            cout << "left operand: ";
            string a;
            getline(cin, a);
            cout << "right operand: ";
            string b;
            getline(cin, b);
            cout << a*b << endl;
        }

        else if (operation == "divide")
        {
            cout << "left operand: ";
            string a;
            getline(cin, a);
            cout << "right operand: ";
            string b;
            getline(cin, b);
            cout << a/b << endl;
        }
//left this original (below)... it says that it reads in a new line character on the next operation so it automatically breaks????
        else if (operation == "mod")
        {
            cout << "left operand: ";
            cin >> a;
            cout << "right operand: ";
            cin >> b;
            cout << a%b << endl;
        }

        else
        {
            cout << operation << " isn't a valid operation" << endl;
        }

    }
            return 0;



    return 0;
}
