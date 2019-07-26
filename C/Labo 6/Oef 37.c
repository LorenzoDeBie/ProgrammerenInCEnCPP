/*Oef 37*/

#include <stdlib.h>
#include <stdio.h>

typedef struct Knoop Knoop;
struct Knoop {
	int d;
	Knoop *opv;
};

void voeg_vooraan_toe(int, Knoop**);
void print_lijst(const Knoop*);
void print_lijst_rec(const Knoop*);
void free_lijst(Knoop**);

int main() {
	Knoop *l = 0;
	voeg_vooraan_toe(3, &l);
	voeg_vooraan_toe(7, &l);
	print_lijst(l);
	print_lijst_rec(l);
	free_lijst(&l);
	return 0;
}

void voeg_vooraan_toe(int getal, Knoop **k) {
	Knoop *nieuw = malloc(sizeof(Knoop)); /*geheugen klaarzetten voor nieuwe knoop*/
	
	nieuw->d = getal; /*getal voor knoop zetten*/
	nieuw->opv = *k; /*opvolger van nieuwe knoop is eerste knoop*/
	*k = nieuw;/*de pointer naar de knoop wordt de net aangemaakte pointer*/
}

void print_lijst(const Knoop *k) {
	if(k) { /*check of de lijst niet leeg is*/
		printf("%d", k->d); /*print het getal*/
		k = k->opv; /*ga naar de volgende knoop*/
	}
	while(k) { /*zolang we niet aan de laatste knoop zitten (opv van laatste knoop = null)*/
		printf("\n%d", k->d); /*print het getal*/
		k = k->opv; /*ga naar de volgende knoop*/
	}
}

void print_lijst_rec(const Knoop *k) {
	if(k) { /*check of k nog niet leeg is*/
		printf("\n%d", k->d); /*print het getal van de knoop*/
		print_lijst_rec(k->opv); /*volgende knoop kan ook gezien worden als het begin van een nieuwe lijst, dus kan deze functie opnieuw aangeroepen worden*/
	}
}

void free_lijst(Knoop** l) {
	Knoop *k; /*hulp*/
	while(*l) { /*zolang er nog knopen zijn*/
		k = *l; /*k ook naar de knoop die gefreed moet worden laten wijzen*/
		*l = k->opv; /*l naar volgende laten wijzen*/
		free(k); /*k vrijgeven*/
	}
}

