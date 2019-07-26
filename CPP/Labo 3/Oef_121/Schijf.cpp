#ifndef SCHIJF_H
#define SCHIJF_H
#include "Doos.h"
template <typename T>
class Schijf {
    private:
        Doos<T> *a;
    public:
        Schijf(Doos<T> *doosptr = nullptr);
};

template <typename T>
Schijf<T>::Schijf(Doos<T> *doosptr) {
    this->a = doosptr;
}

#endif // SCHIJF_H
