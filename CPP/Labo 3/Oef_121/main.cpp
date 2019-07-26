#include "Doos.cpp"
#include "Schijf.cpp"
#include <iostream>

using namespace std;

int main() {
    Schijf<int> schijf;
    Doos<int> doos;
    Doos<int> doos2(doos);
    cout << doos << endl;
    cout << doos2 << endl;
    return 0;
}