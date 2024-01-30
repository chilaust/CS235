#include <iostream>
#include <string>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

int main(int argc, char const* argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    
    if (a > b)
    {
        //subtract
        while (a % c != 0)
        {
            a -= 1;
        }
        while (a >= b)
        {
            cout << a << endl;
            a -= c;
        }
    }

    else
    {
        //add
        while (a % c != 0)
        {
            a += 1;
        }
        while (a <= b)
        {
            cout << a << endl;
            a += c;
        }
    }

    return 0;
}
