/* oef 31 */

#include <stdio.h>

void schrijf_cstring(const char* const *);
void schrijf_int(const int*);
void schrijf_double(const double*);

void schrijf_array(const void*, int, int, char, void(*)(const void*));

int main(int argc, char** argv) {
	char * namen[] = {"Evi","Jaro","Timen","Youri","Ashaf","Jennifer"};
	int leeftijden[] = {21,30,18,14,22,19};
	double scores[] = {0.5,1.6,8.2,-2.4};
	
	//printf("sizeof int %d, sizeof double %d, sizeof char %d", sizeof(int), sizeof(double), sizeof(char *));
	
	schrijf_array((void *)leeftijden, sizeof(int), 6, ',', (void(*)(const void*))&schrijf_int);
	printf("\n");
	schrijf_array(scores, sizeof(double), 4, '~', (const void *)&schrijf_double);
	printf("\n");
	schrijf_array(namen, sizeof(char *), 6, ';', (const void *)&schrijf_cstring);
	
	return 0;
}

void schrijf_array(const void* array, int grootte, int aantal, char leesteken,
	void (*schrijf)(const void*)) {
		const char * char_array = (const char *)array;
		int i = 0;
		for(; i < aantal - 1; i++) {
			schrijf(char_array);
			char_array += grootte;
			printf("%c", leesteken);
		}
		schrijf(char_array);
}

void schrijf_cstring(const char* const * s) {
	printf("%s", *s);
}

void schrijf_int(const int* i) {
	printf("%d", *i);
}

void schrijf_double(const double* d) {
	printf("%.1lf", *d);
}
