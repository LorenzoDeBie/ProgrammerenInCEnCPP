#include <iostream>
#include "./../../headers/containers.h"
#include <memory>
using namespace std;

/************ Rechthoek **************/
class Rechthoek {
    public:
        Rechthoek();
        Rechthoek(int, int);
        virtual void print(ostream& out) const;
        int omtrek() const;
        int oppervlakte() const;
    private:
        int breedte;
    protected:
        int hoogte; 
};

Rechthoek::Rechthoek() : Rechthoek(1,1) {}

Rechthoek::Rechthoek(int hoogte, int breedte) : hoogte(hoogte), breedte(breedte) {}

void Rechthoek::print(ostream& out) const {
    out << "Rechthoek " << breedte << " op " << hoogte << endl;
}

int Rechthoek::omtrek() const {
    return 2*hoogte + 2*breedte;
}

int Rechthoek::oppervlakte() const {
    return hoogte*breedte;
}

ostream& operator<<(ostream& out, const Rechthoek& r) {
     r.print(out);
}

/********* Gekleurde Rechthoek ***********/
// afgeleid van Rechthoek; pas aan in hoofding
class GekleurdeRechthoek : public Rechthoek {
    public:
        GekleurdeRechthoek();
        GekleurdeRechthoek(int, int, const string& kleur = "Onbekend");
        void print(ostream& out) const;
    protected:
        string kleur;
   // enkel extra attribuut voor kleur
};

GekleurdeRechthoek::GekleurdeRechthoek() : Rechthoek(), kleur("onbekend") {}

GekleurdeRechthoek::GekleurdeRechthoek(int breedte, int hoogte, const string& kleur) : Rechthoek(breedte, hoogte), kleur(kleur) {}

void GekleurdeRechthoek::print(ostream& out) const {
    Rechthoek::print(out);
    out << "  Kleur: " << kleur << endl;
}

ostream& operator<<(ostream& out, const GekleurdeRechthoek& r) {
    r.print(out);
    return out;
}

/************ Vierkant **************/
// afgeleid van Rechthoek; pas aan in hoofding
class Vierkant : public Rechthoek {
     // geen extra attributen voorzien!
    public:
        Vierkant(int zijde = 1);
        virtual void print(ostream&) const;
};

Vierkant::Vierkant(int zijde) : Rechthoek(zijde, zijde) {}

void Vierkant::print(ostream& out) const {
    out << "Vierkant: zijde " << hoogte << endl;
}

ostream& operator<<(ostream& out, const Vierkant& v){
    v.print(out);
}

// afgeleid van GekleurdRechthoek en Vierkant; pas aan in hoofding
class GekleurdVierkant : public GekleurdeRechthoek, public Vierkant {
    // geen extra attributen voorzien!
    public:
        GekleurdVierkant(int zijde = 1, const string& kleur = "Onbekend");
        void print(ostream& out) const;
};

GekleurdVierkant::GekleurdVierkant(int zijde, const string& kleur) : Vierkant(zijde) {
    this->kleur = kleur;
}

void GekleurdVierkant::print(ostream& out) const {
    Vierkant::print(out);
    out << "  Kleur: " << kleur <<endl;
}

ostream& operator<<(ostream& out, const GekleurdVierkant& v) {
    v.print(out);
    return out;
}

int main () {
   Rechthoek r2(4,6);
   GekleurdeRechthoek gr1;
   GekleurdeRechthoek gr3(6,9, "rood");
   Vierkant v2(10);

   vector<Rechthoek> v;
   v.push_back(move(r2));
   v.push_back(move(gr1));
   v.push_back(move(gr3));
   v.push_back(move(v2));

   for(auto x : v) {
       x.print(cout);
       cout << " oppervlakte: " << x.oppervlakte() << endl
            << " omtrek: " << x.omtrek() << endl;
   }
   return 0;
}