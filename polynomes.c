/******************************************************************************/
/* POLYNOMES_C                                                                */
/******************************************************************************/

//toutes déclarations dans le fichier .h
#include"polynomes.h"

/******************************************************************************/
/* main                                                                       */
/******************************************************************************/


/******************************************************************************/
/* initPolynomes - initialise le polynome fourni                              */
/*                                                                            */
/* INPUT  : polynome (pointeur) à initialiser                                 */
/* OUTPUT : néant                                                             */
/******************************************************************************/
void initPolynome(Polynome *p)
{
    p->nb_monomes = 0;
}

/******************************************************************************/
/* affichePolynome - self explained                                           */
/*                                                                            */
/* INPUT  : polynome à afficher                                               */
/* OUTPUT : néant                                                             */
/******************************************************************************/
void affichePolynome(Polynome p)
{
    int i=0;
    int n = p.nb_monomes;
    while(i<n)
    {

    	int coeff = p.tab_monomes[i].coeff;
        int degre = p.tab_monomes[i].degre;
    	
    	if(coeff!=0 )// n'afficche rien si le coefficent est egal à 0
    	{
            if (coeff>0 && i!=0)// affcihe un '+' devant le monome si le coeff est supérieur à O et si ce n'est pas le premier monome
            {
                printf("+");
            }
    		if ((coeff!=1 && coeff!=-1) || degre ==0 )//affiche le coeff si il est different de 1 et -1 ou si le degrée est egal à 0
    		{
    			printf("%d", coeff);
    		}
            else if (coeff<0)// affiche un '-' si on affiche pas le coeff et que le coeff est negatif
            {
                printf("-" );
            }
    		if (degre!=0 )//affiche X si le degré est différent de 0
    		{
    			printf("X");
    			if(degre!=1)//affiche le degré si il est différent de 0 et 1
    			{
    				printf("*%d",degre);
    			}
    		}
    	}
    	
    	i++;
    }
    printf("\n");
}

/******************************************************************************/
/* standardiseDescription - ajoute des + devant les -, vire les char étranges */
/* et change 'x' en 'X', remplace X par 1X                                    */
/*                                                                            */
/* INPUT : s est la chaîne source (celle qui contient une description         */
/* réduite du polynôme                                                        */
/*         d est la chaîne de destination dans laquelle on ecrit              */
/* une description standardisée                                               */
/* OUPUT : néant                                                              */
/******************************************************************************/
void standardiseDescription(char *s, char *d)
{
    char *l=s, *e=d;
    //l pointeur qui lit la chaîne source
    //e pointeur qui écrit la chaîne destination

    while(*l!='\0')
    {
        if(*l=='-')  //remplacer - par +-
        {
            *e = '+';
            e++;
            *e = '-';
        }
        else
        {
            if(*l=='x' || *l=='X')  // X ou x
            {
                if(*(l-1)<'0' || *(l-1)>'9') // ...non précédé d'un chiffre
                {
                    *e='1';
                    e++;
                    *e='X';
                }
                else
                    *e = 'X';
            }
            // autre cas on recopie
            else if((*l>='0' && *l<='9') || *l=='+' || *l=='^')
                *e = *l;
            else // caractères erronés
            {
                e--; // on recule
                if (*l!=' ') // et on signale (sauf si espace)
                    fprintf(stderr,"Err: caractère '%c' ignoré\n",*l);
            }
        }

        e++;
        l++;
    }
    *e = '\0'; // fin de chaîne
}

/******************************************************************************/
/* str2Polynome - lit un polynome dans une string et charge un Polynome       */
/* format pour écrire les polynômes                                           */
/*     X^3 - X - 1, 1X^3 - 1X^1 - 1 sont acceptés                             */
/*                                                                            */
/* INPUT  : str chaîne de caractères qui décrit le polynôme                   */
/*          p   polynôme dans lequel écrire le résultat                       */
/* OUTPUT : néant                                                             */
/******************************************************************************/
void str2Polynome(char *str,Polynome *p)
{
    char *tok, *ptr;
    int coeff, degre;
    int nb_monomes = 0;


    //on commence par standardiser la description
    //dans une chaîne assez longue pur la contenir
    char *str2 = (char *) malloc(strlen(str)+50);

    //la nouvelle description
    standardiseDescription(str,str2); // Nettoie et normalise

    tok = strtok(str2,"+"); // Récupération d'un "token" grâce au séparateur +

    while(tok!=NULL)
        {
        ptr=strchr(tok,'X'); // Y a-t-il un X dans le token?
        if(ptr) // Oui, il y a un X
            {
            //Y a-t'il un '^nombre' derriere le X
            if(sscanf(tok,"%dX^%d",&coeff,&degre)!=2) // Cas 5X^2
                {
                if(sscanf(tok,"%dX%d",&coeff,&degre) != 2) // Cas 5X2
                    {
                    if((sscanf(tok,"X%d",&degre) == 1) || (sscanf(tok,"X^%d",&degre) == 1)) // Cas X2 ou X^2
                        coeff = 1;
                    else if (sscanf(tok,"%dX",&coeff)==1) // Cas 5X
                        degre = 1;
                    else // ...sinon on considère qu'il s'agit de X
                        {
                        coeff = 1;
                        degre = 1;
                        }
                    }
                }
            }
        else // Pas de X
            {
            sscanf(tok,"%d",&coeff);
            degre = 0;
            }
        p->tab_monomes[nb_monomes].coeff = coeff;
        p->tab_monomes[nb_monomes].degre = degre;
        nb_monomes++;

        tok = strtok(NULL,"+");
    }

    p->nb_monomes = nb_monomes;
    free(str2);
}

