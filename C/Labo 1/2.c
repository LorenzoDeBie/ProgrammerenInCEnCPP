/* oef 2 */

#include <stdio.h>

int main() {
	int dec = 0;
	int oct = 00;
	int hex = 0x0;
	int i = 0;
	
	for(; i < 65; i++) {
		printf("%o\t%d\t%x\t\n", oct, dec, hex);
		oct++; dec++; hex++;
	}
	return 0;
}
