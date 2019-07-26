/*oef 13*/

#include <stdio.h>

void schrijf_even_posities(char[], int);

int main() {
	char letters[] = {'p','o','r','e','o','i','f','o','i','e','c','i','i',':','a','-','t','('};
	int size = sizeof(letters);
	printf("%d\n", size);
	schrijf_even_posities(letters, size);
	return 0;
}

void schrijf_even_posities(char letters[], int size) {
	int i = 0;
	for(; i < size; i+=2) {
		printf("%c", letters[i]);
	}
}
