void afficher_Menu()
{
	printf("\n");
	printf("Entrez le numéro de l'action souhaité\n");
	printf("\n");
	printf("1.  Attribuer un polynome a la variable A \n");
	printf("2.  Attribuer un polynome a la variable B \n");
	printf("3.  Attribuer un Monome a la variable M\n");
	printf("4.  Afficher le Polynome A et B et le Monome M\n");
	printf("5.  Multiplier Un Polynome avec le Monome M\n");
	printf("6.  Ajouter le Monome M a un Polynome\n");
	printf("7.  Ajouter un Polynome a un Polynome\n");
	printf("8.  multiplier un Polynome a un polynome \n");
	printf("9.  Calcul de puissance d'un Polynome\n");
	printf("10. Trier un Polynome\n");
	printf("11. Reduire Un Polynome\n");
	printf("12. Quittez le programme\n");
}

void Menu()
{
	int done=0;
	Polynome A;
	Polynome B;
	initPolynome(&A);
	initPolynome(&B);
	Monome M={0,0};
	while (!done)
	{
		afficher_Menu();
		int action;
		scanf("%d",&action);
		switch (action)
		{
			case 1:
				rentrer_polynome(&A);
				break;
			case 2:
				rentrer_polynome(&B);
				break;
			case 3:
				rentrer_monome(&M);
				break;
			case 4:
				afficher_les_variables(A,B,M);
				break;
			case 5:
				
				break;
			case 6:
				
				break;
			case 7:
				
				break;
			case 8:
				
				break;
			case 9:
				
				break;
			case 10:
				
				break;
			case 11:
				
				break;
			case 12:
				done = quitter();
				break;
		}
		printf("\n");
	}
}
void rentrer_polynome(Polynome *p)
{
	printf("rentrez le nombre de monome voulu\n");
	scanf("%d",&(p->nb_monomes));
	int i=0;
	for(;i<p->nb_monomes;i++)
	{
		printf("\n");
		printf("rentrez le monome n°%d \n",i+1 );
		rentrer_monome(&(p->tab_monomes[i]));
	}
	printf("\n");
	printf("Le Polynome rentré vaut -> ");
	affichePolynome(*p);
	printf("\n");

}
void rentrer_monome(Monome *M)
{
	int valeur;
	printf("rentrez la valeur du coeff\n");
	scanf("%d",&valeur);
	M->coeff=valeur;
	if(valeur==0)
		printf("ATTENTION votre coeff est nul ! \n");
	printf("rentrez la valeur du degré\n");
	scanf("%d",&valeur);
	M->degre=valeur;
	printf("\n");
}
void afficher_les_variables(Polynome A, Polynome B, Monome M)
{
	if(A.nb_monomes==0)
	{
		printf("La valeur du Polynome A est nulle \n");
		printf("êtes vous sûr de l'avoir rentré?\n");
	}
	else
	{
		printf("Le Polynome A vaut ->");
		affichePolynome(A);
	}
	printf("\n");
	if (B.nb_monomes==0)
	{
		printf("La valeur du Polynome B est nulle \n");
		printf("êtes vous sûr de l'avoir rentré?\n");
	}
	else
	{
		printf("Le Polynome B vaut ->");
		affichePolynome(B);
	}
	printf("\n");
	if(M.coeff==0)
	{
		printf("La valeur du Monome M est nulle \n");
		printf("êtes vous sûr de l'avoir rentré?\n");
	}
	else
	{
		printf("Le Monome M vaut ->");
		printf("%dX^",M.coeff);
		printf("%d\n",M.degre);
	}
	printf("\n");
}
int quitter()
{
	printf("ête vous sûr de vouloir quitter? y/n \n");
	char s =' ';
	int done = 0;
	char y ='y';
	char n ='n';
	while (s!=n && s!=y)
	{
		scanf("%c",&s);
		if (s==y)
			done=1;
		else if(s!=n && s!=y)
			printf("Tapez y ou n\n");

	}
	return done;
}