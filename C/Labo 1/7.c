/* oef 7 */

#include <stdio.h>
#include <math.h>

int main() {
	//this just doesn't work
	/*double i = 2;
	double n = 8.2;
	double oplossing = n;
	double teller = -1;
	double noemer = 1;
	double term = n;
	for(; i < 100; i+=2) {
		noemer *= (i*(i-1));
		term *= (n * n);
		teller = -teller;
		oplossing += (teller/noemer) * term;
		printf("%f\n", oplossing);
	}
	//printf("\n%f, %f, %f, %f\n", oplossing, teller, noemer, term);
	printf("\n%f", oplossing);
	*/
	
	//number getting to big to fast --> better method needed
//	int i = 1;
//	double x = 8.2; //nummer om opdracht op uit te voeren
//	double oplossing = x;
//	int teller = 1;
//	long int noemer = 1;
//	double term = x;
//	double t_oplossing;
//	for(i = 3; i < 20; i+=2) {
//		teller = -teller;
//		noemer = noemer * i * (i-1);
//		printf("noemer: %d\n", noemer);
//		term = term * x * x;
//		t_oplossing = ((double)(teller)/(noemer))*(double)term;
//		printf("term/noemer: %f\n\n", t_oplossing);
//		oplossing += t_oplossing;
//		//printf("%de term: %f\tteller: %d\tnoemer: %d\tterm: %d\tOplossing: %f\n", (i/3), t_oplossing, teller, noemer, term, oplossing);
//	}
//	printf("\nOplossing reeksontwikkeling: %f\n", oplossing);
//	printf("Oplossing math.h %f\n", sin(x));
//	return 0;
	
	int i;
	double x = 8.2;
	double last = x;
	double oplossing = x;
	double nu = 0;
	double nieuw = 0;
	int teken = 1;
	double blijven_doen = 1;
	double laatste_oplossing = 0;
	for(i = 3; blijven_doen != 0.0; i+=2) {
		printf("last: %f\t nieuw:%f\tnu: %f\n", last, nieuw, nu);
		nieuw = (x*x)/(i*(i-1));
		nu = last*nieuw;
		teken = -teken;
		oplossing += teken*nu;
		printf("verschil: %f\n", oplossing - laatste_oplossing);
		blijven_doen = oplossing - laatste_oplossing;
		last = nu;
		laatste_oplossing = oplossing;
	}
	
	printf("\nOplossing reeksontwikkeling: %f\n", oplossing);
	printf("Oplossing math.h %f\n", sin(x));
	return 0;
}
