/* oef 27 */

#include <stdio.h>

void schrijf(const char *, const char *);
void verzetNaarEersteHoofdletter(const char**);
const char* pointerNaarEersteKleineLetter(const char*);

int main() {
	const char zus1[50] = "sneeuwWITje";
	const char zus2[50] = "rozerood";
	const char* begin;
	const char* eind;
	begin = zus1;
	verzetNaarEersteHoofdletter(&begin);
	eind = pointerNaarEersteKleineLetter(begin);
	schrijf(begin,eind); /* schrijft ’WIT’ uit */
	printf("\n");
	begin = zus2;
	verzetNaarEersteHoofdletter(&begin);
	eind = pointerNaarEersteKleineLetter(begin);
	schrijf(begin,eind); /* schrijft ’ROOD’ uit */
	return 0;
}

void verzetNaarEersteHoofdletter(const char** ptr) {
	while((**ptr > 'Z' || **ptr < 'A')) (*ptr)++;
}

void schrijf(const char * begin, const char * einde) {
	int i = 0;
	for(; i < (einde - begin); i++) {
		printf("%c", *(begin + i));
	}
}

const char* pointerNaarEersteKleineLetter(const char* ptr) {
	while(*ptr > 'z' || *ptr < 'a') ptr++;
	return ptr;
}
