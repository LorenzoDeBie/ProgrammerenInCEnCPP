/*oef 21*/

#include <stdio.h>

void schrijf_aantal(const char*, int);
void schrijf(const char*, const char*);

int main() {
	char letters[] = {'p','o','r','g','o','e','d','o','i','e','o','k',
				'i',':','a','-','t','('};
	const char *p = letters;
	
	schrijf_aantal(letters + 3, 4);
	printf("\n");
	schrijf(p + 10, p + 12);
	return 0;
}

void schrijf_aantal(const char * begin, int aantal) {
	int i = 0;
	for(; i < aantal; i++) {
		printf("%c", *(begin + i));
	}
}

void schrijf(const char * begin, const char * einde) {
	int i = 0;
	for(; i < (einde - begin); i++) {
		printf("%c", *(begin + i));
	}
}
