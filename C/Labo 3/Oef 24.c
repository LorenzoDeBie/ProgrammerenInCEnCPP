/*oef 24*/

#include <stdio.h>

void schrijf(const char*, const char*);
void pivoteer(char*, char*, char*);

int main() {
	char tekst[] = {'b','d','?','z','g','o','e','z','e','b',
		' ','d','i','g','!','h','o','s','v'};
		
	char alfa[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	pivoteer(tekst+7,tekst+12,tekst+9);
	schrijf(tekst+4,tekst+15);
	printf("\n");
	pivoteer(alfa, alfa+7, alfa+2);
	schrijf(alfa, alfa+8);
	return 0;
}

void pivoteer(char * begin, char * einde, char * pivot) {
	int i = 0;
	while(begin != (pivot - i + 1) && einde != (pivot + i - 1)) {
		char hulp = *(pivot - i);
		*(pivot - i) = *(pivot + i);
		*(pivot + i) = hulp;
		i++;
	}
}

void schrijf(const char * begin, const char * einde) {
	int i = 0;
	for(; i < (einde - begin); i++) {
		printf("%c", *(begin + i));
	}
}
