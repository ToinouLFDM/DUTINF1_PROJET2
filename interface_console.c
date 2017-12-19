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
				multiplier_par_monome(M,&A,&B);
				break;
			case 6:
				ajouter_monome_a_polynome(M,&A,&B);
				break;
			case 7:
				ajouter_polynome_a_polynome(&A,&B);
				break;
			case 8:
				multiplier_polynome_par_polynome(&A,&B);
				break;
			case 9:
				puissance_polynome(&A,&B);
				break;
			case 10:
				trier_polynome(&A,&B);
				break;
			case 11:
				reduire_le_polynome(&A,&B);
				break;
			case 12:
				done = quitter();
				break;
		}
		printf("\n");
	}
}
void multiplier_par_monome(Monome M,Polynome *A,Polynome *B)
{
	printf("Quel Polynome voulez vous multiplier par M  (A/B)\n");
	char s =' ';
	char a ='A';
	char b ='B';
	while (s!=a && s!=b)
	{
		scanf("%c",&s);
		if(s!=a && s!=b)
			printf("Tapez A ou B\n");
	}
	if(M.coeff==0)
		printf("ATTENTION votre coeff est nul ! \n");
	if(s==a)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*A);
		printf("\n");
		multiplieMonomePolynome(M,A);
		printf("Le Polynome vaut ->");
		affichePolynome(*A);
	}
	if(s==b)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*B);
		printf("\n");
		multiplieMonomePolynome(M,B);
		printf("Le Polynome vaut ->");
		affichePolynome(*B);
	}
	printf("\n");

}
void ajouter_monome_a_polynome(Monome M,Polynome *A,Polynome *B)
{
	printf("Quel Polynome voulez vous ajouter M  (A/B)\n");
	char s =' ';
	char a ='A';
	char b ='B';
	while (s!=a && s!=b)
	{
		scanf("%c",&s);
		if(s!=a && s!=b)
			printf("Tapez A ou B\n");
	}
	if(M.coeff==0)
		printf("ATTENTION votre coeff est nul ! \n");
	if(s==a)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*A);
		printf("\n");
		ajouteMonomePolynome(M,A);
		printf("Le Polynome vaut ->");
		affichePolynome(*A);
	}
	if(s==b)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*B);
		printf("\n");
		ajouteMonomePolynome(M,B);
		printf("Le Polynome vaut ->");
		affichePolynome(*B);
	}
	printf("\n");
}
void ajouter_polynome_a_polynome(Polynome *A,Polynome *B)
{
	printf("Quel Polynome voulez vous ajouter,l'autre sera modifié (A/B)\n");
	char s =' ';
	char a ='A';
	char b ='B';
	while (s!=a && s!=b)
	{
		scanf("%c",&s);
		if(s!=a && s!=b)
			printf("Tapez A ou B\n");
	}
	if(s==a)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*B);
		printf("\n");
		ajoutePolynomePolynome(B,A);
		printf("Le Polynome vaut ->");
		affichePolynome(*B);
	}
	if(s==b)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*A);
		printf("\n");
		ajoutePolynomePolynome(A,B);
		printf("Le Polynome vaut ->");
		affichePolynome(*A);
	}
	printf("\n");
}
void multiplier_polynome_par_polynome(Polynome *A,Polynome *B)
{
	printf("Quel Polynome voulez vous multiplier,il sera modifié (A/B)\n");
	char s =' ';
	char a ='A';
	char b ='B';
	while (s!=a && s!=b)
	{
		scanf("%c",&s);
		if(s!=a && s!=b)
			printf("Tapez A ou B\n");
	}
	if(s==a)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*A);
		printf("\n");
		//multipliePolynomePolynome(A,B);
		printf("Le Polynome vaut ->");
		affichePolynome(*A);
	}
	if(s==b)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*B);
		printf("\n");
		//multipliePolynomePolynome(B,A);
		printf("Le Polynome vaut ->");
		affichePolynome(*B);
	}
	printf("\n");
}
void puissance_polynome(Polynome *A,Polynome *B)
{
	printf("Quel Polynome voulez vous mettre a une puissance (A/B)\n");
	char s =' ';
	char a ='A';
	char b ='B';
	while (s!=a && s!=b)
	{
		scanf("%c",&s);
		if(s!=a && s!=b)
			printf("Tapez A ou B\n");
	}
	int value;
	printf("Entrez une puissance\n");
	scanf("%d",&value);
	if(s==a)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*A);
		printf("\n");
		//puissancePolynome(A,value);
		printf("Le Polynome vaut ->");
		affichePolynome(*A);
	}
	if(s==b)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*B);
		printf("\n");
		//puissancePolynome(B,value);
		printf("Le Polynome vaut ->");
		affichePolynome(*B);
	}
	printf("\n");
}
void trier_polynome(Polynome *A,Polynome *B)
{
	printf("Quel Polynome voulez vous Trier? (A/B)\n");
	char s =' ';
	char a ='A';
	char b ='B';
	while (s!=a && s!=b)
	{
		scanf("%c",&s);
		if(s!=a && s!=b)
			printf("Tapez A ou B\n");
	}
	if(s==a)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*A);
		printf("\n");
		//triePolynome(A);
		printf("Le Polynome vaut ->");
		affichePolynome(*A);
	}
	if(s==b)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*B);
		printf("\n");
		//triePolynome(B);
		printf("Le Polynome vaut ->");
		affichePolynome(*B);
	}
	printf("\n");
}
void reduire_le_polynome(Polynome *A,Polynome *B)
{
	printf("Quel Polynome voulez vous réduire (A/B)\n");
	char s =' ';
	char a ='A';
	char b ='B';
	while (s!=a && s!=b)
	{
		scanf("%c",&s);
		if(s!=a && s!=b)
			printf("Tapez A ou B\n");
	}
	if(s==a)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*A);
		printf("\n");
		reduitPolynomeTrie(A);
		printf("Le Polynome vaut ->");
		affichePolynome(*A);
	}
	if(s==b)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*B);
		printf("\n");
		reduitPolynomeTrie(B);
		printf("Le Polynome vaut ->");
		affichePolynome(*B);
	}
	printf("\n");
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