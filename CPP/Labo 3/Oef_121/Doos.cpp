#ifndef DOOS_H
#define DOOS_H
#include "../../headers/containers.h"
#include <iostream>
template <typename T>
class Schijf;
template <typename T>
class Doos {
    private:
        std::vector<T> b;
        Doos<T> *c;
        Schijf<T> **d;
    public:
        Doos();
        Doos(const Doos<T> &doos);
        friend std::ostream& operator<<(ostream &out, Doos<T> doos);
};

//default constructor
template <typename T>
Doos<T>::Doos() : b(4), c(nullptr) {
    d = new Schijf<T>*[3];
    for(int i = 0; i < 3; i++) {
        d[i] = nullptr;
    }
}

//copy constructor
template <typename T>
Doos<T>::Doos(const Doos &doos) : b(doos.b), c(doos.c), d(doos.d) {

}

template <typename T>
std::ostream& operator<<(ostream &out, Doos<T> doos) {
    out << "Vector: " << doos.b << std::endl;
    out << "Doos adres: " << doos.c << std::endl;
    out << "Schijfptr adres: " << doos.d << std::endl;
    out << "Schijfptr waarde: " << *(doos.d) << std::endl;
}

#endif // DOOS_H
