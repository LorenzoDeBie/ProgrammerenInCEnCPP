#include <iostream>

using namespace std;

void schrijf(int[], int, bool reverse = false, char tussenteken = ' ');

int main() {
    int t[] = {1, 3, 5, 7, 9, 11, 13};
    schrijf(t, 7);
    schrijf(t, 7, true);
    schrijf(t, 7, false, '-');
    schrijf(t, 7, true, '-');
    return 0;
}

void schrijf(int array[], int n, bool reverse, char tussenteken) {
    int opteller = 1;
    int grens = n;
    int i = 0;
    if(reverse) {
        opteller = -1;
        grens = -1;
        i = n - 1;
    }

    cout << array[i];
    i += opteller;
    for(i; i != grens; i += opteller) {
        cout << tussenteken << array[i];
    }

    cout << endl;
}