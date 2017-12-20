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

Polynome ajoutePolynomePolynome2(Polynome *p, Polynome *q)
{   
    int i = 0;
    int e = 0;
    int f = 0;

    Polynome resultat;
    initPolynome(&resultat);
    Monome monome_etape;

    while  (i<p->nb_monomes || e<q->nb_monomes)
    {
        if(i<p->nb_monomes && e<q->nb_monomes)
        {
            if (q->tab_monomes[e].degre < p->tab_monomes[e].degre)
            {   
                resultat.nb_monomes ++;
                printf("marche1\n");
                resultat.tab_monomes[f] = q->tab_monomes[e];
                e ++;        
            }
           if(p->tab_monomes[i].degre < q->tab_monomes[e].degre)
            { 
                resultat.nb_monomes ++;
                printf("marche2\n");
                resultat.tab_monomes[f] = p->tab_monomes[i];
                i++;
               
                
            }                
            if (p->tab_monomes[i].degre == q->tab_monomes[e].degre)
           {
                printf("marche3\n");
                resultat.nb_monomes ++;
                monome_etape.coeff = p->tab_monomes[i].coeff + q->tab_monomes[e].coeff;
                monome_etape.degre = p->tab_monomes[i].degre;
                resultat.tab_monomes[f] = monome_etape;
                
                i++;
                e++;
                
                
            }
            f++;

        }      
        if (i == p->nb_monomes && e < q->nb_monomes)
        {
            resultat.nb_monomes ++;
            printf("marche4\n");
            resultat.tab_monomes[f] = q->tab_monomes[e];
            e++;
            f++;
            
          
        }
        if(e == q->nb_monomes && i < p->nb_monomes)
        {
            resultat.nb_monomes ++;
            printf("marche5\n");
            resultat.tab_monomes[f] = p->tab_monomes[i];
            i++;
            f++;
            
           
        }
    }
    return resultat;
}
//void ajoutePolynomePolynome2(Polynome *p, polynome q)
//{
//int compteur
//Pokynome somme
//initPolynome(somme)
//somme = *poly1
//somme.nb_monomes = poly1 -> nb_monomes + poly.nb_monomes;
//for(curseur = poly1->nb_monome; curseur < somme.nb_monome; curseur ++)
    //some.tab_monomes[curseur ] = p.tab_monome[cureseur - q->nb_monome];
 //*poly1 = somme;
//}



Polynome multipliePolynomePolynome(Polynome *p, Polynome *q)
{
    printf("salut\n");
    Polynome resultat;
    Polynome tampon;
    initPolynome(&resultat);

    int i;
    for ( i = 0; i < q->nb_monomes && resultat.nb_monomes<= 50 ; i++) // tant que le compteur est inférieur a la valeur d'arret
    {
        printf("%d\n", i );
        resultat.nb_monomes += q->nb_monomes;
        multiplieMonomePolynome(p->tab_monomes[i], q);  
        ajoutePolynomePolynome2(&resultat, q);
       
    }
 return resultat;
affichePolynome(resultat);
}