/* oef 28 */

#include <stdio.h>
#include <string.h>
#include <stdio.h>

void wis(char*);

int main() {
	int a = 0;
	char test[] = "8d'a7!<t-)>+. -)4h&!e9)b*( )j'(e)!4\n8g|'92o!43e5d/.' 2 3g*(e('d22a'(a25n'(d";
	char input[100]; /* bij inlezen direct alles naar 0*/
	wis(test);
	printf("%s\nEn nu met input (max 100 char): ", test);
	fgets(input, 100, stdin);
	wis(input);
	printf("gewiste input: %s", input);
	return 0;
}

void wis(char* s) {
	char *first_open_pos = s;
	while(*s != '\0') {
		while(!islower(*s) && !isspace(*s) && *s != 0) s++;
		*first_open_pos = *s;
		first_open_pos++;
		s++;
	}
	*first_open_pos = 0;
}
