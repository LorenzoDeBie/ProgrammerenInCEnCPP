/* oef 10 */

#include <stdio.h>
#include <stdlib.h>

int ggd(int, int);
int controleer_ggd(int, int, int);

int main() {
	printf("%d\n", ggd(-6, -8));
	printf("%d\n", ggd(24, 18));
	printf("%d\n", ggd(0, 5));
	printf("%d\n", ggd(6, 35));
	printf("nu met controleer functie\n");
	printf("ggd(-6, -8) controleer met 2: %d\n", controleer_ggd(-6, -8, 2));
	printf("ggd(-6, -8) controleer met 3: %d\n", controleer_ggd(-6, -8, 3));
	printf("ggd(24, 18) controleer met 6: %d\n", controleer_ggd(24, 18, 6));
	printf("ggd(24, 18) controleer met 60: %d\n", controleer_ggd(24, 18, 60));
	printf("ggd(0, -5) controleer met 5: %d\n", controleer_ggd(0, -5, 5));
	printf("ggd(0, -5) controleer met -5: %d\n", controleer_ggd(0, -5, -5));
	printf("ggd(6, -35) controleer met 1: %d\n", controleer_ggd(6, -35, 1));
	printf("ggd(6, -35) controleer met 10: %d\n", controleer_ggd(6, -35, 10));
	return 0;
}

int ggd(int a, int b) {
	if(a == 0) {
		return abs(b);
	}
	else if( b == 0) {
		return abs(a);
	}
	else {
		if (abs(b) > abs(a)) {
			return ggd(a, b % a);
		}
		else {
			return ggd(b, a % b);
		}
	}
	
}

int controleer_ggd(int a, int b, int res) {
	return (res == ggd(a, b));
}
