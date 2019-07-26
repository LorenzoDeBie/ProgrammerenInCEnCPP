/* Oef 34 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int waarde;
	int aantal_delers;
	int* delers;
} deeltal;

/*alle schrijf procedures*/
void schrijf_ints(const int*, int);
void schrijf_deeltal(const deeltal *);
void schrijf_deeltallen(deeltal*, int);

/*alle reken functies*/
int aantal_delers_van(int);
int* delers_van(int, int);

/*alle lees procedures*/
void lees_deeltal(deeltal*);
void lees_deeltallen(deeltal*, int);

/*zoek functie*/ 
const deeltal* zoek_deeltal(int, const deeltal*, int);

/*voorkom memory leask*/
void free_deeltallen(deeltal*, int);
void free_delers(deeltal*);

int main() {
	int n = 0, z = 0;
	deeltal d1; /*1e deeltal*/
	deeltal *d2; /*lijst van deeltallen*/
	const deeltal *d3; /*gezochte deeltal*/
	
	lees_deeltal(&d1);
	schrijf_deeltal(&d1);
	
	printf("\nHoeveel deeltallen wilt u nu inlezen? ");
	scanf("%d", &n);
	
	d2 = malloc(n*sizeof(deeltal));
	lees_deeltallen(d2, n);
	schrijf_deeltallen(d2, n);
	
	printf("Welk deeltal wilt u zoeken? ");
	scanf("%d", &z);
	d3 = zoek_deeltal(z, d2, n);
	if(d3 != NULL) {
		schrijf_deeltal(d3);
	}
	else {
		printf("Dit getal is niet gevonden!");
	}
	
	free_delers(&d1);
	free_deeltallen(d2, n);
	printf("nu geef ik de tabel zelf vrij");
	free(d2);
	
	return 0;
}

/*alle schrijf procedures*/
void schrijf_ints(const int* n, int size) {
	int i = 1;
	/* 	beter oplossing om enkel tussenteken bij niet de laatste:
		eerste printen zonder --> dan al de rest met teken ervoor*/
	/*	slechte versie
	for(; i < size; i++) {
		printf("%d", *n++);
		if(i != size-1) {
			printf("-");
		}
	}*/
	
	printf("%d", *n++);
	for(; i < size; i++) {
		printf("-%d", *n++);
	}
}

void schrijf_deeltal(const deeltal * d) {
	printf("Het getal %d heeft %d delers: ", d->waarde, d->aantal_delers);
	schrijf_ints(d->delers, d->aantal_delers);
	printf("\n");
}

void schrijf_deeltallen(deeltal *t, int aantal) {
	int i = 0;
	for(; i < aantal; i++) {
		schrijf_deeltal(t++);
	}
}

/*alle reken functies*/
int aantal_delers_van(int x) {
	/*aantal is altijd al 1 want 1 is deler
		 --> dus ook beginnen van 2*/
	int aantal = 1;
	int i = 2;
	for(; i <= (x/2); i++) {
		if(!(x % i)) {
			aantal++;
		}
	}
	return aantal;
}

int * delers_van(int x, int aantal) {
	int *p = malloc(aantal*sizeof(int));
	int i = 1, aantal_gevonden = 0;
	
	for(;aantal_gevonden < aantal; i++) {
		if(!(x % i)) {
			*p++ = i;
			aantal_gevonden++;
		}
	}
	p -= aantal;
	return p;
}

/*alle lees procedures*/
void lees_deeltal(deeltal *g) {
	printf("Geef de waarde van het deeltal: ");
	scanf("%d", &(g->waarde));
	/*ook checken voor negatieve nummers!*/
	if(g->waarde < 0) {
		g->waarde *= -1;
	}
	g->aantal_delers = aantal_delers_van(g->waarde);
	g->delers = delers_van(g->waarde, g->aantal_delers);
}

void lees_deeltallen(deeltal *t, int aantal) {
	int i = 0;
	for(; i < aantal; i++) {
		lees_deeltal(t++);
	}
}

/*zoek functie*/ 
const deeltal* zoek_deeltal(int waarde, const deeltal* t, int aantal) {
	int i = 0;
	for(; i < aantal; i++) {
		if(t->waarde == waarde) {
			return t;
		}
		t++;
	}
	return NULL;
}

/*voorkom memory leaks*/
void free_deeltallen(deeltal* d, int aantal) {
	/*	voor elk deeltal moet ik:
		free(delers)
		free(deeltal zelf)
	*/
	int i = 0;
	for(; i < aantal; i++) {
		free_delers(d);
		d++;
	}
}

void free_delers(deeltal *d) {
	printf("Nu geef ik %d zijn delers vrij\n", d->waarde);
	free(d->delers);
}

