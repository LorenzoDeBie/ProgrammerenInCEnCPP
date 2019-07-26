#include <memory>
#include <iostream>
using namespace std;

void schrijf(const unique_ptr<string>[], int);
void verwijder(unique_ptr<string>[], int, int);

int main(){
    unique_ptr<string> pnamen[]={make_unique<string>("Rein"), make_unique<string>("Ada"),
        make_unique<string>("Eppo"), make_unique<string>("Pascal"),
        make_unique<string>("Ilse")}; //vul zelf deze array aan met 5 unieke pointers
    
    schrijf(pnamen,5);
    verwijder(pnamen,5,5);
    cout << "Ik heb verwijderd" << endl;
    schrijf(pnamen,5);
	
    return 0;
}

void schrijf(const unique_ptr<string> pnamen[], int aantal) {
    for(int i = 0; i < aantal && pnamen[i] != nullptr; i++) {
        cout << *(pnamen[i]) << endl;
    }
}

void verwijder(unique_ptr<string> pnamen[], int aantal, int volgnummer) {
    //VERBETERING: Niet gecheckt of volgnummer == aantal --> dan moet ik reset() gebruiken!
    if(volgnummer < aantal) {
        for(int i = volgnummer - 1; i < aantal - 1; i++) {
            pnamen[i] = move(pnamen[i+1]);
        }
    }
    else if(volgnummer == aantal) {
        pnamen[aantal-1].reset();
    }
    
}