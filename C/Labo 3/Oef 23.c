/* oef 23 */

#include <stdio.h>

const int *plaats_van(const int[], int, int);

void plaats_ptr_op_getal(int[], int, int, int**);

void verdubbel_in_array(int[], int, int, int**);

int main() {
	int getallen[] = {0, 1, 3, 4, 7, 10, 9};
	int sorted_getallen[] = {0, 1, 2, 3, 4, 5};
	int size = sizeof(getallen) / sizeof(int);
	int *ptr = NULL;
	const int *p = plaats_van(getallen, size, 0);
	/*23.1*/
	printf("%d staat op plaats %d in de array\n", 0, p - getallen + 1);
	p = plaats_van(getallen, size, 9);
	printf("%d staat op plaats %d in de array\n", 9, p - getallen + 1);
	p = plaats_van(getallen, size, 6);
	printf("%d staat op plaats %d in de array\n", 6, p);
	printf("\n");
	/*23.3*/
	printf("ptr wordt nu naar %d verplaatst\n", 0);
	plaats_ptr_op_getal(getallen, size, 0, &ptr);
	printf("de waarde waar ptr naar wijst is %d\n", *ptr);
	printf("ptr wordt nu naar %d verplaatst\n", 9);
	plaats_ptr_op_getal(getallen, size, 9, &ptr);
	printf("de waarde waar ptr naar wijst is %d\n", *ptr);
	printf("ptr wordt nu naar %d verplaatst\n", 6);
	plaats_ptr_op_getal(getallen, size, 6, &ptr);
	printf("de waarde waar ptr naar wijst is %s\n", ptr);
	printf("\n");
	/*23.4*/
	verdubbel_in_array(getallen, size, 3, &ptr);
	verdubbel_in_array(getallen, size, 9, &ptr);
	verdubbel_in_array(getallen, size, 8, &ptr);
	
	return 0;
}

const int *plaats_van( const int getallen[], int size, int getal) {
	int i = 0;
	for(; i < size; i++) {
		if(getallen[i] == getal) {
			return &getallen[i];
		}
	}
	return NULL;
}

void plaats_ptr_op_getal(int getallen[], int size, int getal, int **ptr) {
	int i = 0;
	for(; i < size; i++) {
		if(*getallen == getal) {
			*ptr = getallen;
			return;
		}
		getallen++;
	}
	*ptr = NULL;
}

void verdubbel_in_array(int getallen[], int size, int getal, int **ptr) {
	printf("ik wil graag het getal %d verdubbelen\n", getal);
	plaats_ptr_op_getal(getallen, size, getal, ptr);
	if(*ptr != NULL) {
		**ptr *= 2;
		printf("de waarde waar ptr naar wijst is %d\n", **ptr);
	}
	else {
		printf("Het getal zat niet in de array");
	}
	
}
