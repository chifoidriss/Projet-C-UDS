#include <stdio.h>
#include <stdlib.h>

#ifndef __PILE__H__
#define __PILE__H__

typedef enum{
    false,
    true
}Bool;

typedef struct monome{
    double c;
    int d;
}monome;

typedef struct Polynome{
    monome m;
    struct Polynome *next;
}PolynomeElt, *Polynome;

monome newMono(int d,double c);
Polynome newPoly(void);
Bool videPoly(Polynome P);
void affMono(monome m);
void affPoly(Polynome P);
Polynome ajoutPoly(Polynome P, monome mn);
Polynome retirePoly(Polynome P);
monome sommetPoly(Polynome P);
int longPoly(Polynome P);
Polynome somPoly(Polynome P,Polynome Q);
Polynome diffPoly(Polynome P,Polynome Q);
Polynome effacePoly(Polynome P);

#endif
