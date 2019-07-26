#include "Schijf.h"
#include "Doos.h"
template <typename T>
Schijf<T>::Schijf(Doos<T> *doosptr) {
    this->a = doosptr;
}
