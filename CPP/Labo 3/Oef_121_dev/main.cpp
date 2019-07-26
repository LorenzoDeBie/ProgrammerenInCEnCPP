#include <iostream>
#include "Doos.h"
#include "Schijf.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	std::cout << "Hallo!";
	Schijf<int> schijf;
	Doos<int> doos;
	Doos<int> doos2(doos);
	
	cout << doos;
	
	return 0;
}
