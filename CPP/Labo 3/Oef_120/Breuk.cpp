#include <iostream>
#include <string>
#include <sstream>

int mijn_ggd(int, int);

class Breuk {
    public:
        Breuk(int, int);
        int getTeller() const;
        int getNoemer() const;
        Breuk operator+(const Breuk breuk) const;
        Breuk operator+(int getal) const;
        Breuk operator-() const;
        Breuk operator-(const Breuk breuk) const;
        Breuk& operator+=(const Breuk breuk);
        Breuk& operator-=(const Breuk breuk);
        Breuk& operator++();
        Breuk operator++(int);
        bool operator<(const Breuk) const;
        bool operator>(const Breuk) const;
        bool operator==(const Breuk breuk) const;
        bool operator!=(const Breuk breuk) const; 
        friend std::ostream& operator<<(std::ostream &out, const Breuk &breuk);
        friend std::istream& operator>>(std::istream &in, Breuk &breuk);
    private:
        int teller;
        int noemer;
        void herbereken();

};

void Breuk::herbereken() {
    int gemeenschappelijke_deler = mijn_ggd(teller, noemer);
    teller = teller / gemeenschappelijke_deler;
    noemer = noemer / gemeenschappelijke_deler;
}

Breuk::Breuk(int teller = 1, int noemer = 1) {
    if(noemer < 0) {
        this->teller = (teller * -1);
        this->noemer = (noemer * -1);
    }
    else {
        this->teller = teller;
        this->noemer = noemer;
    }
}

Breuk Breuk::operator+(const Breuk breuk) const {
    int gemeenschappelijke_noemer = noemer*breuk.noemer;
    int som_teller = teller*breuk.noemer+breuk.teller*noemer;
    int gemeenschappelijke_deler = mijn_ggd(gemeenschappelijke_noemer, som_teller);
    int teller = som_teller/gemeenschappelijke_deler;
    int noemer = gemeenschappelijke_noemer/gemeenschappelijke_deler;
    return Breuk(teller, noemer);
}

Breuk Breuk::operator+(int getal) const {
    return operator+(Breuk(getal));
}

Breuk Breuk::operator-() const {
    return Breuk(-teller, noemer);
}

Breuk Breuk::operator-(const Breuk breuk) const {
    return *this + breuk.operator-();
}

std::ostream& operator<<(std::ostream &out, const Breuk &breuk) {
    out << breuk.teller;
    if(breuk.noemer != 1) {
        out << "/" << breuk.noemer;
    }
    return out;
}

std::istream& operator>>(std::istream &in, Breuk &breuk) {
    std::string breukString;
    in >> breukString;
    std::stringstream ss;
    ss << breukString;
    if(breukString.find("/") != std::string::npos) {
        ss >> breuk.teller;
        char ch;
        ss >> ch;
        ss >> breuk.noemer;
    }
    else {
        ss >> breuk.teller;
        breuk.noemer = 1;
    }
    return in;
}

int Breuk::getTeller() const {
    return this->teller;
}

int Breuk::getNoemer() const {
    return this->noemer;
}

Breuk& Breuk::operator+=(const Breuk breuk) {
    Breuk som = *this + breuk;
    *this = som;
    return *this;
}

Breuk& Breuk::operator-=(const Breuk breuk) {
    Breuk verschil = *this - breuk;
    *this = verschil;
    return *this;
}

Breuk& Breuk::operator++() {
    teller += noemer;
    herbereken();
    return *this;
}

Breuk Breuk::operator++(int a) {
    Breuk temp(*this);
    teller+= noemer;
    herbereken();
    return temp;
}

bool Breuk::operator==(const Breuk breuk) const {
    return (teller == breuk.getTeller() && noemer == breuk.getNoemer());
}

bool Breuk::operator!=(const Breuk breuk) const {
    return !(operator==(breuk));
}

bool Breuk::operator<(const Breuk breuk) const {
    int teller1 = teller * breuk.getNoemer();
    int teller2 = breuk.getTeller() * noemer;

    return teller1 < teller2;
}

bool Breuk::operator>(const Breuk breuk) const {
    return !(operator<(breuk));
}

Breuk operator+(int i, const Breuk breuk) {
    return breuk + i;
}

// zet deze functie in het bestand 'breuk.cpp'
int mijn_ggd(int a, int b){
    if(a < 0 || b < 0){
        return mijn_ggd(abs(a),abs(b));
    }
    if(a < b){
        return mijn_ggd(b,a);
    }
    if(b == 0){
        return a;
    }
    return mijn_ggd(b,a%b);
}


bool is_stambreuk(Breuk breuk) {
    return (breuk.getTeller() == 1);
}