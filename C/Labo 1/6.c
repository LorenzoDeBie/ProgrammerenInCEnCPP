/* oef 6 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	int i = 1;
	int random = (2 + (rand() % 20));
	printf("%d\n", random);
	long long n = 1;
	for(; i <= random; i++) {
		n *= (i+1);
	}
	printf("%d", n);
	return 0;
}
