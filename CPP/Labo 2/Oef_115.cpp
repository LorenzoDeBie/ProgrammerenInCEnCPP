#include <iostream>
#include <fstream>
#include "headers/containers.h"

using namespace std;

int main() {
    vector<map<char, set<string>>> v1(10);
    ifstream inv1("files/bible_stop.txt");

    if(inv1.is_open()) {
        cout << "Openen gelukt!" << endl;

        string lijn;
        getline(inv1, lijn);
        while(!inv1.fail()) {
            //handle data
            string woord;
            int pos;
            while((pos = lijn.find(" ")) != string::npos) {
                woord = lijn.substr(0, pos);
                //handle the word
                int lengte = woord.size(); char eerste = woord[0];
                if(v1.size() <= lengte) {
                    v1.resize(lengte + 1);
                }
                v1[lengte][eerste].insert(woord);
                lijn.erase(0, pos + 1);
            }
            getline(inv1, lijn);
        }
        if(inv1.eof()) {
            cout << "Volledig bestand gelezen!" << endl;
        } else {
            cout << "Foute data in het bestand!!" << endl;
        }

        cout << "output:" << endl;

        string zoekwoord = "sinterklaas";
        cout << v1[zoekwoord.size()][zoekwoord[0]];
    }
    else {
        cout << "Openen niet gelukt!!!";
    }


    return 0;
}