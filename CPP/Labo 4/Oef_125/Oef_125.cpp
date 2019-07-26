#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

class Persoon{
    public:
       string voornaam;
       string naam;
       int leeftijd;
       Persoon(const string & v, const string & n, int l):voornaam(v),naam(n),leeftijd(l){}
};	

ostream& operator<<(ostream & out, const Persoon & p){
    out<<p.naam <<" "<<p.voornaam<<" ("<<p.leeftijd<<")";
    return out;
}


class Groep : public vector<Persoon>{
    public:
        // Hier komt de declaratie van de lidfunctie 'geef_extremum',
        // die een Persoon teruggeeft.
        // Deze lidfunctie krijgt als parameter een functie mee die twee 
        // objecten van de klasse Persoon vergelijkt.
        Persoon& geef_extremum(function<bool (const Persoon&, const Persoon&)> func) {
            int index_beste = 0;
            for(int i = 1; i < size(); i++) {
                index_beste = func((*this)[index_beste], (*this)[i]) ? index_beste : i; 
            }
            return (*this)[index_beste];
        }
};

int main(){
    Groep gr;
    gr.push_back(Persoon("Ann","Nelissen",12));
    gr.push_back(Persoon("Bert","Mertens",22));
    gr.push_back(Persoon("Celle","Lauwers",55));
	
    cout<<"Eerste qua naam:     " << gr.geef_extremum([](const Persoon& pers1, const Persoon& pers2) -> bool {
        return pers1.naam > pers2.naam;
    }) << endl;	
    cout<<"Eerste qua voornaam: " << gr.geef_extremum([](const Persoon& pers1, const Persoon& pers2)->bool{
        return pers1.voornaam > pers2.voornaam;
    } ) << endl;
    cout<<"Jongste:             " << gr.geef_extremum([](const Persoon& pers1, const Persoon& pers2)->bool{
        return pers1.leeftijd < pers2.leeftijd;
    } ) << endl;
    cout<<"Oudste:              " << gr.geef_extremum([](const Persoon& pers1, const Persoon& pers2)->bool{
        return pers1.leeftijd > pers2.leeftijd;
    } ) << endl;
    return 0;	
}