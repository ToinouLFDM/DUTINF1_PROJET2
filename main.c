#include "polynomes.h"
#include "polynomes.c"


int main(int argc, char const *argv[])
{
	Polynome p;
	initPolynome(&p);
	char *s=" 1X^3 + 133X^2 - 1X^1 - 1";
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
	ajoutePolynomePolynome(&p,&p);
	affichePolynome(p);
	char *s2=" 1X^3 +3X^3 + 133X^2 - 1X^1 - 2X^1";
	Polynome p2;
	str2Polynome(s2,&p2);
	affichePolynome(p2);
	reduitPolynomeTrie(&p2);
	affichePolynome(p2);
	return 0;
}