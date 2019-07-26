#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    for(int i = 1; i < 65; i++) {
        cout << setw(10) << dec << i << setw(10) << oct << i << setw(10) << hex << i << endl;
    }
    return 0;
}