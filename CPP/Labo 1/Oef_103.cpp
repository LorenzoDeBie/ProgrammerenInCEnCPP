#include <string>
#include <iostream>

using namespace std;

int main() {
    char c = 'x';
    string s = "" + c; //zal niet lukken want optellen van c-string en char, en geen constructor
    cout << "karakter " << c << " omgezet: " << s << "." << endl;

    char k = 'y';
    string w = ""; //vanaf nu kan ik het wel aanpassen want constructor is opgeroepen
    w += k;
    cout << "karakter " << k << " omgezet: " << w << "." << endl;
    return 0;
}