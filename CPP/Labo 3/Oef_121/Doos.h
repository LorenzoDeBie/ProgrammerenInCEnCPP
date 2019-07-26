#ifndef DOOS_H
#define DOOS_H
#include "../../headers/containers.h"
template <typename T>
class Schijf;
template <typename T>
class Doos {
    private:
        vector<T> b;
        Doos<T> *c;
        Schijf<T> **d;
    public:
        Doos();
        Doos(const Doos &doos);
};
#endif // DOOS_H
