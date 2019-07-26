#include "Schijf.h"
#include "Doos.h"
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
