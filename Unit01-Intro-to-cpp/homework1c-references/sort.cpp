#include <iostream>
#include <string>


void sort(std::string& a, std::string& b, std::string& c) {
    // implement sort here
    std::string A = a;
    std::string B = b;
    std::string C = c;
    int Al = A.length();
    int Bl = B.length();
    int Cl = C.length();

    if (a > b) {
        std::swap(a, b);
    }
    if (a > c) {
        std::swap(a, c);
    }
    if (b > c) {
        std::swap(b, c);
    }

//    if (Al>Bl){
//        if (Al>Cl) {
//            a = A;
//            if (Bl > Cl) {
//                b = B;
//                c = C;
//            }
//            else {
//                b = C;
//                c = B;
//            }
//        }
//        else {
//            a=C;
//            b=A;
//            c=B;
//        }
//    }
//    else if (Bl>Cl){
//        a=B;
//        if (Al>Cl){
//            b=A;
//            c=C;
//        }
//        else{
//            b=C;
//            c=A;
//        }
//
//    }
//    else{
//        a=C;
//        b=B;
//        c=A;
//    }
}

int main(int argc, char const* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " a b c" << std::endl;
        return 1;
    }

    std::string a = argv[1];
    std::string b = argv[2];
    std::string c = argv[3];

    sort(a, b, c);

    std::cout << a << ' ' << b << ' ' << c << std::endl;

    return 0;
}