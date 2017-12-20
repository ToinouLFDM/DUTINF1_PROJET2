#include "polynomes.h"
#include "polynomes.c"
#include "interface_console.c"


int main(int argc, char const *argv[])
{

	Polynome p, resultat;
	initPolynome(&p);
	char *s=" 1X^3 + 133X^2 - 1X^1 - 1";
	//char *d="";
	//standardiseDescription(s,d);
	str2Polynome(s,&p);
	affichePolynome(p);
	//Monome m;
	//m.coeff=2;
	//m.degre=2;
	//multiplieMonomePolynome(m,&p);
	//affichePolynome(p);
	//ajouteMonomePolynome(m,&p);
	//affichePolynome(p);
	//resultat = ajoutePolynomePolynome2(&p,&p);
	//affichePolynome(resultat);
	//char *s2=" 1X^3 +3X^3 + 133X^2 - 1X^1 - 2X^1";
	//Polynome p2;
	//str2Polynome(s2,&p2);
	//affichePolynome(p2);
	//reduitPolynomeTrie(&p2);
	//affichePolynome(p2);
	multipliePolynomePolynome(&p,&p);


	return 0;
}