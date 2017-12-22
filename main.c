#include "polynomes.h"
#include "polynomes.c"
#include "interface_console.c"
//#include "polynomesSIMON.c" //


int main(int argc, char const *argv[])
{


	//Menu();
	Polynome p, resultat, test;
	initPolynome(&p);
	initPolynome(&test);
	char *s=" 1X^4 + 1X^2";
	//char *d="";
	//standardiseDescription(s,d);
	str2Polynome(s,&p);
	//affichePolynome(p);
	char *a=" 1X^4 + 1X^2 +1X - 1";
	str2Polynome(a,&test);
	//affichePolynome(test);
	//Monome m;
	//m.coeff=2;
	//m.degre=2;
	//multiplieMonomePolynome(m,&p);
	//affichePolynome(p);
	//ajouteMonomePolynome(m,&p);
	//affichePolynome(p);
	//resultat = ajoutePolynomePolynome2(&p,&test);
	//affichePolynome(resultat);
	//char *s2=" 1X^3 +3X^3 + 133X^2 - 1X^1 - 2X^1";
	//Polynome p2;
	//str2Polynome(s2,&p2);
	//affichePolynome(p2);
	//reduitPolynomeTrie(&resultat);
	//affichePolynome(resultat);
	resultat = multipliePolynomePolynome(&p,&p);
	affichePolynome(resultat);
	 



	return 0;
}