/******************************************************************************/
/*  multiplieMonomePolynome- multiple le polynome par un monome               */
/*                                                                            */
/* INPUT  : un monome que l'on multiplie a un polynome                        */
/* OUTPUT : néant car le polynome est un pointeur                             */
/******************************************************************************/
void multiplieMonomePolynome(Monome m,Polynome *p)
{
    if (p->nb_monomes==0)//si le nb de monomes est null ne fait rien
    {
        return;
    }
    int i=0, n=p->nb_monomes;
    for(;i<n;i++)//multiplie chaque coeff du polynome avec le coeff du monome 
    {            //et ajoute le degre du monome a chaque degre du polynome
        p->tab_monomes[i].coeff*=m.coeff;
        p->tab_monomes[i].degre+=m.degre;
    }
}

/******************************************************************************/
/*  ajouteMonomePolynome- ajoute un monome a un polynome                      */
/*                                                                            */
/* INPUT  : un monome que l'on aditionne a un polynome                        */
/* OUTPUT : néant car le polynome est un pointeur                             */
/******************************************************************************/
void ajouteMonomePolynome(Monome m,Polynome *p)
{
    if (p->nb_monomes==0)//si le nb de monome est null , on l'augmente de 1 
    {                    //et on ajoute le monome dans le tableau de monome a la case 0
        p->nb_monomes=1;
        p->tab_monomes[0]=m;
        return;
    }
    int i=0, n=p->nb_monomes;
    while (i<n && p->tab_monomes[i].degre>m.degre )//tant que le degre monome du polynome a l'indice i est superieur au degre du monome on incrémente i
    {
        
        i++;
    }
    if(p->tab_monomes[i].degre==m.degre)//si le degre monome a du polynome a l'indice i est egal eu degre du monome 
    {                                   
        p->tab_monomes[i].coeff+=m.coeff;//on ajoute le coeff du monome au coeff du monome  al'indice i du polynome
    }
    else//sinon on insert a l'indice i le monome dans le tableau de monome du polynome
    {
        p->nb_monomes+=1;
        insert_tab(p->tab_monomes,m,n+1,i);
        
    }
}


//fonction pour inserer un monome a 'indce i' d'un tableau de monome
void insert_tab(Monome tab[],Monome value,int max_tab,int position)
{
    int i=position;
    Monome tmp;
    Monome new_tmp;
    tmp.degre=value.degre;
    tmp.coeff=value.coeff;
    while (i<max_tab )
    {
        new_tmp.degre=tmp.degre;
        new_tmp.coeff=tmp.coeff;
        tmp.degre=tab[i].degre;
        tmp.coeff=tab[i].coeff;
        tab[i].degre=new_tmp.degre;
        tab[i].coeff=new_tmp.coeff;

        i++;
    }
}
/******************************************************************************/
/* ajoutePolynomePolynome - ajoute les polynomes fourni                       */
/*                                                                            */
/* INPUT  : deux polynome (pointeur) a ajouter l'un a l'autre                 */
/* OUTPUT : néant pas besoin de return car ce sont des tableaux               */
/******************************************************************************/

void ajoutePolynomePolynome(Polynome *p, Polynome *q)
{
    int i;
    for(i=0;i<q->nb_monomes;i++) // tant que le compteur est inférieur a la valeur d'arret
    {       
        ajouteMonomePolynome(q->tab_monomes[i], p); // on ajoute le monome d'indice i du polynome q au polynome p
    }
}


/******************************************************************************/
/* reduitPolynomeTrie - reduit le polynome trie fourmi                        */
/*                                                                            */
/* INPUT  : un polynome (pointeur) reduit pqr lq suite                        */
/* OUTPUT : néant pas besoin de return car ce polynome modifie est un poimteur*/
/******************************************************************************/
void reduitPolynomeTrie(Polynome *p)
{
    int i=0; //initialise le compteur a zero
    int n=p->nb_monomes-1;//imitialize le maximum d'iteratiom au mobre de monome-! 
    for(;i<n;i++)//pour chaque monome dams le polynome
    {
        if(p->tab_monomes[i].degre==p->tab_monomes[i+1].degre)//verifie si le degre est identique a celui du monomes suivant
        {
            p->tab_monomes[i].coeff+=p->tab_monomes[i+1].coeff;//ajoute le coeff du monone suivant au monome actuel
            delete_and_move(p,i+1);//enleve le monmome suivant et decale tout les monomes du tableau
            n-=1;
            
        }
    }

}
//fonction aui enleve le monmome suivant et decale tout les monomes du tableau
void delete_and_move(Polynome *p,int index )
{
    p->nb_monomes-=1;
    int n=p->nb_monomes;
    for (;index<n;index++)
    {
        p->tab_monomes[index].coeff=p->tab_monomes[index+1].coeff;
        p->tab_monomes[index].degre=p->tab_monomes[index+1].degre;

    }
    p->tab_monomes[index].degre=NULL;
    p->tab_monomes[index].coeff=NULL;
}


