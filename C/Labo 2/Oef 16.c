/* oef 16 */

#include <stdio.h>

#define MIN 100
#define MAX 120
#define AANTAL 4

void print_int_array(const int[], int);
void put_in_array(int, int[], int);
void init_array(int, int[], int);

int main() {
	int getallen[AANTAL] = {0};
	int gekozen_getallen[AANTAL] = {121};
	char kies_getal = '0';
	int aantal_gekozen_getallen = 0;
	int i = 0;
	int size_getallen = sizeof(getallen) / sizeof(int);
	srand(time(NULL));
	init_array(121, gekozen_getallen, size_getallen);
	printf("Dit zijn twintig getallen:\n");
	for(; i < size_getallen; i++) {
		getallen[i] = 100 + (rand() % 21);
		printf("Wenst u %d te kiezen? (Y/N)\n", getallen[i]);
		scanf("%c", &kies_getal); while(getchar() != '\n');
		printf("U koos voor: %c\n", kies_getal);
		if(kies_getal == 'Y') {
			put_in_array(getallen[i], gekozen_getallen, size_getallen);
			aantal_gekozen_getallen++;
		}
	}
	if(aantal_gekozen_getallen > 0) {
		printf("\nU hebt volgende getallen gekozen:\n");
		print_int_array(gekozen_getallen, size_getallen);	
	} else {
		printf("\nU hebt geen getallen gekozen");
	}
	
	return 0;
}

void put_in_array(int getal, int getallen [], int size) {
	int i = size - 1;
	if(getal < getallen[0]) {
		getallen[0] = getal;
		return;
	}
	for(; i >= 0; i--) {
		if(getal > getallen[i]) {
			getallen[i] = getallen[i-1];
		}
		else {
			getallen[i] = getal;
			return;
		}
	}
}

void print_int_array(const int getallen[], int size) {	
	int i = 0;
	for(; i < size; i++) {
		printf("%d ", getallen[i]);
	}
}

void init_array(int value, int getallen[], int size) {
	int i = 0;
	for(; i < size; i++) {
		getallen[i] = value;
	}
}





