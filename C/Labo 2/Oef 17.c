/* Oef 17 */

#include <stdio.h>

void read_text(char[], int[]);
void print_hor_diagram(int[]);
void print_ver_diagram(int[]);

int main() {
	int aantallen[26] = {0};
	char input[500];
	int i = 0;
	i = 0;
	read_text(input, aantallen);
	/*for(i = 0; i < 20; i++) {
		printf("%c: aantal[%d] = %d\n",'a' + i, i, aantallen[i]);
	}*/
	
	print_hor_diagram(aantallen);
	return 0;
}

void read_text(char input[], int aantallen[]) {
	int i = 0;
	char test = 0;
	for(; i < 500; i++) {
		scanf("%c", &test);
		if(test == '$') {
			input[i] = test;
			return;
		}
		
		if(test >= 'A' && test <= 'Z') {
			test += 'a' - 'A';
		}
		input[i] = test;
		aantallen[input[i] - 'a']++;
	}
	return;
}

void print_hor_diagram(int aantallen[]) {
	int i = 0;
	int n = 0;
	for(; i < 26; i++) {
		printf("%c: ",'a' + i);
		for(n = 0; n < aantallen[i]; n++) {
			printf("*");
		}
		printf("\n");
	}
}

void print_ver_diagram(int aantallen[]) {
	int i = 0;
	int n = 0;
	
}
