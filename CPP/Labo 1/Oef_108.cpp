#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    ifstream *inv = new ifstream[argc - 1]; //create ifstream for every file in params
    for(int i = 0; i < argc - 1; i++) { 
        inv[i].open(argv[i+1], ios::in); //initialize every ifstream
    }

    ofstream uitv("files/uit.txt", ios::out); //create an output file

    int i = 0;
    bool stoppen = false;

    while(!stoppen) {
        string s = ""; //line to put in uit.txt
        getline(inv[i % (argc - 1)], s);//read line to store
        uitv << s;//write line to uit.txt
        string h = "";//hulp
        for(int n = i + 1; n < (argc - 1 + i) && !stoppen; n++) {//loop through all the other files
            if(inv[n % (argc - 1)].fail()) { // check if they have ended
                stoppen = true;// file has ended
            }
            else {
                getline(inv[n % (argc - 1)], h); //go to next line        
            }
        }
        i++;//next ifstream
    }

    //check if we stopped because of eof or because of an error
    for(int i = 0; i < argc - 1; i++) { 
            if(!inv[i].eof()) {
                cout << "Something has gone wrong..." << endl;
                return 0;
            }
    }

    //a file has ended
    cout << "A file has ended." << endl;

    for(int i = 0; i < argc - 1; i++) { 
            inv[i].close(); //close every ifstream
    }

    uitv.close(); //close output file

    delete[] inv;

    return 0;
}