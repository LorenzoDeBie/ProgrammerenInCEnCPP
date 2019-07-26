#include <iostream>
#include <string>
#include "headers/containers.h"
#include <fstream>
#include <iterator>
#include <list>

int main() {
    string bible = "files/nbible.txt", regelnummers = "files/regelnummers.txt";
    ifstream inv_bible(bible), inv_regelnummers(regelnummers);

    //check if files are found
    if(!inv_regelnummers.is_open()) {
        cout << "Ik kan het regelnummers bestand niet vinden!\n";
        inv_bible.close();
        inv_regelnummers.close();
        return 0;
    }
    if(!inv_bible.is_open()) {
        cout << "Ik kan het bijbelbestand niet vinden!\n";
        inv_bible.close();
        inv_regelnummers.close();
        return 0;
    }


    list<int> volgorde; //link between volgorde and line number
    map<int, string> regelnummer_zin; //link between line number and string
    //loop through the file wiht line numbers
    int regelnummer;
    inv_regelnummers >> regelnummer;
    //I have to check if reading was successfull after every read
    while(!inv_regelnummers.fail()) {
        volgorde.push_back(regelnummer);
        regelnummer_zin.insert(pair<int, string>(regelnummer, ""));
        inv_regelnummers >> regelnummer;
    }
    //check if the whole file was read
    if(!inv_regelnummers.eof()) {
        cout << "Probleem gehad tijdens het lezen van de regelnummers!";
        return 0;
    }

    //read the file with text
    int regel = 1;
    string lijn;
    getline(inv_bible, lijn);
    while(!inv_bible.fail()) {
        if(regelnummer_zin.find(regel) != regelnummer_zin.end()) {
            //ik moet deze regel opslaan
            regelnummer_zin[regelnummer_zin.find(regel)->first] = lijn; //regel opslaan
        }
        getline(inv_bible, lijn);
        regel++;
    }

    //check if the whole file was read
    if(!inv_bible.eof()) {
        cout << "Ik kon niet het volledige bestand lezen!" << endl;
        inv_bible.close();
        inv_regelnummers.close();
        return 0;
    }

    for(int regelnummer : volgorde) {
        cout << regelnummer_zin[regelnummer] << endl;
    }

    inv_bible.close();
    inv_regelnummers.close();
    return 0;
}