#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef char ELEMENT;

typedef struct {
    int sommet;
    ELEMENT tab[MAX];
}PILE_TAB;

int est_vide(PILE_TAB* pile);
int est_pleine(PILE_TAB* pile);
void init_pile(PILE_TAB* pile);
int empiler(PILE_TAB* pile, ELEMENT nouveau);
int depile(PILE_TAB* pile);
