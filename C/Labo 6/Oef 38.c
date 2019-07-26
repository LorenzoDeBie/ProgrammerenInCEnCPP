/*Oef 38*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Knoop Knoop;
struct Knoop {
	int d;
	Knoop *opv;
};

Knoop* maak_gesorteerde_lijst_automatisch(int, int);
void voeg_vooraan_toe(int, Knoop **);
void print_lijst(const Knoop*);
void free_lijst(Knoop **);
void verwijder_dubbels(Knoop **);

int main(){
	Knoop *l;
    srand(time(NULL));
    l = maak_gesorteerde_lijst_automatisch(10,100);
    print_lijst(l);
    printf("\n\nnu worden dubbels verwijderd: \n");
    verwijder_dubbels(&l); /* aan te vullen */
    printf("\nna verwijderen van dubbels: \n");
    print_lijst(l);
    free_lijst(&l);
    return 0;
}

/*dit kan waarschijnlijk ook met Knoop *l!! en is waarschijnlijk ook de bedoeling*/
void verwijder_dubbels(Knoop **l) {
	Knoop *k = *l, *b = *l;
	*l = k->opv;
	while(*l) {
		/*check if they are the same*/
		if(k->d == (*l)->d) {
			/*remove this one*/
			printf("%d verwijderd\n", k->d);
			k->opv = (*l)->opv;
			free(*l);
			*l = k; /*dit is kleine omweg maar anders met continue werken en is ook niet goed*/
		}
		k = *l;
		*l = k->opv;
	}
	*l = b;
}

Knoop* maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens) {
	Knoop * list = malloc(sizeof(Knoop));
	int i = 1;
	list->d = bovengrens;
	list->opv = 0;
	
	for(; i < aantal; i++) {
		int g = list->d - (rand() % 3);
		voeg_vooraan_toe(g, &list);
	}
	
	return list;
}

void voeg_vooraan_toe(int getal, Knoop **k) {
	Knoop *nieuw = malloc(sizeof(Knoop)); /*allocate memory*/
	
	nieuw->d = getal; /*assign getal*/
	nieuw->opv = *k;
	*k = nieuw;
}

void print_lijst(const Knoop *k) {
	if(k) {
		printf("%d", k->d);
		k = k->opv;
	}
	while(k) {
		printf("\n%d", k->d);
		k = k->opv;
	}
}

void free_lijst(Knoop** l) {
	Knoop *k;
	while(*l) {
		k = *l;
		*l = k->opv;
		free(k);
	}
}
