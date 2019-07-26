//oef 12
#include <stdio.h>

int main() {
	int n = 0;
	int som = 0;
	int aantal = 0;
	while(n >= 0 && aantal < 5) {
		som += n;
		printf("Geef een getal in: ");
		scanf("%d", &n);
		aantal++;
	}
	if(aantal == 5) { //tellen vanaf 0
		printf("U gaf 5 positieve getallen in\n");
	}
	else {
		printf("U gaf minder dan 5 positieve getallen in\n");
	}

		
	printf("De som van de ingegeven positieve getallen is %d", som);
	return 0;
}
