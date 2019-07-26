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


#endif // SCHIJF_H
