/* oef 29 */

#include <stdio.h>

void my_toupper( char*);

int main(int argc, char** argv) {
	int i = 1;
	if(argc == 1) {
		printf("Dag Allemaal!");
		return 0;
	}
	for(; i < argc; i++) {
		my_toupper(argv[i]);
		printf("Dag %s!\n", argv[i]);
	}
	
	return 0;
}

void my_toupper( char *s) {
	if(*s > 'a' && *s < 'z') {
		*s -= 'a' - 'A';
		s++;
	}
	while(*s++) {
		if(*s > 'A' && *s < 'Z') {
			*s += 'a' - 'A';
		}
	}
}
