//oefening 8

#include <stdio.h>

int cijfersom(int);

int cijfersom_rec(int);

int main() {
	printf("cijfersom van 15: %d\n", cijfersom(12345));
	printf("cijfersom van 12345 recursief %d\n", cijfersom_rec(12345));
	return 0;
}

int cijfersom(int x) {
	int som = 0;
	do {
		//printf("nu optellen\n");
		som += x % 10;
		//printf("%d\n", x /10);
		x /= 10;
		//printf("result while: %d\n getal deling: %d\n", (x / 10) > 0, x);
	} while((x / 10) > 0);
	som+= x % 10;
	return som;
}

int cijfersom_rec(int x) {
	if(x / 10 == 0) {
		return x;
	}
	else {
		int n = x % 10;
		return n + cijfersom_rec(x/10);
	}
}
