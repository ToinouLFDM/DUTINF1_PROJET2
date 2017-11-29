#include "polynomes.h"
#include "polynomes.c"
#include "polynomesSIMON.c"


int main(int argc, char const *argv[])
{
	Polynome p;
	initPolynome(&p);
	char *s=" 1X^3 - 1X^1 - 1";
	//char *d="";
	//standardiseDescription(s,d);
	str2Polynome(s,&p);
	affichePolynome(p);
	Monome m;
	m.coeff=2;
	m.degre=2;
	multiplieMonomePolynome(m,&p);
	affichePolynome(p);
	ajouteMonomePolynome(m,&p);
	affichePolynome(p);
	return 0;
}