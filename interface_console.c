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
	printf("8.  Ajouter un Polynome a un Polynome 2eme version\n");
	printf("9.  Multiplier un Polynome a un polynome \n");
	printf("10. Calcul de puissance d'un Polynome\n");
	printf("11. Trier un Polynome\n");
	printf("12. Reduire Un Polynome\n");
	printf("13. Dessiner un Polynome\n");
	printf("14. Quittez le programme\n");
}

void Menu()
{
	int done=0;
	Polynome A;
	Polynome B;
	initPolynome(&A);
	initPolynome(&B);
	Monome M={0,0};
	int compteur;
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
				ajouter_polynome_a_polynome2(&A,&B);
				break;
			case 9:
				multiplier_polynome_par_polynome(&A,&B);
				break;
			case 10:
				puissance_polynome(&A,&B);
				break;
			case 11:
				trier_polynome(&A,&B);
				break;
			case 12:
				reduire_le_polynome(&A,&B);
				break;
			case 13:
				dessiner_polynome(A,B, &compteur);
				break;
			case 14:
				done = quitter();
				break;
			default:
				printf("Rentrez une valeur entre 1 et 13\n");
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
		ajoutePolynomePolynome(A,B);
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
void ajouter_polynome_a_polynome2(Polynome *A,Polynome *B)
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
		*B=ajoutePolynomePolynome2(B,A);
		printf("Le Polynome vaut ->");
		affichePolynome(*B);
	}
	if(s==b)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*A);
		printf("\n");
		*A=ajoutePolynomePolynome2(A,B);
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
		*A=multipliePolynomePolynome(A,B,0);
		printf("Le Polynome vaut ->");
		affichePolynome(*A);
	}
	if(s==b)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*B);
		printf("\n");
		*B=multipliePolynomePolynome(A,B,0);
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
		*A=puissancePolynome(A,value);
		printf("Le Polynome vaut ->");
		affichePolynome(*A);
	}
	if(s==b)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*B);
		printf("\n");
		*B=puissancePolynome(B,value);
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
		triPolynome(A);
		printf("Le Polynome vaut ->");
		affichePolynome(*A);
	}
	if(s==b)
	{
		printf("Le Polynome valait ->");
		affichePolynome(*B);
		printf("\n");
		triPolynome(B);
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
	while (p->nb_monomes<=0 || p->nb_monomes>50)
	{
		scanf("%d",&(p->nb_monomes));
		if(p->nb_monomes<=0 || p->nb_monomes>50)
			printf("votre nombre doit etre compris ente 1 et 50 inclus\n");
	}
	
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
float puissance(float x,int n )
{
	int i=1;
	int res=0;
	if(n>=1)
	{
	res=x;
		for(;i<n;i++)
		{
			res*=x;
		}
	}
	return res;	
}/*
void dessiner_polynome(Polynome p)
{
	int value;
	printf("donner une valeur pour l'echelle \n");
	scanf("%d",value);
	int i=0;
	for(;i<10;i++)
	{
		float tab[10]={0};
		j=0;;
		n=p.nb_monomes;
		for(;j<n;j++)
			tab[10]+=(float)p.tab_monomes[j].coeff*(puissance(i*value,p.tab_monomes[j].degre));
	}
	for(i=0;i<40;i++)
	{
		for(j=0;j<40;j++)
		{

		}
	}
}*/
/* Image parameters */
#define W 320
#define H 320
#define M 255
 
/* This is where we'll store the pixels */
uint8_t r[H+1][W], g[H+1][W], b[H+1][W];
 void create_abs_ord ()
 {
 	for ( int x=0; x<W; x++ )
 	{
		int y= H/2;
		r[y][x] = 255, g[y][x] = 255, b[y][x] = 255;
	}
	for( int y=0; y<W; y++ )
	{
		int x= W/2;
		r[y][x] = 255, g[y][x] = 255, b[y][x] = 255;
	}
 }
/* Draw a full 2*pi period of the sine */
void create_image ( Polynome p )
{
	float scale;
	if(p.tab_monomes[0].degre==1)
		scale=1;
	else
		scale=W*puissance((p.tab_monomes[0].degre-1),(p.tab_monomes[0].degre-1));

	for ( int x=W/2; x>=0; x-- )
	{
		int n=p.nb_monomes;
		int j=0;
		int y=0;
		for(;j<n;j++)
			y+=(H/2)-(p.tab_monomes[j].coeff*puissance(x-W/2,p.tab_monomes[j].degre))/scale;
		if(y>H || y<0)
        	y=H;
        r[y][x] = 255, g[y][x] = 255, b[y][x] = 0;
	}
    /* Run the width of the image */
    for ( int x=W/2; x<W; x++ )
    {
        /* Scale the wave to the image height */
        /*int n=p.nb_monomes;
        int j=0; à 
        int y=0;
        for(;j<n;j++)
        {
        	if(y+ H/2 + (H/2) * p.tab_monomes[j].coeff*puissance(x,p.tab_monomes[j].degre)< H)
        		y +=H/2 + (H/2) * p.tab_monomes[j].coeff*puissance(x,p.tab_monomes[j].degre);
        }*/
        int n=p.nb_monomes;
		int j=0;
		int y=0;
		for(;j<n;j++)
			y+=(H/2)-(p.tab_monomes[j].coeff*puissance(x-W/2,p.tab_monomes[j].degre))/scale;
        if(y>H || y<0)
        	y=H;
        r[y][x] = 255, g[y][x] = 255, b[y][x] = 0;
    }
}
 
/* Write the ppm-formatted file */
void write_ppm ( const char *filename )
{
    FILE *out = fopen ( filename, "w" );
    /* Header:
     * Magic number, width, height, maxvalue
     */
    fprintf ( out, "P6 %d %d %d\n", W, H, M );
    /* Rows. 2-byte values if max > 255, 1-byte otherwise.
     * These loops explicitly show where every single byte
     * goes; in practice, it would be faster and shorter to
     * interleave the arrays and write bigger blocks of
     * contiguous data.
     */
    for ( size_t i=0; i<H; i++ )
        for ( size_t j=0; j<W; j++ )
        {
            fwrite ( &r[i][j], sizeof(uint8_t), 1, out ); /* Red */
            fwrite ( &g[i][j], sizeof(uint8_t), 1, out ); /* Green */
            fwrite ( &b[i][j], sizeof(uint8_t), 1, out ); /* Blue */
        }
    fclose ( out );
}
void effacer()
{
	for ( int x=0; x<W; x++ )
 	{
 		for( int y=0; y<W; y++ )
		{
		r[y][x] = 0, g[y][x] = 0, b[y][x] = 0;
		}
	}
	
}		
/* Make the picture, store it, and go home */
void dessiner_polynome (Polynome A,Polynome B,int *compteur)
{
	*compteur+=1;
	printf("Quel Polynome voulez vous dessiner? (A/B)\n");
	char s =' ';
	char a ='A';
	char b ='B';
	char filename[30];
	sprintf(filename,"fonction_%d.ppm",*compteur);
	while (s!=a && s!=b)
	{
		scanf("%c",&s);
		if(s!=a && s!=b)
			printf("Tapez A ou B\n");
	}
	if(s==a)
	{
		create_abs_ord();
		write_ppm ( filename );
		printf("Le Polynome A a été dessiné!\n");
		printf("Pour le voir ouvrrez l'image %s",filename);
		create_image(A);
    	write_ppm ( filename );
	}
	if(s==b)
	{	create_abs_ord();
		write_ppm ( filename);
		printf("Le Polynome B a été dessiné!\n");
		printf("Pour le voir ouvrrez l'image %s",filename);
		create_image(B);
    	write_ppm ( filename );
	}
	effacer();
	printf("\n");
    
}