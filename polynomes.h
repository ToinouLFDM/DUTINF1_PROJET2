/******************************************************************************/
/* POLYNOMES_H                                                                */
/******************************************************************************/

#ifndef POLYNOMES_H
#define POLYNOMES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int quitter();








#endif

