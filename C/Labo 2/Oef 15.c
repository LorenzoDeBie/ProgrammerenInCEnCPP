/* oef 15 */

#include <stdio.h>

void shift_links(char[], int);

void shift_rechts(char[], int);

void schrijf_opgeschuifd(char[], int);

int main() {
	char rij[] = {'s','a','p','a','p','p','e','l'};
	schrijf_opgeschuifd(rij, sizeof(rij));
	schrijf_opgeschuifd(rij, sizeof(rij));
	schrijf_opgeschuifd(rij, sizeof(rij));
	return 0;
}

void schrijf_opgeschuifd(char letters[], int size) {
	int i = 0;
	shift_links(letters, sizeof(letters));
	for(; i < sizeof(letters); i++) {
		printf("%c", letters[i]);
	}
	printf("\n");
}
void shift_links(char letters[], int size) {
	char l = letters[0];
	int i = 0;
	for(; i < size;i++) {
		letters[i] = letters[i+1];
	}
	letters[size-1] = l;
}

void shift_rechts(char letters[], int size) {
	char l = letters[size - 1];
	int i = size;
	for(; i > 0; i--) {
		letters[i] = letters[i - 1];
	}
	letters[0] = l;
}
