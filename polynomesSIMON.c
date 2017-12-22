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

void ajoutePolynomePolynome(Polynome *p, Polynome *q) //complexité (n+m)^2
{
	int i;
	for(i=0;i<=q->nb_monomes;i++) // tant que le compteur est inférieur a la valeur d'arret
	{		
		ajouteMonomePolynome(q->tab_monomes[i], p); // on ajoute le monome d'indice i du polynome q au polynome p
	}
}

/******************************************************************************/
/* ajoutePolynomePolynome2 - ajoute les polynomes fourni                      */
/*                                                                            */
/* INPUT  : deux polynome (pointeur) a ajouter l'un a l'autre                 */
/* OUTPUT : renvoi un polynome résultat                                       */
/******************************************************************************/

Polynome ajoutePolynomePolynome2(Polynome *p, Polynome *q) //complexité n+m marche nikel 
{   
    int i = 0;
    int e = 0;
    int f = 0;
    Polynome resultat;
    Monome monome_etape;
    initPolynome(&resultat);

    while  (i<p->nb_monomes || e<q->nb_monomes)
    {
        if(i<p->nb_monomes && e<q->nb_monomes)
        {
            if (q->tab_monomes[e].degre < p->tab_monomes[i].degre)
            {                  
                printf("%d\n", q->tab_monomes[i].degre);  
                resultat.tab_monomes[f] = p->tab_monomes[i];
                i ++;
                f++;
                resultat.nb_monomes ++;
            }
            else if(p->tab_monomes[i].degre < q->tab_monomes[e].degre)
            { 
                printf("%d\n", p->tab_monomes[i].degre);  
                resultat.tab_monomes[f] = q->tab_monomes[e];
                e++;
                f++;
                resultat.nb_monomes ++;                
            }                
            else if (p->tab_monomes[i].degre == q->tab_monomes[e].degre)
           {
                printf("%d\n", p->tab_monomes[i].degre);
                monome_etape.coeff = p->tab_monomes[i].coeff + q->tab_monomes[e].coeff;
                monome_etape.degre = p->tab_monomes[i].degre;
                resultat.tab_monomes[f] = monome_etape;
                i++;
                e++;                
                f++;
                resultat.nb_monomes ++;
            }
        }      
        else if (i == p->nb_monomes && e < q->nb_monomes)
        {
            printf("%d\n", q->tab_monomes[i].degre);  
            resultat.tab_monomes[f] = q->tab_monomes[e];
            e++;
            f++;
            resultat.nb_monomes ++;          
        }
        else if(e == q->nb_monomes && i < p->nb_monomes)
        {
            printf("%d\n", p->tab_monomes[i].degre); 
            resultat.tab_monomes[f] = p->tab_monomes[i];
            i++;
            f++;
            resultat.nb_monomes ++;           
        }
    }
    return resultat;
}

Polynome multipliePolynomePolynome(Polynome *p, Polynome *q)
{
    Polynome resultat;
    Polynome tampon;
    initPolynome(&resultat);
    resultat.nb_monomes = p->nb_monomes;

    int i;
    for ( i = 0; i < q->nb_monomes && resultat.nb_monomes<= 50 ; i++) // tant que le compteur est inférieur a la valeur d'arret
    {
        printf("%d\n", i );
        resultat.tab_monomes[i].coeff=0;
        multiplieMonomePolynome(p->tab_monomes[i], q);  
        ajoutePolynomePolynome2(&resultat, q);
        
       
    }
return resultat;