//Ton fichier .c j'ai defa mis le include dans le main
//fais tt tes fct dedans en metrras le tout ensemble
////////////////////////////////////////////////////////////////////////
//  IMPORTANT a chaque fois que tu veux push le projet pull le avant !//
////////////////////////////////////////////////////////////////////////



void ajoutePolynomePolynome(Polynome *p, Polynome *q)
{

	if (p->nb_monomes > q->nb_monomes)
	{
		int stop=p->nb_monomes;
		int i;
		for(i=0;i<=stop;i++)
		{
			
			ajouteMonomePolynome(q->tab_monomes[i], p);
		}
	}
	else
	{
		int stop=q->nb_monomes;
		int i;
		for ( i = 0; i <= stop; ++i)
		{
			ajouteMonomePolynome(p->tab_monomes[i], q);
		}

	}
}
	
	