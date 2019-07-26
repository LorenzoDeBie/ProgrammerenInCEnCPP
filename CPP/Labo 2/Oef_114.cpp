#include "headers/containers.h"

int main() {
    map<char, set<string>> m1;
    set<string> s1;

    string input = "";
    cout << "Geef woorden in, eindig met STOP: ";
    getline(cin, input);
    while(input != "STOP") {
        if(input.find(" ") == string::npos) {
            //correcte input
            s1.insert(input);
            cout << "Volgende woord: ";
        }
        else {
            cout << "U gaf een zin in ipv een woord! Probeer opnieuw: ";
        }
        getline(cin, input);
    }
    cout << "Welke letter wilt u associeren met deze set van woorden?\n";
    char c;
    cin >> c; m1[c] = s1;

    int aantal = 0;
    for(string s : m1[c]) {
        if(s[0] == c) {
            aantal++;
        }
    }

    cout << aantal << " woorden beginnen met de letter " << c << endl;

    return 0;
}