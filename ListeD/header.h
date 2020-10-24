#ifndef __PILE__H__
#define __PILE__H__

#include <stdio.h>
#include <stdlib.h>

typedef enum{
    false,
    true
}Bool;

// Défintion du maillon de la liste
typedef struct DListeNode{
    int val;
    struct DListeNode *prev;
    struct DListeNode *next;
}DListeNode;

//Définition d'une liste doublement chaînée
typedef struct Dliste{
    int taille;
    DListeNode *deb;
    DListeNode *fin;
}*Dliste;

// Prototypes des fonctions
Dliste newDliste(void);
Bool videDliste(Dliste l);
int longDliste(Dliste l);
int premierEltDliste(Dliste l);
int dernierEltDliste(Dliste l);
void affDliste(Dliste l);
Dliste ajoutFinDliste(Dliste l, int x);
Dliste ajoutDebutDliste(Dliste l, int x);
Dliste retraitFinDliste(Dliste l);
Dliste retraitDebutDliste(Dliste l);
Dliste effacerDliste(Dliste l);

#endif
