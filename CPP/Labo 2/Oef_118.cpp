#include <iostream>
#include "headers/containers.h"

int main() {
    
    set<string> woorden;
    woorden.insert("awoordnul");
    woorden.insert("bwoordeen");
    woorden.insert("cwoordtwee");
    woorden.insert("dwoorddrie");
    woorden.insert("ewoordvier");
    woorden.insert("fwoordvijf");

    cout << woorden << endl;

    set<string>::iterator sit = woorden.begin();
    int i = 0;
    while(sit != woorden.end()) {
        if(!(i % 2)) {
            sit = woorden.erase(sit); //we mogen deze return niet gebruiken??
            //woorden.erase(sit); //segfault
        }
        sit++; i++;
    }

    cout << woorden << endl;

    return 0;
}