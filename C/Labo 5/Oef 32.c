/*oef 32*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

char * lees();

int main(){
    int i;
    for(i=0; i<5; i++){    
        char * tekst = lees();
        printf("Ik las in '%s'.\n", tekst);
        printf("de lengte hiervan was %d\n", strlen(tekst));
        free(tekst);
    }	
    return 0;
}

char * lees() {
	char input[MAX + 1]; /*input of user*/
	char* result;/* c-string which will become length of input*/
	
	fgets(input, MAX + 1, stdin);
	
	if(input[strlen(input) - 1] == '\n') {
		input[strlen(input) - 1] = 0;
	}
	else {
		while(getchar() != '\n');
	}
	
	result = malloc((strlen(input) + 1 )*(sizeof(char)));
	strcpy(result, input);
	return result;
}
