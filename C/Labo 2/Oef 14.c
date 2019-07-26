/* oef 14*/

#include <stdio.h>

int index_of(const double[], int, double);
int index_of_sorted(const double[], int, double);

int main() {
	double getallen[] = {0.0, 1, 1.5, 3, 4, 7.8, 9};
	double sorted_getallen[] = {0, 1, 2, 3, 3.5, 4, 5};
	int size = sizeof(getallen);
	double d = 0;
	int is_r = 0;
	while (is_r==0){
		printf("Geef een reëel getal: ");
		is_r = scanf("%lf", &d);
		while(getchar() != '\n');	
	}
	printf("%.3lf staat op plaats %d in de array\n", d, index_of(getallen, size, d));
	printf("%.3lf staat op plaats %d in de array\n", d, index_of_sorted(getallen, size, d));
	return 0;
}

int index_of(const double array[], int size, double getal) {
	int i = 0;
	for(; i < size; i++){
		if(array[i] == getal) {
			printf("ik het nu %d keer gezocht\n", i);
			return i + 1;
		}
	}
	printf("ik het nu %d keer gezocht\n", i);
	return -1;
}

int index_of_sorted(const double array[], int size, double getal) {
	int i = 0;
	for(; i < size && getal >= array[i]; i++){
		if(array[i] == getal) {
			printf("ik het nu %d keer gezocht\n", i);
			return i + 1;
		}
	}
	printf("ik het nu %d keer gezocht\n", i);
	return -1;
}
