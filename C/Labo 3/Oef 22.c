/* oef 22*/

#include <stdio.h>

void zoek_extremen(const int[], int, int*, int*);
void zoek_extremen_rec(const int[], int, int*, int*);

int main() {
	int getallen[] = {1, 4, -19, 20, 45, 6, 7};
	int min = 0;
	int max = 0;
	int rec_min = 0;
	int rec_max = 0;
	
	zoek_extremen(getallen, sizeof(getallen)/sizeof(int), &min, &max);
	zoek_extremen_rec(getallen, sizeof(getallen)/sizeof(int), &rec_min, &rec_max);
	
	printf("min = %d, max = %d", min, max);
	printf("rec_min = %d, rec_max = %d", rec_min, rec_max);
	return 0;
}

void zoek_extremen(const int getallen[], int size, int * min, int * max) {
	int i = 1;
	int lmin = getallen[0];
	int lmax = getallen[0];
	for(; i < size; i++) {
		if(getallen[i] < lmin) {
			lmin = getallen[i];
		}
		if(getallen[i] > lmax) {
			lmax = getallen[i];
		}
	}
	
	*min = lmin;
	*max = lmax;
	
}
void zoek_extremen_rec(const int getallen[], int size, int * min, int * max) {
	if(getallen[0] < *min || min == NULL) {
		*min = getallen[0];
	}
	if(getallen[0] > *max || max == NULL) {
		*max = getallen[0];
	}
	if(size > 1) {
		zoek_extremen_rec(&getallen[1], size - 1, min, max);
	}	
}
