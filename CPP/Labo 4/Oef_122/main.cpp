#include <iostream>
#include <string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*********** RECHTHOEK ******************/
class Rechthoek {
	public:
		/*eventueel ook:
		Rechthoek(); */
		Rechthoek(int hoogte = 1, int breedte = 1);
		int omtrek() const;
		int oppervlakte() const;
		void print(ostream& out) const;
		friend ostream& operator<<(ostream& out, const Rechthoek& rechthoek);
	protected:
		int hoogte, breedte;
	/* breedte moet niet protected! want voor vierkant enkel hoogte (of 1 zijde) nodig!
	private:
		int breedte;
	*/
};

/*eventueel ook
Rechthoek::Rechthoek() : Rechthoek(1,1) {}*/

Rechthoek::Rechthoek(int hoogte, int breedte) : hoogte(hoogte), breedte(breedte) {}

Rechthoek::omtrek() const {
	return 2*hoogte + 2*breedte;
}

Rechthoek::oppervlakte() const {
	return breedte*hoogte;
}

void Rechthoek::print(ostream& out) const {
	out << "Rechthoek: " << breedte << " op " << hoogte << endl;
}

ostream& operator<<(ostream& out, const Rechthoek& rechthoek) {
	rechthoek.print(out);
	return out;
}


/********* GekleurdeRechthoek **********/
class GekleurdeRechthoek : public Rechthoek {
	public:
		//GekleurdeRechthoek();
		GekleurdeRechthoek(int hoogte = 1, int breedte = 1, /*const*/string /*&*/kleur = "Onbekend");
		void print(ostream& out) const;
		//geen friend functie nodig aangezien print public is, kan dus gewone externe functie zijn.
		friend ostream& operator<<(ostream& out, const GekleurdeRechthoek& rechthoek);
	protected:
		string kleur;
};

//GekleurdeRechthoek::GekleurdeRechthoek() : Rechthoek(), kleur("onbekend") {}

GekleurdeRechthoek::GekleurdeRechthoek(int hoogte, int breedte, /*const*/string /*&*/kleur) : Rechthoek(hoogte, breedte), kleur(kleur) {}

void GekleurdeRechthoek::print(ostream &out) const {
	Rechthoek::print(out);
	out << "  kleur: " << kleur << endl;
}

ostream& operator<<(ostream& out, const GekleurdeRechthoek& rechthoek) {
	rechthoek.print(out);
	return out;
}



/************* Vierkant ***************/
class Vierkant : public Rechthoek {
	public:
		Vierkant(int zijde = 1);
		void print(ostream &out) const;
		friend ostream& operator<<(ostream& out, const Vierkant vierkant);
};

Vierkant::Vierkant(int zijde) : Rechthoek(zijde, zijde) {}

void Vierkant::print(ostream &out) const {
	out << "Vierkant: zijde " << breedte << endl;
}

ostream& operator<<(ostream& out, const Vierkant vierkant) {
	vierkant.print(out);
}


/************** Gekleurd vierkant *************/
class GekleurdVierkant: public GekleurdeRechthoek, public Vierkant {
	public:
		GekleurdVierkant(int zijde = 1, string kleur = "Onbekend");
		void print(ostream&) const;
		friend ostream& operator<<(ostream& out, const GekleurdVierkant vierkant);
};

GekleurdVierkant::GekleurdVierkant(int zijde, string kleur) : Vierkant(zijde), GekleurdeRechthoek(zijde, zijde, kleur) {}

void GekleurdVierkant::print(ostream& out) const{
	Vierkant::print(out);
	out << "  kleur: " << kleur << endl;
}

ostream& operator<<(ostream& out, const GekleurdVierkant vierkant) {
	vierkant.print(out);
}

int main () {
   Rechthoek r1;
   r1.print(cout);
   cout << "  oppervlakte: " << r1.oppervlakte() << endl
        << "  omtrek: " << r1.omtrek() << endl;
    
   Rechthoek r2(4,6);
   cout << r2;
   cout << "  oppervlakte: " << r2.oppervlakte() << endl
        << "  omtrek: " << r2.omtrek() << endl;
        
   GekleurdeRechthoek gr1;
   gr1.print(cout);
   cout << "  oppervlakte: " << gr1.oppervlakte() << endl
        << "  omtrek: " << gr1.omtrek() << endl;
      
   GekleurdeRechthoek gr2(5,7);
   cout << gr2;
   cout << "  oppervlakte: " << gr2.oppervlakte() << endl
        << "  omtrek: " << gr2.omtrek() << endl;

   GekleurdeRechthoek gr3(6,9,"rood");
   gr3.print(cout);
   cout << "  oppervlakte: " << gr3.oppervlakte() << endl
        << "  omtrek: " << gr3.omtrek() << endl; 

   Vierkant v1;
   cout << v1;
   cout << "  oppervlakte: " << v1.oppervlakte() << endl
        << "  omtrek: " << v1.omtrek() << endl;
        
   Vierkant v2(10);
   v2.print(cout);
   cout << "  oppervlakte: " << v2.oppervlakte() << endl
        << "  omtrek: " << v2.omtrek() << endl; 
		
   GekleurdVierkant gv1;
   cout << gv1;   
   cout << "  oppervlakte: " << gv1.Vierkant::oppervlakte() <<endl
        << "  omtrek: " << gv1.Vierkant::omtrek() << endl;
      
   GekleurdVierkant gv2(12);
   gv2.print(cout);
   cout << "  oppervlakte: " << gv2.Vierkant::oppervlakte() << endl
        << "  omtrek: " << gv2.Vierkant::omtrek() << endl;
	
   GekleurdVierkant gv3(15,"geel");
   cout << gv3;
   cout << "  oppervlakte: " << gv3.Vierkant::oppervlakte() << endl
        << "  omtrek: " << gv3.Vierkant::omtrek() << endl;
   return 0;
   
}
