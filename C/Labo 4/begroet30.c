/* oef 30, vervolg op 29 */

#include <stdio.h>
#include <string.h>

void my_toupper( char*);
char *alfab_kleinste( char**, int);

int main(int argc, char** argv) {	
	char *kleinste = "";	
	
	if(argc == 1) {
		printf("Dag Allemaal!");
		return 0;
	}
	printf("kleinste = %s\n", kleinste);
	kleinste = alfab_kleinste(argv, argc);
	my_toupper(kleinste);
	printf("Dag %s!", kleinste);
	
	
	return 0;
}

void my_toupper( char *s) {
	if(*s > 'a' && *s < 'z') {
		*s -= 'a' - 'A';
	}
	while(*s++) {
		if(*s > 'A' && *s < 'Z') {
			*s += 'a' - 'A';
		}
	}
}

char * alfab_kleinste(char** voornamen, int size) {
	char * kleinste = voornamen[0];
	int i = 1;
	int n = 0;
	for(; i < size; i++) {
		int smallest_size = (strlen(kleinste) > strlen(voornamen[i])) ?
		 strlen(kleinste): strlen(voornamen[i]);
		for(; n < smallest_size; n++) {
			if(voornamen[i][n] < kleinste[n]) {
				kleinste = voornamen[i];
				break;
			}
		}
	}
	return kleinste;
}
