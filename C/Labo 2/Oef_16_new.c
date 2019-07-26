/* oef 16_new */

#include <stdio.h>

#define AANTAL 20
#define MIN 100
#define MAX 120

void add_int_to_array(int, int[], int);

int main() {
	int getal = 0; /* getal tussen 100 en 120*/
	int i = 0;/*index*/
	char answer = 'A'; /* answer for question*/
	int gekozen_getallen[AANTAL] = {0};
	int aantal_getallen = 0;
	
	srand(time(NULL));
	for(; i < AANTAL; i++) {
		getal = MIN + (rand() % (MAX - MIN + 1)); /* calculate new random number*/
		printf("Wenst u %d te behouden? (Y/N)\n", getal);/* ask if user wants the number*/
		scanf("%c", &answer); while(getchar() != '\n');/* scan for answer and clr line*/
		if(answer == 'Y' || answer == 'y') {
			add_int_to_array(getal, gekozen_getallen, sizeof(gekozen_getallen) / sizeof(int));
			aantal_getallen++;
		}	
	}
	
	if(aantal_getallen != 0) {
		printf("U heeft volgende getallen behouden: \n");
		for(i = 0; i < aantal_getallen; i++) {
			printf("%d\n", gekozen_getallen[i]);
		}	
	}
	else {
		printf("U heeft geen enkel getal behouden.\n");
	}
	
	
	return 0;
}

void add_int_to_array(int getal, int arr[], int size) {
	int i = size - 1;
	
	if(arr[0] == 0) {
		arr[0] = getal;
		return;
	}
	
	for(; i > 0; i--) {
		if(arr[i - 1] > getal || arr[i - 1] == 0) {
			arr[i] = arr[i - 1];
		} 
		else {
			arr[i] = getal;
			return;
		}
	}
	arr[0] = getal;
}
