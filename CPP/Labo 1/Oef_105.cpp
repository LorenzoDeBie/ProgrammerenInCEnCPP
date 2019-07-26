#include <iostream>

using namespace std;

struct persoon {
    string naam;
    int leeftijd;
    double lengte;
};

template <typename T>
T grootste(const T[], int);

double grootte(double);
int grootte(const string &);
double grootte(const persoon &);

void initialiseer(persoon &, string, int, double);

void print(const persoon &);

int main() {
    //deelvraag 1
    double getallen[5] = {5.5,7.7,2.2,9.9,9.8};
	string woorden[3] = {"geloof","hoop","de liefde"};		
	cout << grootste(getallen,5) << endl;
	cout << "De grootste van de drie is \"" << grootste(woorden,3) << "\"." << endl;
    //deelvraag 2
    persoon pr[3];
    initialiseer(pr[0], "Samuel", 12, 1.52);
    initialiseer(pr[1], "Jente", 22, 1.81);
    initialiseer(pr[2], "Idris", 42, 1.73);
    //deelvraag 4
    for(int i = 0; i < 3; i++) {
        print(pr[i]);
    }
    //deelvraag 5
    cout << "De oudste: ";
    print(grootste(pr, 3)); //om te sorteren op lengte van een persoon --> alle grootte functies moeten double
    return 0;
}

template <typename T>
T grootste(const T arr[], int n) {
    T g = arr[0]; 
    for(int i = 1; i < n; i++) { //mag hier beginnen bij 1!
        if(grootte(arr[i]) > grootte(g)) {
            g = arr[i];
        }
    }
    return g;
}

double grootte(double n) {
    return n;
}

int grootte(const string &s) {
    return s.size();
}

double grootte(const persoon &p) {
    return p.lengte;
}

void initialiseer(persoon &p, string naam, int leeftijd, double lengte) {
    p.naam = naam;
    p.leeftijd = leeftijd;
    p.lengte = lengte;
}

void print(const persoon &p) {
    cout << p.naam << " is " << p.leeftijd << " jaar oud en " << p.lengte << " meter groot" << endl;
}