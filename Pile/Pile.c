#include "header.h"

Pile newPile(void){
    return NULL;
}

Bool isEmpty(Pile P){
    if(P == NULL)
        return true;
    return false;
}

Pile addPile(Pile P,int x){
    PileElt *elt;
    elt = malloc(sizeof(*elt));
    if(elt == NULL){
        fprintf(stderr,"Problème allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }
    elt->val = x;
    elt->next = P;
    return elt;
}

Pile removePile(Pile P){
    PileElt *elt;
    if(isEmpty(P))
        return newPile();
    elt = P->next;
    free(P);
    return elt;
}

void showPile(Pile P){
/*    if(isEmpty(P)){
        printf("La pile est vide.\n");
        return;
    }
    while(!isEmpty(P)){
        printf("[%d]\n",P->val);
        P = P->next;
    }
*/
    if(isEmpty(P)){
        printf("\n");
        return;
    }
    printf("[%d]",P->val);
    showPile(P->next);
}

int topPile(Pile P){
    if(isEmpty(P)){
        printf("Aucun élément à afficher.\n");
        return -1;
    }
    return P->val;
}

int lengthPile(Pile P){
    int i=0;
    while(!isEmpty(P)){
        i++;
        P = P->next;
    }
    return i;
}

Pile clearPile(Pile P){
    PileElt *elt;
    if(isEmpty(P))
        return newPile();
    elt = P->next;
    free(P);
    return clearPile(elt);
    /* version simplifiée
        while(!isEmpty(P))
            P = removePile(P);
        return newPile();
    */
}

int main(void)
{
    printf("Bienvenue dans la gestion des PILES.\n");

    Pile p = newPile();
    p = addPile(p,2);
    p = addPile(p,1);
    p = addPile(p,9);
    p = addPile(p,7);
    p = addPile(p,4);

    if(isEmpty(p))
        printf("Je suis vide!\n");
    else
        printf("Je suis chargee!.\nDe longueur: %d\n",lengthPile(p));

    showPile(p);

    return 0;
}
