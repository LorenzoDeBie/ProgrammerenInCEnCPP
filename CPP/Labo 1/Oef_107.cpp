#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ifstream inv;
    inv.open("files/lord.txt", ios::in);
    if(inv.is_open()) {
        cout << "Openen gelukt" << endl;
    }
    else cout << "Openen mislukt" << endl;
    
    int frequentieTabel[26] = {0};
    char c = inv.get();

    while(!inv.fail()) {
        if(c <= 'z' && c >= 'a') {
            frequentieTabel[c-'a']++;
        }
        c = inv.get();
    }

    if(inv.eof()) {
        for(int i = 0; i < sizeof(frequentieTabel)/sizeof(frequentieTabel[0]); i++) {
            cout << (char)('a' + i) << " ";
        }
        cout << endl;
        for(int i = 0; i < sizeof(frequentieTabel)/sizeof(frequentieTabel[0]); i++) {
            cout << frequentieTabel[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Bestand bevat foute data!" << endl;
    }

    return 0;
}