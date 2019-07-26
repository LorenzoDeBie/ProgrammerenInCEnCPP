/*Oef 43*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTE_STRING 80

typedef struct knoop knoop;
struct knoop {
	char *s;
	knoop *opv;
};

void print_lijst_strings(const knoop*);
void free_lijst(knoop **);

knoop **geef_array_van_lijsten(int);
int main() {
	int aantal = 3, i = 0;
	knoop **lijst = geef_array_van_lijsten(aantal);
	
	printf("Ik zal nu de lijsten printen:\n");
	for(; i < aantal; i++) {
		print_lijst_strings(lijst[i]);
		free_lijst(&lijst[i]);
	}
	
	return 0;
}

knoop **geef_array_van_lijsten(int aantal) {
	int i = 0; /*counter*/
	knoop **result = malloc(aantal * sizeof(knoop*));/*resulting array of lists*/
	knoop **hulp = malloc(aantal * sizeof(knoop*));/*array of pointers to help*/
	char input[MAX_LENGTE_STRING + 1] = {0}; /*input buffer: 80 chars + \n + \0*/
	
	for(; i < aantal; i++) {
		result[i] = 0; /*alle pointers initialiseren*/
		hulp[i] = result[i]; /*alle hulppointers initialiseren*/
	}
	
	printf("geef woorden in van max %d karakters: ", MAX_LENGTE_STRING);
	/*leest MAX_LENGTE_STRING (80) chars + enter*/
	fgets(input, MAX_LENGTE_STRING + 1, stdin);
	
	i = 0; /*reset the counter*/
	while(strcmp(input, "STOP\n")) {
		/*checks if input was longer than 80 chars*/
		if(input[strlen(input) - 1] == '\n') {
			input[strlen(input) - 1] = 0;
		}
		else {
			while(getchar() != '\n');
		}
		/*voor de eerste woorden te initialiseren*/
		if(!result[i % aantal]) { 
			/*maak plaats voor een knoop*/
			result[i % aantal] = malloc(sizeof(knoop));
			/*hulppointer goed zetten*/
			hulp[i % aantal] = result[i % aantal];
		}
		/*als het niet de eerste woorden zijn*/
		else {
			/*maak plaats voor de nieuwe knoop*/
			hulp[i % aantal]->opv = malloc(sizeof(knoop));
			/*verzet de hulppointer*/
			hulp[i % aantal] = hulp[i % aantal]->opv;
		}
		/*maak net genoeg plaats voor de string*/
		hulp[i % aantal]->s = malloc(sizeof(char) * (strlen(input) + 1));
		/*kopieer de input naar de knoop*/
		strcpy(hulp[i % aantal]->s, input);
		/*init opv naar null*/
		hulp[i % aantal]->opv = 0;
		/*hier staat de hulppointer al goed, ideaal dus*/
			
		/*lees volgende string*/
		printf("Volgende: ");
		fgets(input, MAX_LENGTE_STRING + 1, stdin);
		i++;
	}
	
	free(hulp);
	return result;
}

void print_lijst_strings(const knoop *k) {
	if(k) {
		printf("%s", k->s);
		k = k->opv;
	}
	while(k) {
		printf(" %s", k->s);
		k = k->opv;
	}
	printf("\n");
}

void free_lijst(knoop** l) {
	knoop *k;
	while(*l) {
		k = *l;
		*l = k->opv;
		free(k->s);
		free(k);
	}
}

