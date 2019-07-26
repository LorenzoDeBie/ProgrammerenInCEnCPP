/*Oef 40
Hoeft niet voor op een test, if else mag altijd!!!
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct knoop knoop;
struct knoop {
	int getal;
	knoop *next;
};

void voeg_getal_toe(int, knoop**);
knoop* maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens);
void voeg_vooraan_toe(int getal, knoop **k);
void free_lijst(knoop** l);
void print_lijst(const knoop *k);

int main() {
	knoop *l;
    srand(time(NULL));
    l = maak_gesorteerde_lijst_automatisch(4,10);
    print_lijst(l);
    voeg_getal_toe(2, &l);
    printf("\n\n");
    print_lijst(l);
    
	return 0;
}

/*deze functie zonder if else*/
void voeg_getal_toe(int g, knoop **l) {
   knoop *h, *m;
   if (*l == 0 || g <= (*l)->getal) {
      h = (knoop*) malloc(sizeof(knoop));
      h->getal = g; h->next = *l; *l = h;
   }
   else {
      h = *l;
      while (h->next != 0 && h->next->getal < g)
         h = h->next;
      m = h->next;
      h->next = (knoop*) malloc(sizeof(knoop));
      h = h->next; h->getal = g; h->next = m;
   }
}

knoop* maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens) {
	knoop * list = malloc(sizeof(knoop));
	int i = 1;
	list->getal = bovengrens;
	list->next = 0;
	
	for(; i < aantal; i++) {
		int g = list->getal - (rand() % 3);
		voeg_vooraan_toe(g, &list);
	}
	
	return list;
}

void voeg_vooraan_toe(int getal, knoop **k) {
	knoop *nieuw = malloc(sizeof(knoop)); /*allocate memory*/
	
	nieuw->getal = getal; /*assign getal*/
	nieuw->next = *k;
	*k = nieuw;
}

void print_lijst(const knoop *k) {
	if(k) {
		printf("%d", k->getal);
		k = k->next;
	}
	while(k) {
		printf("\n%d", k->getal);
		k = k->next;
	}
}

void free_lijst(knoop** l) {
	knoop *k;
	while(*l) {
		k = *l;
		*l = k->next;
		free(k);
	}
}