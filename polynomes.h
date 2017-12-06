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
/* PROTOTYPES                                                                 */
/******************************************************************************/
void initPolynome(Polynome *);
void affichePolynome(Polynome);
void standardiseDescription(char *s, char *d);
void str2Polynome(char *str,Polynome *p);
void multiplieMonomePolynome(Monome m,Polynome *p);
void ajouteMonomePolynome(Monome m,Polynome *p);
void insert_tab(Monome tab[],Monome value,int max_tab,int position);
void ajoutePolynomePolynome(Polynome *p, Polynome *q);













#endif

