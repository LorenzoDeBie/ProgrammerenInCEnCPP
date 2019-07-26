/*Oef 41*/

#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;

struct knoop {
	int d;
	knoop *opv;
};

knoop* maak_gesorteerde_lijst_automatisch(int, int);
void voeg_vooraan_toe(int, knoop **);
void print_lijst(const knoop*);
void free_lijst(knoop **);
void free_lijst_rec(knoop**);
void verwijder_dubbels(knoop **);

knoop *merge(knoop**, knoop**);

int main(){
	knoop *m, *n, *mn;
    srand(time(NULL));
    
    m = maak_gesorteerde_lijst_automatisch(10,1000);
    n = maak_gesorteerde_lijst_automatisch(5,1000);
    
    	
    printf("\nLIJST m:\n");    print_lijst(m);
    printf("\nLIJST n:\n");    print_lijst(n);
    printf("\nDeze worden gemerged. \n\n");
    
    mn = merge(&m, &n);	
	
    printf("\nLIJST m:   \n");	print_lijst(m);
    printf("\nLIJST n:   \n");	print_lijst(n);
    printf("\nRESULTAAT: \n");	print_lijst(mn);
	
	printf("\n");	
    
	free_lijst(&mn);
    return 0;
}

knoop * merge( knoop** l1, knoop** l2) {
	knoop *lr, *h1, *h2, *hr;
	
	/*check if a list is empty --> return the other*/
	if(!(*l1)) {
		lr = *l2;
		*l2 = NULL;
		return lr;
	}
	else if(!(*l2)) {
		lr = *l1;
		*l1 = NULL;
		return lr;
	}
	
	/*set helper pointers*/
	h1 = *l1, h2 = *l2;
	
	if((*l1)->d <= (*l2)->d) {
		lr = *l1;
		h1 = h1->opv;
	}
	else {
		lr = *l2;
		h2 = h2->opv;
	}
	/*set result helper pointer*/
	hr = lr;
	
	/*merging happens here*/
	while(h1 && h2) {
		if(h1->d < h2->d) {
			hr->opv = h1;
			h1 = h1->opv;
		}
		else {
			hr->opv = h2;
			h2 = h2->opv;
		}
		hr = hr->opv;
	}
	
	/*check if there still is anything in the lists*/
	if(h1) {
		hr->opv = h1;
	}
	else {
		hr->opv = h2;
	}
	/*delete l1 & l2*/
	*l1 = NULL; *l2 = NULL;
	return lr;
}

/*dit kan waarschijnlijk ook met Knoop *l!! en is waarschijnlijk ook de bedoeling*/
void verwijder_dubbels(knoop **l) {
	knoop *k = *l, *b = *l;
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

knoop* maak_gesorteerde_lijst_automatisch(int aantal, int bovengrens) {
	knoop * list = malloc(sizeof(knoop));
	int i = 1;
	list->d = bovengrens;
	list->opv = 0;
	
	for(; i < aantal; i++) {
		int g = list->d - (rand() % 3);
		voeg_vooraan_toe(g, &list);
	}
	
	return list;
}

void voeg_vooraan_toe(int getal, knoop **k) {
	knoop *nieuw = malloc(sizeof(knoop)); /*allocate memory*/
	
	nieuw->d = getal; /*assign getal*/
	nieuw->opv = *k;
	*k = nieuw;
}

void print_lijst(const knoop *k) {
	if(k) {
		printf("%d", k->d);
		k = k->opv;
	}
	while(k) {
		printf("\n%d", k->d);
		k = k->opv;
	}
}

void free_lijst(knoop** l) {
	knoop *k;
	while(*l) {
		k = *l;
		*l = k->opv;
		printf("\nnu geef ik %d vrij", k->d);
		free(k);
	}
}

void free_lijst_rec(knoop** l) {
	knoop* k;
	if((*l)->opv) {
		k = *l;
		*l = k->opv;
		printf("nu geef ik %d vrij", k->d);
		free(k);
		free_lijst_rec(l);
	}
	else {
		printf("nu zit ik in de else, %d", (*l)->d);
		free(*l);
	}
}



