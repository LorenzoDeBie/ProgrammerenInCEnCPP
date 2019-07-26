/*oef 33*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define MAXAANTAL 6

char * lees();
char ** lees_meerdere();

int main(){    
    char ** s = lees_meerdere();
    
    if(*s == NULL) {
    	printf("Er werd enkel STOP doorgegeven");
    	return 0;
	}
    while(*s != NULL) {
    	printf("adres: %d, waarde: %s.\n", s, *s);
    	free(*s);
    	s++;
	}
	
    return 0;
}

char ** lees_meerdere() {
	int i = 0, n = 0; /*index counters*/
	char** p; /*pointer to C-strings to return*/
	char * s[MAXAANTAL];/*array to store input from user*/
	
	/*	Fill up first open entry with user input
		and check if not STOP
	*/
	do {
		s[i] = lees();
		i++;
	} while( i < MAXAANTAL && strcmp("STOP", s[i - 1]));
	
	/*
		check if last entry was not STOP, decrement i so I dont copy that one
	*/
	if(!strcmp("STOP", s[i - 1])) {
		i--;
	}
	
	
	/*reserve memory for p (i inputs +  1 for nullptr)*/
	p = malloc((i + 1) * sizeof(char *));
	/*loop through the array and point each ptr of p to c-string*/
	for(; n < i; n++) {
		*p = s[n];
		p++;
	}
	*p = NULL; /*last ptr of p must be NULL*/
	return (p - n); /*return adress of first ptr of p*/
}

char * lees() {
	char input[MAX + 1]; /*input of user*/
	char* result;/* c-string which will become length of input*/
	
	fgets(input, MAX + 1, stdin); /*reads max chars of next line*/
	
	if(input[strlen(input) - 1] == '\n') { /*if last char of line is lb --> make it 0*/
		input[strlen(input) - 1] = 0;
	}
	else {
		while(getchar() != '\n'); /* clean line if lb has not been read yet*/
	}
	
	result = malloc((strlen(input) + 1 )*(sizeof(char))); /*reserve memory for this c-string*/
	strcpy(result, input);
	return result;
}
