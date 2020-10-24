#ifndef __PILE__H__
#define __PILE__H__

#include <stdio.h>
#include <stdlib.h>

typedef enum{
    false,
    true
}Bool;

typedef struct PileElt{
    int val;
    struct PileElt *next;
}PileElt, *Pile;

Pile newPile(void);
Bool isEmpty(Pile P);
Pile addPile(Pile P,int x);
Pile removePile(Pile P);
void showPile(Pile P);
int topPile(Pile P);
int lengthPile(P);
Pile clearPile(Pile P);

#endif
