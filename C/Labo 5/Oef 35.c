/*Oef 35*/
#include <stdio.h>
#include <string.h>

#define AANTAL_WOORDEN            2 
#define GEMIDDELDE_LENGTE_WOORDEN  7
#define TOTALE_LENGTE_ARRAY   AANTAL_WOORDEN * (GEMIDDELDE_LENGTE_WOORDEN + 1)   /*gebruik vorige constanten om dit te berekenen */

void lees(char**);
void lees2(char**);
void schrijf(char* const * const);

int main(){
    char* pt[AANTAL_WOORDEN+1];  /* zodat je ook nog een nullpointer kan toevoegen
                                    op het einde van de pointertabel */
    char t[TOTALE_LENGTE_ARRAY];
	
    pt[0] = t;
	
    printf("Geef %d woorden in:\n", AANTAL_WOORDEN);
    lees(pt);     /* leest alle woorden in                  */
    schrijf(pt);  /* schrijft alle woorden onder elkaar uit */
    printf("\n");
    while(getchar() != '\n');
    lees2(pt);
    schrijf(pt);
	
    return 0;
}

void schrijf( char *const *const pt) {
	int i = 1;
	printf("%s", pt[0]);
	for(; i < AANTAL_WOORDEN && pt[i] != NULL; i++) {
		printf("\n%s", pt[i]);
	}
}

void lees(char **pt) {
	int i = 0;
	for(; i < AANTAL_WOORDEN && pt[i] != NULL; i++) {
		scanf("%s", pt[i]);
		pt[i + 1] = pt[i] + strlen(*pt) + 1; 
	}
	pt[i] = 0;
}

void lees2(char** pt) {
	int i = 0;
	int charsleft = TOTALE_LENGTE_ARRAY;
	for(; i < AANTAL_WOORDEN && charsleft > 1; i++) {
		printf("Geef een woord in van max %d karakters\n", charsleft);
		fgets(pt[i], charsleft, stdin); /*input in t steken*/
		pt[i+1] = pt[i] + strlen(pt[i]); /*volgende ptr klaarzetten*/
		charsleft -= strlen(pt[i]); /*minder karakters over om nog op te slaan*/
		*(pt[i] + strlen(pt[i])) = 0;
	}
	*(pt[i-1]);
	pt[i] = 0;
}
