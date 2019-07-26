#include <iostream>
#include "../../headers/containers.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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
		~Doos();
		Doos(const Doos<T> &doos);
		Doos<T>& operator=(const Doos<T> &doos);
};

template <typename T>
class Schijf {
	private:
		Doos<T> *a;
	public:
		Schijf();
		~Schijf();
		Schijf(const Schijf<T> &schijf);
		Schijf<T>& operator=(const Schijf<T> &schijf);
};

/************************** DOOS ***************************/
//default constructor
template <typename T>
Doos<T>::Doos() : b(4), c(nullptr) {
	d = new Schijf<T>*[3];
	for(int i = 0; i < 3; i++) {
		d[i] = nullptr;
	}
}

//destructor
template <typename T>
Doos<T>::~Doos() {
	delete c; //delete de doos
	for(int i = 0; i < 3; i++) {
		delete d[i]; //delete elke schijf
	}
	delete[] d; // delete de array zelf
}

//copy constructor
template <typename T>
Doos<T>::Doos(const Doos<T> &doos) : b(doos.b) { //vector can use its copy constructor
	if(doos.c != nullptr) { // check if c points to a doos
		this.c = new Doos<T>(*(doos.c)); //use copy constructor to copy doos
	}
	else {
		this.c = nullptr;
	}
	d = new Schijf<T>[3];
	for(int i = 0; i < 3; i++) {
		if(doos.d[i] != nullptr) { //check each entry of array for a schijf
			d[i] = new Schijf<T>(*(doos.d[i])); //use copy constructor of schijf
		}
		else {
			d[i] = nullptr;
		}
	}
}

template <typename T>
Doos<T>& Doos<T>::operator=(const Doos<T> &doos) {
	if(this != &doos) { // checken of ze niet al gelijk zijn
		b = doos.b; //vector kopiëren
		delete c;
		c = nullptr;
		if(doos.c != nullptr) {
			c = new Doos<T>(*(doos.c));
		}
		for(int i = 0; i < 3; i++) {
			delete d[i];
			if(doos.d[i] != nullptr) {
				d[i] = new Schijf<T>(*(doos.d[i]));
			}
			else {
				d[i] = nullptr;
			}
		}
	}
	return *this;
}


/************************* SCHIJF *************************/
//default constructor
template <typename T>
Schijf<T>::Schijf() : a(nullptr) {}

//destructor
template <typename T>
Schijf<T>::~Schijf() {
	delete a;
}

//copy constructor
template <typename T>
Schijf<T>::Schijf(const Schijf<T> &schijf) {
	if(schijf.a != 0 ) {
		this.a = new Doos<T>(*(schijf.a));
	}
}

template <typename T>
Schijf<T>& Schijf<T>::operator=(const Schijf<T> &schijf) {
	if(this != &schijf) {
		delete a;
		a = nullptr;
		if(schijf.a != nullptr) {
			a = new Doos<T>(*(schijf.a));
		}
	}
	return *this;
}


/************************ MAIN ****************************/

int main(int argc, char** argv) {
	Doos<int> doos;
	Schijf<int> schijf;
	return 0;
}
