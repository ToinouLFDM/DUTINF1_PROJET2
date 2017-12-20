/******************************************************************************/
/* POLYNOMES_H                                                                */
/******************************************************************************/

#ifndef POLYNOMES_H
#define POLYNOMES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define MAXMONOME 50




/******************************************************************************/
/* STRUCTURES                                                                 */
/******************************************************************************/
typedef struct monome {
    int coeff;
    int degre;
    } Monome;

typedef struct polynome {
    Monome      tab_monomes[MAXMONOME];
    int         nb_monomes;
    } Polynome;




/******************************************************************************/
/* PROTOTYPES polynome.c                                                      */
/******************************************************************************/
void initPolynome(Polynome *);
void affichePolynome(Polynome);
void standardiseDescription(char *s, char *d);
void str2Polynome(char *str,Polynome *p);
void multiplieMonomePolynome(Monome m,Polynome *p);
void ajouteMonomePolynome(Monome m,Polynome *p);
void insert_tab(Monome tab[],Monome value,int max_tab,int position);
void ajoutePolynomePolynome(Polynome *p, Polynome *q);
void reduitPolynomeTrie(Polynome *p);
void delete_and_move(Polynome *p,int index );

/******************************************************************************/
/* PROTOTYPES interface_console.c                                             */
/******************************************************************************/
void afficher_Menu();
void Menu();
void rentrer_polynome(Polynome *p);
void rentrer_monome(Monome *M);
void afficher_les_variables(Polynome A, Polynome B, Monome M);
void multiplier_par_monome(Monome M,Polynome *A,Polynome *B);
void ajouter_monome_a_polynome(Monome M,Polynome *A,Polynome *B);
void multiplier_polynome_par_polynome(Polynome *A,Polynome *B);
void ajouter_polynome_a_polynome(Polynome *A,Polynome *B);
void puissance_polynome(Polynome *A,Polynome *B);
void reduire_le_polynome(Polynome *A,Polynome *B);
void trier_polynome(Polynome *A,Polynome *B);
void dessiner_polynome (Polynome A, Polynome B);
int quitter();








#endif

