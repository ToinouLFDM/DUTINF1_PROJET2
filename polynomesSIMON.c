//Ton fichier .c j'ai defa mis le include dans le main
//fais tt tes fct dedans en metrras le tout ensemble
////////////////////////////////////////////////////////////////////////
//  IMPORTANT a chaque fois que tu veux push le projet pull le avant !//
////////////////////////////////////////////////////////////////////////

/******************************************************************************/
/* ajoutePolynomePolynome - ajoute les polynomes fourni                       */
/*                                                                            */
/* INPUT  : deux polynome (pointeur) a ajouter l'un a l'autre                 */
/* OUTPUT : néant pas besoin de return car ce sont des tableaux               */
/******************************************************************************/

void ajoutePolynomePolynome(Polynome *p, Polynome *q)
{

	if (p->nb_monomes > q->nb_monomes)
	{
		int stop=p->nb_monomes; //valeur d'arret
		int i;
		for(i=0;i<=stop;i++) // tant que le compteur est inférieur a la valeur d'arret
		{
			
			ajouteMonomePolynome(q->tab_monomes[i], p); // on ajoute le monome d'indice i du polynome q au polynome p
		}
	}
	else //si le nombre de monome de q est supérieur a celui de p
	{
		int stop=q->nb_monomes; //valeur d'arret
		int i;
		for ( i = 0; i <= stop; ++i) // tant que le compteur est inférieur a la valeur d'arret
		{
			ajouteMonomePolynome(p->tab_monomes[i], q); // on ajoute le monome d'indice i du polynome p au polynome q
		}

	}
}
	
	