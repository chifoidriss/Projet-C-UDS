#ifndef __PILE__H__
#define __PILE__H__

#include <stdio.h>
#include <stdlib.h>

typedef struct Arbre{
    int val;
    struct Arbre *sag;
    struct Arbre *sad;
    struct Arbre *parent;
}Arbre;

Arbre *newArbre(int x);
void effaceArbre(Arbre *a);
Arbre *joinArbre(Arbre *a,Arbre *b, int noeud);
void affArbre_prefix(Arbre *a);

#endif
